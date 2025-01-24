`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps

// dummy implementation, please replace with your own

module module_hierarchy ( 
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    
    add16 low_bits (
        .a(a[15:0]),
        .b(b[15:0]),
        .cin(0),          
        .sum(sum[15:0]),
        .cout()
    );

    
    add16 high_bits (
        .a(a[31:16]),
        .b(b[31:16]),
        .cin(cout),        
        .sum(sum[31:16]),
        .cout()
    );

endmodule

module add1 ( input a, input b, input cin,   output sum, output cout );

    assign sum = (a ^ b) ^ cin;
    assign cout = (a & b) | (cin & (a ^ b));

endmodule