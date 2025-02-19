 `include "define.vh" 


module FE_STAGE(
  input wire clk,
  input wire reset,
  input wire [`from_DE_to_FE_WIDTH-1:0] from_DE_to_FE,
  input wire [`from_AGEX_to_FE_WIDTH-1:0] from_AGEX_to_FE,   
  input wire [`from_MEM_to_FE_WIDTH-1:0] from_MEM_to_FE,   
  input wire [`from_WB_to_FE_WIDTH-1:0] from_WB_to_FE, 
  output wire [`FE_latch_WIDTH-1:0] FE_latch_out
);

  `UNUSED_VAR (from_MEM_to_FE)
  `UNUSED_VAR (from_WB_to_FE)

  // I-MEM
  (* ram_init_file = `IDMEMINITFILE *)
  reg [`DBITS-1:0] imem [`IMEMWORDS-1:0];
 
  initial begin
      $readmemh(`IDMEMINITFILE , imem);
  end

  // Display memory contents with verilator 
  /*
  always @(posedge clk) begin
    for (integer i=0 ; i<`IMEMWORDS ; i=i+1) begin
        $display("%h", imem[i]);
    end
  end
  */

  /* pipeline latch */ 
  reg [`FE_latch_WIDTH-1:0] FE_latch;  // FE latch 
  wire valid_FE;
   
  `UNUSED_VAR(valid_FE)
  reg [`DBITS-1:0] PC_FE_latch; // PC latch in the FE stage   // you could use a part of FE_latch as a PC latch as well 
  
  reg [`DBITS-1:0] inst_count_FE; /* for debugging purpose */ 
  
  wire [`DBITS-1:0] inst_count_AGEX; /* for debugging purpose. resent the instruction counter */ 

  wire [`INSTBITS-1:0] inst_FE;  // instruction value in the FE stage 
  wire [`DBITS-1:0] pcplus_FE;  // pc plus value in the FE stage 
  wire stall_pipe_FE; // signal to indicate when a front-end needs to be stall
  
  wire [`FE_latch_WIDTH-1:0] FE_latch_contents;  // the signals that will be FE latch contents 
  
  // reading instruction from imem 
  assign inst_FE = imem[PC_FE_latch[`IMEMADDRBITS-1:`IMEMWORDBITS]];  // this code works. imem is stored 4B together 
  
  // wire to send the FE latch contents to the DE stage 
  assign FE_latch_out = FE_latch; 
 

  // This is the value of "incremented PC", computed in the FE stage
  assign pcplus_FE = PC_FE_latch + `INSTSIZE;
  
   
   // the order of latch contents should be matched in the decode stage when we extract the contents. 
  assign FE_latch_contents = {
                                valid_FE, 
                                inst_FE, 
                                PC_FE_latch, 
                                pcplus_FE, // please feel free to add more signals such as valid bits etc. 
                                inst_count_FE,
                                 // if you add more bits here, please increase the width of latch in VX_define.vh 
                                next_PC
                                };




  // **TODO: Complete the rest of the pipeline 
  //assign stall_pipe_FE = 1;   // you need
  wire br_mispred_AGEX;  
  wire [`DBITS-1:0] br_target_AGEX;

  // branch preditor logic
  reg [7:0] BHR;

  // Branch Target Buffer (BTB) - 16 entries
  reg [15:0] BTB_valid;

  //stuff new stuff from agex
  wire [`DBITS-1:0]PC_AGEX;
  wire is_br_AGEX;
  wire is_jmp_AGEX;
  reg br_cond_AGEX;

  // init PHT and BTB
  initial begin
    integer i;
    BHR = 8'b0;
    for (i = 0; i < 256; i = i + 1) begin
      PHT[i] = 2'b01; // weakly not taken
    end
    BTB_valid = 16'b0;
    for (i = 0; i < 16; i = i + 1) begin
      BTB_tag[i] = 26'b0;
      BTB_target[i] = `DBITS'b0;
    end
  end

  // PHT index and BTB index
  wire [7:0] PHT_index = PC_FE_latch[9:2] ^ BHR; 
  wire [3:0] BTB_index = PC_FE_latch[5:2];
  wire [25:0] BTB_tag_value = PC_FE_latch[31:6]; 

  // BTB hit and PHT prediction
  wire BTB_hit = BTB_valid[BTB_index] && (BTB_tag[BTB_index] == BTB_tag_value);
  wire [1:0] PHT_counter = PHT[PHT_index];
  wire PHT_prediction = PHT_counter[1]; // MSB of the counter

  // Next PC based on BTB and PHT
  wire [`DBITS-1:0] next_PC = (BTB_hit && PHT_prediction) ? BTB_target[BTB_index] : pcplus_FE;
  //assign next_PC = (BTB_hit && PHT_prediction) ? BTB_target[BTB_index] : pcplus_FE;

  // Update BTB, PHT, and BHR
always @ (posedge clk) begin
  if (reset) begin
    // Reset logic for BTB, PHT, and BHR
    integer i;
    for (i = 0; i < 16; i = i + 1) begin
      BTB_valid[i] <= 1'b0;
      BTB_tag[i] <= 26'b0;
      BTB_target[i] <= `DBITS'b0;
    end
    for (i = 0; i < 256; i = i + 1) begin
      PHT[i] = 2'b01; // weakly not taken
    end
    BHR <= 8'b0;
  end else if (is_br_AGEX || is_jmp_AGEX) begin
    // Update BTB
    BTB_valid[PC_AGEX[5:2]] <= 1'b1;
    BTB_tag[PC_AGEX[5:2]] <= PC_AGEX[31:6];
    BTB_target[PC_AGEX[5:2]] <= br_target_AGEX;

    // Update PHT (old)
    // if (br_cond_AGEX) begin
    //   if (PHT[PC_AGEX[9:2] ^ BHR] < 2'b11) begin
    //     PHT[PC_AGEX[9:2] ^ BHR] <= PHT[PC_AGEX[9:2] ^ BHR] + 1;
    //   end
    // end else begin
    //   if (PHT[PC_AGEX[9:2] ^ BHR] > 2'b00) begin
    //     PHT[PC_AGEX[9:2] ^ BHR] <= PHT[PC_AGEX[9:2] ^ BHR] - 1;
    //   end
    // end

    // Update PHT (new)
    if (br_mispred_AGEX && !is_jmp_AGEX && (PHT[PC_AGEX[9:2] ^ BHR] > 2'b00)) begin
      PHT[PC_AGEX[9:2] ^ BHR] <= PHT[PC_AGEX[9:2] ^ BHR] - 1;
    end
    else if ((!br_mispred_AGEX && !is_jmp_AGEX) && (PHT[PC_AGEX[9:2] ^ BHR] < 2'b11)) begin
      PHT[PC_AGEX[9:2] ^ BHR] <= PHT[PC_AGEX[9:2] ^ BHR] + 1;
    end
    else if (is_jmp_AGEX && (PHT[PC_AGEX[9:2] ^ BHR] < 2'b11)) begin
      PHT[PC_AGEX[9:2] ^ BHR] <= 2'b11;
    end

    // Update BHR
    BHR <= {BHR[6:0], br_cond_AGEX};
  end
end
  

  assign {
    stall_pipe_FE
  } = from_DE_to_FE[0]; 

  assign {
    br_mispred_AGEX,
    br_target_AGEX,
    PC_AGEX, //added for execution use
    is_br_AGEX,
    is_jmp_AGEX,
    br_cond_AGEX
  } = from_AGEX_to_FE;

  always @ (posedge clk) begin
  /* you need to extend this always block */
   if (reset) begin 
      PC_FE_latch <= `STARTPC;
      inst_count_FE <= 1;  /* inst_count starts from 1 for easy human reading. 1st fetch instructions can have 1 */ 
      //BHR <= 8'b0; //possibly not here
      end 
    else if (br_mispred_AGEX)
      PC_FE_latch <= br_target_AGEX;
      //BHR <= 8'b0; //possibly not here
    else if (stall_pipe_FE) 
      PC_FE_latch <= PC_FE_latch; 
    else begin 
      PC_FE_latch <= next_PC; // use the next PC based on BTB and PHT
      inst_count_FE <= inst_count_FE + 1;
      //BHR <= {BHR[6:0], PHT_prediction}; //possibly dont update BHR here
      end 
  end
  

  always @ (posedge clk) begin
    if (reset) begin 
      FE_latch <= '0; 
    end else begin 
      if (br_mispred_AGEX)
        FE_latch <= '0;
      else if (stall_pipe_FE)
        FE_latch <= FE_latch; 
      else 
        FE_latch <= FE_latch_contents; 
    end  
  end

endmodule
