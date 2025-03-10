`include "define.vh" 

module AGEX_STAGE(
  input wire clk,
  input wire reset,
  input wire [`from_MEM_to_AGEX_WIDTH-1:0] from_MEM_to_AGEX,    
  input wire [`from_WB_to_AGEX_WIDTH-1:0] from_WB_to_AGEX,   
  input wire [`DE_latch_WIDTH-1:0] from_DE_latch,
  input wire [`FE_latch_WIDTH-1:0] from_FE_latch, //added for next_PC
  output wire [`AGEX_latch_WIDTH-1:0] AGEX_latch_out,
  output wire [`from_AGEX_to_FE_WIDTH-1:0] from_AGEX_to_FE,
  output wire [`from_AGEX_to_DE_WIDTH-1:0] from_AGEX_to_DE
);

  `UNUSED_VAR (from_MEM_to_AGEX)
  `UNUSED_VAR (from_WB_to_AGEX)

  reg [`AGEX_latch_WIDTH-1:0] AGEX_latch; 
  // wire to send the AGEX latch contents to other pipeline stages 
  assign AGEX_latch_out = AGEX_latch;
  
  wire[`AGEX_latch_WIDTH-1:0] AGEX_latch_contents; 
  
  wire valid_AGEX; 
  wire [`INSTBITS-1:0]inst_AGEX; 
  wire [`DBITS-1:0]PC_AGEX;
  wire [`DBITS-1:0] inst_count_AGEX; 
  wire [`DBITS-1:0] pcplus_AGEX; 
  wire [`IOPBITS-1:0] op_I_AGEX;
  reg br_cond_AGEX; // 1 means a branch condition is satisified. 0 means a branch condition is not satisifed
 
  /////////////////////////////////////////////////////////////////////////////
  // TODO: Complete remaining code logic here!

  wire is_br_AGEX;
  wire is_jmp_AGEX;
  wire rd_mem_AGEX;
  wire wr_mem_AGEX;
  wire wr_reg_AGEX;
  wire [`REGNOBITS-1:0] wregno_AGEX;

  wire [`DBITS-1:0] regval1_AGEX;
  wire [`DBITS-1:0] regval2_AGEX;
  wire [`DBITS-1:0] sxt_imm_AGEX;

  reg [`DBITS-1:0] aluout_AGEX;
  reg [`DBITS-1:0] memaddr_AGEX;
  reg [`DBITS-1:0] br_target_AGEX;
  reg br_mispred_AGEX; //changed from wire to reg, amybe revert

  reg [31:0] correct_predictions;
  reg [31:0] total_branches;

  //stuff from FE latch, only next_pc matters
  wire valid_FE;
  `UNUSED_VAR(valid_FE)
  wire [`INSTBITS-1:0] inst_FE;
  `UNUSED_VAR(inst_FE)
  reg [`DBITS-1:0] PC_FE_latch;
  `UNUSED_VAR(PC_FE_latch)
  wire [`DBITS-1:0] pcplus_FE;
  `UNUSED_VAR(pcplus_FE)
  wire [`DBITS-1:0] inst_count_FE;
  `UNUSED_VAR(inst_count_FE)
  wire [`DBITS-1:0] next_PC;

  // Initialize counters
  always @ (posedge clk) begin
    if (reset) begin
      correct_predictions <= 32'b0;
      total_branches <= 32'b0;
    end else if (is_br_AGEX || is_jmp_AGEX) begin
      total_branches <= total_branches + 1;
      if (!br_mispred_AGEX) begin
        correct_predictions <= correct_predictions + 1;
      end
    end
  end

  
  // Calculate branch condition
  // TODO: complete the code
  always @ (*) begin
    case (op_I_AGEX)
    `BEQ_I : br_cond_AGEX = (regval1_AGEX == regval2_AGEX);
    `BNE_I : br_cond_AGEX = (regval1_AGEX != regval2_AGEX);
    `BLT_I : br_cond_AGEX = ($signed(regval1_AGEX) < $signed(regval2_AGEX));
    `BGE_I : br_cond_AGEX = ($signed(regval1_AGEX) >= $signed(regval2_AGEX));
    `BLTU_I: br_cond_AGEX = (regval1_AGEX < regval2_AGEX);
    `BGEU_I: br_cond_AGEX = (regval1_AGEX >= regval2_AGEX);
    //add jump cases
    `JAL_I : br_cond_AGEX = 1'b1; // unconditional jump
    `JALR_I: br_cond_AGEX = 1'b1; // unconditional jump
    `JR_I  : br_cond_AGEX = 1'b1; // unconditional jump
    default: br_cond_AGEX = 1'b0;
    endcase
  end

  // Compute ALU operations  (alu out or memory addresses)
  // TODO: complete the code
  always @ (*) begin
    case (op_I_AGEX)
    `ADD_I:   aluout_AGEX = regval1_AGEX + regval2_AGEX; 
    `SUB_I:   aluout_AGEX = regval1_AGEX - regval2_AGEX; 
    `AND_I:   aluout_AGEX = regval1_AGEX & regval2_AGEX; 
    `OR_I:    aluout_AGEX = regval1_AGEX | regval2_AGEX; 
    `XOR_I:   aluout_AGEX = regval1_AGEX ^ regval2_AGEX; 
    `SLT_I:   aluout_AGEX = ($signed(regval1_AGEX) < $signed(regval2_AGEX)) ? 1 : 0; 
    `SLTU_I:  aluout_AGEX = (regval1_AGEX < regval2_AGEX) ? 1 : 0;
    `SRA_I:   aluout_AGEX = $signed(regval1_AGEX) >>> $signed(regval2_AGEX[4:0]); 
    `SRL_I:   aluout_AGEX = regval1_AGEX >> regval2_AGEX[4:0]; 
    `SLL_I:   aluout_AGEX = regval1_AGEX << regval2_AGEX[4:0]; 
    `MUL_I:   aluout_AGEX = $signed(regval1_AGEX) * $signed(regval2_AGEX);
    `ADDI_I:  aluout_AGEX = regval1_AGEX + sxt_imm_AGEX; 
    `ANDI_I:  aluout_AGEX = regval1_AGEX & sxt_imm_AGEX; 
    `ORI_I:   aluout_AGEX = regval1_AGEX | sxt_imm_AGEX; 
    `XORI_I:  aluout_AGEX = regval1_AGEX ^ sxt_imm_AGEX;
    `SLTI_I:  aluout_AGEX = ($signed(regval1_AGEX) < $signed(sxt_imm_AGEX)) ? 1 : 0; 
    `SLTIU_I: aluout_AGEX = (regval1_AGEX < sxt_imm_AGEX) ? 1 : 0;
    `SRAI_I:  aluout_AGEX = $signed(regval1_AGEX) >>> $signed(sxt_imm_AGEX[4:0]); 
    `SRLI_I:  aluout_AGEX = regval1_AGEX >> sxt_imm_AGEX[4:0];
    `SLLI_I:  aluout_AGEX = regval1_AGEX << sxt_imm_AGEX[4:0];
    `LUI_I:   aluout_AGEX = sxt_imm_AGEX; 
    `AUIPC_I: aluout_AGEX = PC_AGEX + sxt_imm_AGEX;
    `JAL_I,
    `JALR_I:  aluout_AGEX = pcplus_AGEX;
    `LW_I:    memaddr_AGEX = regval1_AGEX + sxt_imm_AGEX;
    `SW_I: begin 
      memaddr_AGEX = regval1_AGEX + sxt_imm_AGEX;
      aluout_AGEX = regval2_AGEX; 
    end
    default: begin 
      aluout_AGEX  = '0;
      memaddr_AGEX = '0;		  
    end
    endcase
  end 

  // branch target needs to be computed here 
  // computed branch target needs to send to other pipeline stages (br_target_AGEX)
  // TODO: complete the code
  always @(*)begin
    if (op_I_AGEX == `JAL_I) 
      br_target_AGEX  = PC_AGEX + sxt_imm_AGEX;
    else if (op_I_AGEX == `JR_I)
      br_target_AGEX = regval1_AGEX; 
    else if (op_I_AGEX == `JALR_I)
      br_target_AGEX = (regval1_AGEX + sxt_imm_AGEX) & 32'hfffffffe; 
    else if (is_br_AGEX && br_cond_AGEX) 
      br_target_AGEX = PC_AGEX + sxt_imm_AGEX; 
    else 
      br_target_AGEX = pcplus_AGEX;        
  end

  // assign br_mispred_AGEX = ((is_br_AGEX || is_jmp_AGEX) 
  //                        && (br_target_AGEX != pcplus_AGEX)) ? 1 : 0;
  
  assign br_mispred_AGEX = ( (is_br_AGEX || is_jmp_AGEX) && (br_target_AGEX != next_PC))? 1:0; //new condition

