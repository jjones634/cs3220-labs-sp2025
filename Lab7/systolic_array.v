module systolic_array #(
    parameter IN_WIDTH          = 8,
    parameter IN_FRAC           = 0,
    parameter OUT_WIDTH         = 8,
    parameter OUT_FRAC          = 0,
    parameter MULT_LAT          = 3,                 // Multiplication latency
    parameter ACC_LAT           = 1,                 // Addition latency (<=1, not support pipelined acc)
    parameter ROWS              = 4,                 // Row number of systolic array
    parameter K                 = 4,
    parameter COLS              = 4                  // Column number of systolic array
)(
    input                       clk,
    input                       rst,
    input                       en,
    input                       flush,               // If 1, flush the pipeline
    input                       rst_accumulator_rdy, // If 1, reset accumulator in array
    input                       stream_out_rdy,      // If 1, stream acc result out
    input [IN_WIDTH*ROWS-1:0]   row_data_in,         // AXIS row_data_in
    input                       row_data_in_vld,
    output                      row_data_in_rdy,
    input [IN_WIDTH*COLS-1:0]   col_data_in,         // AXIS col_data_in
    input                       col_data_in_vld,
    output                      col_data_in_rdy,
    output [OUT_WIDTH*ROWS-1:0] row_data_out,        // AXIS row_data_out
    output                      row_data_out_vld,
    input                       row_data_out_rdy
);
    //TODO: Signal declarations
    // register inputs // something todo with verilator timing issue
    reg       rst;
    reg       rst_accumulator_rdy;
    reg       stream_out_rdy;
    reg [IN_WIDTH*ROWS-1:0] row_data_in;
    reg [IN_WIDTH*COLS-1:0] col_data_in;

    always @(posedge clk) begin
        rst <= rst_in;
        rst_accumulator_rdy <= rst_accumulator_rdy_in;
        stream_out_rdy <= stream_out_rdy_in_in;
        row_data_in <= row_data_in_in;
        col_data_in <= col_data_in_in;
    end


    // rst_accumulator wires 
    wire            rst_accumulator_in  [0:ROWS][0:COLS];
    wire            rst_accumulator_out [0:ROWS][0:COLS];
    wire [COLS-1:0] control_rst_accumulator_rdy;

    // stream_out_rdy wires
    wire            stream_out_rdy_in   [0:ROWS][0:COLS];
    wire            stream_out_rdy_out  [0:ROWS][0:COLS];
    wire [COLS-1:0] control_stream_out_rdy;

    // row data for macs [column number][row number]
    // data starts from first column and propogates through columns
    // cannot use COLS-1 or ROWS-1 as for multiples of 4, will wrap around and overrite first value
    wire [IN_WIDTH-1:0] mac_row_data_in  [0:COLS][0:ROWS];
    wire [IN_WIDTH-1:0] mac_row_data_out [0:COLS][0:ROWS];

    // column data for macs [row number][column number]
    // data starts from first row and propogates through rows
    // cannot use COLS-1 or ROWS-1 as for multiples of 4, will wrap around and overrite first value
    wire [IN_WIDTH-1:0] mac_col_data_in  [0:ROWS][0:COLS];
    wire [IN_WIDTH-1:0] mac_col_data_out [0:ROWS][0:COLS];

    // wires for bypass data [row number][column number]
    // only needed between rows and columns, last one not used
    // cannot use COLS-1 or ROWS-1 as for multiples of 4, will wrap around and overrite first value
    wire  [IN_WIDTH-1:0] bypass_data_in      [0:ROWS][0:COLS];
    wire [OUT_WIDTH-1:0] bypass_data_out     [0:ROWS][0:COLS];


    // wires receiving bypass data
    wire [OUT_WIDTH*ROWS-1:0] row_data_out_tmp;
    


    //TODO: MAC units instantiation
    // - Image you are drawing a spatial diagram of the MAC units; how should you connect the wires of them?
    // - Use generate block to realize the spatial diagram (You are not required to use generate block though)

    assign row_data_out = row_data_out_tmp;

    
    generate
        genvar row, col;
        
        // assign row/column data
        for (row = 0; row < ROWS; row = row + 1) begin: assign_row_data_in
            for (col = 0; col < COLS; col = col + 1) begin: assign_col_data_in
                if (row == 0) begin
                    assign mac_col_data_in[0][col]     = col_data_in[IN_WIDTH*col +: IN_WIDTH];
                    assign rst_accumulator_in[0][col]  = control_rst_accumulator_rdy[col];
                    assign stream_out_rdy_in[0][col]   = control_stream_out_rdy[col];
                end else begin
                    assign mac_col_data_in[row][col]     = mac_col_data_out[row-1][col];
                    assign rst_accumulator_in[row][col]  = rst_accumulator_out[row-1][col];
                    assign stream_out_rdy_in[row][col]   = stream_out_rdy_out[row-1][col];
                end
                if (col == 0) begin
                    assign mac_row_data_in[0][row] =  row_data_in[IN_WIDTH*row +: IN_WIDTH];
                end else begin
                    assign mac_row_data_in[col][row] = mac_row_data_out[col-1][row];
                end
                assign bypass_data_in[row][col]     = bypass_data_out[row][col+1];
            end
        end

        // instantiate MAC array
        for (row = 0; row < ROWS; row = row + 1) begin: instantiate_mac_rows
            for (col = 0; col < COLS; col = col + 1) begin: instantiate_mac_cols
                mac #(
                    .IN_WIDTH(IN_WIDTH),
                    .IN_FRAC(IN_FRAC),
                    .OUT_WIDTH(OUT_WIDTH),
                    .OUT_FRAC(OUT_FRAC),
                    .MULT_LAT(MULT_LAT),
                    .ADD_LAT(ACC_LAT),
                    .K(COLS - col - 1),
                    .COLS(COLS),
                    .ROWS(ROWS),
                    .COLS_IDX(col),
                    .ROWS_IDX(row)
                ) mac (
                    .clk(clk),
                    .rst(rst),
                    .rst_accumulator_in(rst_accumulator_in[row][col]),
                    .stream_out_rdy_in(stream_out_rdy_in[row][col]),
                    .row_data_in(mac_row_data_in[col][row]),
                    .col_data_in(mac_col_data_in[row][col]),
                    .bypass_data_in(bypass_data_in[row][col]),
                    .rst_accumulator_out(rst_accumulator_out[row][col]),
                    .stream_out_rdy_out(stream_out_rdy_out[row][col]),
                    .row_data_out(mac_row_data_out[col][row]),
                    .col_data_out(mac_col_data_out[row][col]),
                    .psum_out(bypass_data_out[row][col])
                );
            end
        end

        for (row = 0; row < ROWS; row = row + 1) begin: data_out
            assign row_data_out_tmp[OUT_WIDTH*row +: OUT_WIDTH] = bypass_data_out[row][0];
        end
    endgenerate

    

    //TODO: Ctrl unit instantiation
    // generate rst accmulator and bypass enable control signals
    ctrl #(
        .IN_WIDTH(IN_WIDTH),
        .OUT_WIDTH(OUT_WIDTH),
        .ROWS(ROWS),
        .COLS(COLS),
        .MULT_LAT(MULT_LAT),
        .ACC_LAT(ACC_LAT)
    ) ctrl_0(
        .clk(clk),
        .rst(rst),
        .input_rst_accumulator(rst_accumulator_rdy),
        .input_stream_out_rdy(stream_out_rdy),
        .rst_accumulator(control_rst_accumulator_rdy),
        .stream_out_rdy(control_stream_out_rdy)
    );

endmodule
