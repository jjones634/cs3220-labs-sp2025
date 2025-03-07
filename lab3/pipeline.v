 `include "define.vh" 

module pipeline (
  input wire clk,
  input wire reset
);
  
  reg [`DBITS-1:0] cycle_count; /* for debugging purpose */ 

  /* wires to connect between pipeline stages */ 
  
  wire [`FE_latch_WIDTH-1:0] FE_latch_out; 
  wire [`DE_latch_WIDTH-1:0] DE_latch_out; 
  wire [`AGEX_latch_WIDTH-1:0] AGEX_latch_out; 
  wire [`MEM_latch_WIDTH-1:0] MEM_latch_out;

  wire [`from_DE_to_FE_WIDTH-1:0] from_DE_to_FE;
  wire [`from_AGEX_to_FE_WIDTH-1:0] from_AGEX_to_FE;
  wire [`from_MEM_to_FE_WIDTH-1:0] from_MEM_to_FE;
  wire [`from_WB_to_FE_WIDTH-1:0] from_WB_to_FE;

  wire [`from_AGEX_to_DE_WIDTH-1:0] from_AGEX_to_DE;
  wire [`from_MEM_to_DE_WIDTH-1:0] from_MEM_to_DE;
  wire [`from_WB_to_DE_WIDTH-1:0] from_WB_to_DE;

  wire [`from_MEM_to_AGEX_WIDTH-1:0] from_MEM_to_AGEX;
  wire [`from_WB_to_AGEX_WIDTH-1:0] from_WB_to_AGEX;

  wire [`from_WB_to_MEM_WIDTH-1:0] from_WB_to_MEM; 

  wire [`from_DE_to_FU_WIDTH-1:0] from_DE_to_FU;
  wire [`from_FU_to_DE_WIDTH-1:0] from_FU_to_DE;
  //TODO: part2/bonus modify as necessary
  wire stall_value;

  FE_STAGE my_FE_stage(
    .clk(clk), 
    .reset(reset), 
    .from_DE_to_FE(from_DE_to_FE),
    .from_AGEX_to_FE(from_AGEX_to_FE),
    .from_MEM_to_FE(from_MEM_to_FE),
    .from_WB_to_FE(from_WB_to_FE),
    .FE_latch_out(FE_latch_out)
  ); 

//TODO: part2/bonus modify as necessary
  DE_STAGE my_DE_stage(
    .clk(clk),
    .reset(reset),
    .from_FE_latch(FE_latch_out),
    .from_AGEX_to_DE(from_AGEX_to_DE),  
    .from_MEM_to_DE(from_MEM_to_DE),     
    .from_WB_to_DE(from_WB_to_DE), 
    .from_DE_to_FE(from_DE_to_FE),
    .from_FU_to_DE(from_FU_to_DE),
    .from_DE_to_FU(from_DE_to_FU), 
    .DE_latch_out(DE_latch_out),
    .stall_value(stall_value)
  );

  AGEX_STAGE my_AGEX_stage(
    .clk(clk),
    .reset(reset),
    .from_MEM_to_AGEX(from_MEM_to_AGEX),    
    .from_WB_to_AGEX(from_WB_to_AGEX),   
    .from_DE_latch(DE_latch_out),
    .AGEX_latch_out(AGEX_latch_out),
    .from_AGEX_to_FE(from_AGEX_to_FE),
    .from_AGEX_to_DE(from_AGEX_to_DE),
    .stall_value(stall_value)
  );

  MEM_STAGE my_MEM_stage(
    .clk(clk),
    .reset(reset),
    .from_WB_to_MEM(from_WB_to_MEM),  
    .from_AGEX_latch(AGEX_latch_out),
    .MEM_latch_out(MEM_latch_out),
    .from_MEM_to_FE(from_MEM_to_FE),
    .from_MEM_to_DE(from_MEM_to_DE),
    .from_MEM_to_AGEX(from_MEM_to_AGEX),
    .stall_value(stall_value)
  );     

//TODO: part2/bonus modify as necessary
  WB_STAGE my_WB_stage(
    .clk(clk),
    .reset(reset),  
    .from_MEM_latch(MEM_latch_out),
    .from_WB_to_FE(from_WB_to_FE),
    .from_WB_to_DE(from_WB_to_DE),  
    .from_WB_to_AGEX(from_WB_to_AGEX),
    .from_WB_to_MEM(from_WB_to_MEM),
    .stall_value(stall_value)
  );

  FU_STAGE my_FU_stage(
    .clk(clk),
    .reset(reset),
    .from_DE_to_FU(from_DE_to_FU),
    .from_FU_to_DE(from_FU_to_DE)
  );

  always @ (posedge clk) begin
    if (reset) begin
      cycle_count <= 0; 
    end else begin
      cycle_count <= cycle_count + 1;    
    end
  end

endmodule