// always @ (posedge clk) begin
//   if (reset) begin
//     // Reset logic for BTB, PHT, and BHR
//     integer i;
//     for (i = 0; i < 16; i = i + 1) begin
//       BTB_valid[i] <= 1'b0;
//       BTB_tag[i] <= 26'b0;
//       BTB_target[i] <= `DBITS'b0;
//     end
//     for (i = 0; i < 256; i = i + 1) begin
//       PHT[i] = 2'b01; // weakly not taken
//     end
//     BHR <= 8'b0;
//   end else if (is_br_AGEX || is_jmp_AGEX) begin
//     // Update BTB
//     BTB_valid[BTB_index] <= 1'b1;
//     BTB_tag[BTB_index] <= PC_AGEX[31:6];
//     BTB_target[BTB_index] <= br_target_AGEX;

//     // Update PHT
//     if (br_cond_AGEX) begin
//       if (PHT[PHT_index] < 2'b11) begin
//         PHT[PHT_index] <= PHT[PHT_index] + 1;
//       end
//     end else begin
//       if (PHT[PHT_index] > 2'b00) begin
//         PHT[PHT_index] <= PHT[PHT_index] - 1;
//       end
//     end
//     // Update BHR
//     BHR <= {BHR[6:0], br_cond_AGEX};
//   end
// end


    assign  {                     
                                  valid_AGEX,
                                  inst_AGEX,
                                  PC_AGEX,
                                  pcplus_AGEX,
                                  op_I_AGEX,
                                  inst_count_AGEX,
                                          // more signals might need
                                  regval1_AGEX,
                                  regval2_AGEX,
                                  sxt_imm_AGEX,                                
                                  is_br_AGEX,
                                  is_jmp_AGEX,
                                  rd_mem_AGEX,
                                  wr_mem_AGEX,
                                  wr_reg_AGEX,
                                  wregno_AGEX
                                  } = from_DE_latch; 

  assign  {                     
                                valid_FE, 
                                inst_FE, 
                                PC_FE_latch, 
                                pcplus_FE,
                                inst_count_FE, 
                                next_PC
                                  } = from_FE_latch;
    
 
  assign AGEX_latch_contents = {
                                valid_AGEX,
                                inst_AGEX,
                                PC_AGEX,
                                op_I_AGEX,
                                inst_count_AGEX,
                                       // more signals might need
                                memaddr_AGEX, 
                                aluout_AGEX,
                                rd_mem_AGEX,
                                wr_mem_AGEX,
                                wr_reg_AGEX,
                                wregno_AGEX
                                 }; 
 
  always @ (posedge clk ) begin
    if(reset) begin
      AGEX_latch <= {`AGEX_latch_WIDTH{1'b0}};
        end 
    else 
        begin
            AGEX_latch <= AGEX_latch_contents ;
        end 
  end


  // forward signals to FE stage
  assign from_AGEX_to_FE = { 
    br_mispred_AGEX,
    br_target_AGEX,
    PC_AGEX, //added for execution use
    is_br_AGEX,
    is_jmp_AGEX,
    br_cond_AGEX
  };

  // forward signals to DE stage
  assign from_AGEX_to_DE = { 
    br_mispred_AGEX
  };

endmodule
