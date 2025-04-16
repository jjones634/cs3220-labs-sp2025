module mac #(
    parameter IN_WIDTH = 8,
    parameter IN_FRAC = 0,
    parameter OUT_WIDTH = 8,
    parameter OUT_FRAC = 0,
    parameter MULT_LAT = 3,
    parameter ADD_LAT = 1,
    parameter K = 1,
    parameter ROWS = 1,
    parameter COLS = 1,
    parameter COLS_IDX = 1,
    parameter ROWS_IDX = 1
)(
    input                      clk,
    input                      rst,
    input                      rst_accumulator_in,
    input                      stream_out_rdy_in,
    input       [IN_WIDTH-1:0] row_data_in,
    input       [IN_WIDTH-1:0] col_data_in,
    input       [IN_WIDTH-1:0] bypass_data_in, 
    output reg  [IN_WIDTH-1:0] row_data_out,
    output reg  [IN_WIDTH-1:0] col_data_out,
    output reg                 rst_accumulator_out,
    output reg                 stream_out_rdy_out,
    output reg [OUT_WIDTH-1:0] psum_out
);


    //TODO: Signal declarations
    reg [OUT_WIDTH-1:0] accumulator;
    reg [OUT_WIDTH-1:0] mult_result;

    //delay stuff?
    // reg [OUT_WIDTH-1:0] delayed_accumulator;
    // reg [OUT_WIDTH-1:0] delayed_bypass;
    // integer delay_counter; 
    


    //TODO: multiplier instantiation



    //TODO: adder instantiation



    //TODO: signal propagation and synchronization
    //Major approaches to look out for:
    // 1. rst_accumulator and stream_out_rdy are major control signals that dictates the flow of the data and when to reset the accumulator between different matrix multiplications
    // 2. An important part of the following design is to figure out how the data from multipliers and adders should be paired with the above two control signals
    // 3. Mainly you need to know: should I pass the results of this very own MAC's accumulator to the next MAC's accumulator or should I pass the results of the previous MAC's accumulator to this MAC's accumulator and when to do so
    // 4. Also, when should be the exact time point to reset the accumulator so my current results will not be cleared by mistake and the next matrix multiplication can start cleanly.
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            accumulator <= 0;
            psum_out <= 0;
            row_data_out <= 0;
            col_data_out <= 0;
            rst_accumulator_out <= 0;
            stream_out_rdy_out <= 0;
            //delay stuff
            // delayed_accumulator <= 0;
            // delayed_bypass <= 0;
            // delay_counter <= 0;
        end else begin
            if (rst_accumulator_in) begin
                accumulator <= 0;
            end else begin
                mult_result <= row_data_in * col_data_in;
                accumulator <= accumulator + mult_result; 
            end

            //delay based
            // if (delay_counter < (K - 1 + MULT_LAT + ADD_LAT)) begin
            //     delay_counter <= delay_counter + 1;
            //     delayed_accumulator <= accumulator;
            //     delayed_bypass <= bypass_data_in;
            // end else begin
            //     if (stream_out_rdy_in) begin
            //         psum_out <= delayed_bypass;
            //     end else begin
            //         psum_out <= delayed_accumulator;
            //     end
            // end

            if (stream_out_rdy_in) begin
                psum_out <= bypass_data_in;
            end else begin
                psum_out <= accumulator;
            end

            row_data_out <= row_data_in;
            col_data_out <= col_data_in;

            rst_accumulator_out <= rst_accumulator_in;
            stream_out_rdy_out <= stream_out_rdy_in;

        end
    end

endmodule
