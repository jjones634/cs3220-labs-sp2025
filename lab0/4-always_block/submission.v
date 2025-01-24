`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps

// dummy implementation, please replace with your own
module sequential_circuits ( 
    input wire clk,    // Clocks are used in sequential circuits
    input wire d,
    output reg q );//



    always@(posedge clk) begin
        q <= d;
    end

endmodule