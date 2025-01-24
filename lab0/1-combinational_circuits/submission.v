`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps

// dummy implementation, please replace with your own
module combinational_circuits ( 
    input p1a, p1b, p1c, p1d, p1e, p1f,
    output p1y,
    input p2a, p2b, p2c, p2d,
    output p2y );

    //intermediate signals
    wire and_out1, and_out2, and_out3, and_out4;
    wire or_out1, or_out2;

    //AND gates
    assign and_out1 = p2a & p2b;
    assign and_out2 = p2c & p2d;
    assign and_out3 = p1a & p1b & p1c;
    assign and_out4 = p1d & p1e & p1f;

    //OR gates
    assign or_out1 = and_out1 | and_out2;
    assign or_out2 = and_out3 | and_out4;


    assign p1y = or_out2;
    assign p2y = or_out1;

endmodule