module ctrl #(
    parameter IN_WIDTH = 8,
    parameter OUT_WIDTH = 16,
    parameter ROWS = 4,
    parameter COLS = 4,
    parameter MULT_LAT = 1,
    parameter ACC_LAT = 1
)(
    input clk,
    input rst,
    input input_rst_accumulator,
    input input_stream_out_rdy,
    output reg [COLS-1:0] rst_accumulator,
    output reg [COLS-1:0] stream_out_rdy
);

    //TODO: Signal declarations
    // reg [COLS-1:0] rst_accumulator_reg;
    // reg [COLS-1:0] stream_out_rdy_reg;

    // assign rst_accumulator = rst_accumulator_reg;
    // assign stream_out_rdy = stream_out_rdy_reg;



    // //TODO: Rst and stream out rdy signal propagation and synchronization logic among different MAC units
    // always @(posedge clk or posedge rst) begin
    //     if (rst) begin
    //         rst_accumulator_reg <= {COLS{1'b0}};
    //         stream_out_rdy_reg <= {COLS{1'b0}};
    //     end else begin
    //         rst_accumulator_reg <= {COLS{input_rst_accumulator}};
    //         stream_out_rdy_reg <= {COLS{input_stream_out_rdy}};
    //     end
    // end

    integer i;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            rst_accumulator <= {COLS{1'b0}};
            stream_out_rdy <= {COLS{1'b0}};
        end else begin
            // Propagate rst_accumulator signal sequentially across columns
            for (i = 0; i < COLS; i = i + 1) begin
                if (i == 0) begin
                    rst_accumulator[i] <= input_rst_accumulator;
                end else begin
                    rst_accumulator[i] <= rst_accumulator[i-1];
                end
            end

            // Propagate stream_out_rdy signal sequentially across columns
            for (i = 0; i < COLS; i = i + 1) begin
                if (i == 0) begin
                    stream_out_rdy[i] <= input_stream_out_rdy;
                end else begin
                    stream_out_rdy[i] <= stream_out_rdy[i-1];
                end
            end
        end
    end



endmodule