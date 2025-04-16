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
    input                       rst_in,
    input                       rst_accumulator_rdy_in, // If 1, reset accumulator in array
    input                       stream_out_rdy_in_in,      // If 1, stream acc result out

    input [IN_WIDTH*ROWS-1:0]   row_data_in_in,         
    input [IN_WIDTH*COLS-1:0]   col_data_in_in,         
    output [OUT_WIDTH*ROWS-1:0] row_data_out
);
    //TODO: Signal declarations
    // register inputs // something todo with verilator timing issue
    reg       rst;
    reg       rst_accumulator_rdy;
    reg       stream_out_rdy;
    reg [IN_WIDTH*ROWS-1:0] row_data_in;
    reg [IN_WIDTH*COLS-1:0] col_data_in;

    // always @(posedge clk or posedge rst_in) begin
    //     if (rst_in) begin
    //         rst <= 1;
    //         rst_accumulator_rdy <= 0;
    //         stream_out_rdy <= 0;
    //         row_data_in <= 0;
    //         col_data_in <= 0;
    //     end else begin
    //         rst <= 0;
    //         rst_accumulator_rdy <= rst_accumulator_rdy_in;
    //         stream_out_rdy <= stream_out_rdy_in_in;
    //         row_data_in <= row_data_in_in;
    //         col_data_in <= col_data_in_in;
    //     end
    // end



    // //TODO: MAC units instantiation
    // // - Image you are drawing a spatial diagram of the MAC units; how should you connect the wires of them?
    // // - Use generate block to realize the spatial diagram (You are not required to use generate block though)

    // wire [OUT_WIDTH-1:0] psum[ROWS-1:0][COLS-1:0];
    // wire [IN_WIDTH-1:0] row_data[ROWS-1:0][COLS-1:0];
    // wire [IN_WIDTH-1:0] col_data[ROWS-1:0][COLS-1:0];

    // wire rst_accumulator_mac[ROWS-1:0][COLS-1:0];
    // wire stream_out_rdy_mac[ROWS-1:0][COLS-1:0];

    // wire [COLS-1:0] ctrl_rst_accumulator;
    // wire [COLS-1:0] ctrl_stream_out_rdy;

    // //TODO: Ctrl unit instantiation
    // // generate rst accmulator and bypass enable control signals
    // ctrl #(
    //     .IN_WIDTH(IN_WIDTH),
    //     .OUT_WIDTH(OUT_WIDTH),
    //     .ROWS(ROWS),
    //     .COLS(COLS),
    //     .MULT_LAT(MULT_LAT),
    //     .ACC_LAT(ACC_LAT)
    // ) ctrl_unit (
    //     .clk(clk),
    //     .rst(rst),
    //     .input_rst_accumulator(rst_accumulator_rdy),
    //     .input_stream_out_rdy(stream_out_rdy),
    //     .rst_accumulator(ctrl_rst_accumulator), //something?
    //     .stream_out_rdy(ctrl_stream_out_rdy) //something?
    // );


    // generate
    //     genvar i, j;
    //     for (i = 0; i < ROWS; i = i + 1) begin : ROW
    //         for (j = 0; j < COLS; j = j + 1) begin : COL
    //             mac #(
    //                 .IN_WIDTH(IN_WIDTH),
    //                 .IN_FRAC(IN_FRAC),
    //                 .OUT_WIDTH(OUT_WIDTH),
    //                 .OUT_FRAC(OUT_FRAC),
    //                 .MULT_LAT(MULT_LAT),
    //                 .ADD_LAT(ACC_LAT),
    //                 .K(K),
    //                 .ROWS(ROWS),
    //                 .COLS(COLS),
    //                 .ROWS_IDX(i),
    //                 .COLS_IDX(j)
    //             ) mac_unit (
    //                 .clk(clk),
    //                 .rst(rst),
    //                 .rst_accumulator_in((j == 0) ? ctrl_rst_accumulator[j] : rst_accumulator_mac[i][j-1]),
    //                 .stream_out_rdy_in((j == COLS-1) ? ctrl_stream_out_rdy[j] : stream_out_rdy_mac[i][j-1]),
    //                 .row_data_in((j == 0) ? row_data_in[IN_WIDTH*(i+1)-1:IN_WIDTH*i] : row_data[i][j-1]),
    //                 .col_data_in((i == 0) ? col_data_in[IN_WIDTH*(j+1)-1:IN_WIDTH*j] : col_data[i-1][j]),
    //                 .bypass_data_in((j == 0) ? 0 : psum[i][j-1]),
    //                 .row_data_out(row_data[i][j]),
    //                 .col_data_out(col_data[i][j]),
    //                 .rst_accumulator_out(rst_accumulator_mac[i][j]),
    //                 .stream_out_rdy_out(stream_out_rdy_mac[i][j]),
    //                 .psum_out(psum[i][j])
    //             );
    //         end
    //     end
    // endgenerate

    // //old stuff
    // Internal signals for the systolic array
    wire [IN_WIDTH-1:0] row_data_outs[1:0][1:0];
    wire [IN_WIDTH-1:0] col_data_outs[1:0][1:0];
    wire rst_accumulator_outs[1:0][1:0];
    wire stream_out_rdy_outs[1:0][1:0];
    wire [OUT_WIDTH-1:0] psum_outs[1:0][1:0];

    // Generate block for MAC instantiation
    genvar i, j;
    generate
        for (i = 0; i < 2; i = i + 1) begin : ROW
            for (j = 0; j < 2; j = j + 1) begin : COL
                mac #(
                    .IN_WIDTH(IN_WIDTH),
                    .IN_FRAC(IN_FRAC),
                    .OUT_WIDTH(OUT_WIDTH),
                    .OUT_FRAC(OUT_FRAC),
                    .MULT_LAT(MULT_LAT),
                    .ADD_LAT(ACC_LAT),
                    .K(2),
                    .ROWS(2),
                    .COLS(2),
                    .ROWS_IDX(i),
                    .COLS_IDX(j)
                ) mac_unit (
                    .clk(clk),
                    .rst(rst_in),
                    .rst_accumulator_in((j == 0) ? rst_accumulator_rdy_in : rst_accumulator_outs[i][j-1]),
                    .stream_out_rdy_in((j == 0) ? stream_out_rdy_in_in : stream_out_rdy_outs[i][j-1]),
                    .row_data_in((j == 0) ? row_data_in_in[IN_WIDTH*(i+1)-1:IN_WIDTH*i] : row_data_outs[i][j-1]),
                    .col_data_in((i == 0) ? col_data_in_in[IN_WIDTH*(j+1)-1:IN_WIDTH*j] : col_data_outs[i-1][j]),
                    .bypass_data_in((j == 0) ? 0 : psum_outs[i][j-1]),
                    .row_data_out(row_data_outs[i][j]),
                    .col_data_out(col_data_outs[i][j]),
                    .rst_accumulator_out(rst_accumulator_outs[i][j]),
                    .stream_out_rdy_out(stream_out_rdy_outs[i][j]),
                    .psum_out(psum_outs[i][j])
                );
            end
        end
    endgenerate

    // Assign final outputs
    generate
        for (i = 0; i < 2; i = i + 1) begin : OUTPUT_ASSIGN
            assign row_data_out[OUT_WIDTH*(i+1)-1:OUT_WIDTH*i] = psum_outs[i][1];
        end
    endgenerate
    // //old stuff

    // generate
    //     for (i = 0; i < ROWS; i = i + 1) begin : OUTPUT_ASSIGN
    //         assign row_data_out[OUT_WIDTH*(i+1)-1:OUT_WIDTH*i] = psum[i][COLS-1];
    //     end
    // endgenerate
    

endmodule
