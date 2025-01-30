// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpipeline__Syms.h"


VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__pipeline__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("pipeline", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpipeline___024root__trace_init_sub__TOP__pipeline__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+144,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__pipeline__my_WB_stage__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__pipeline__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_sub__TOP__pipeline__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+144,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"cycle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+2,0,"FE_latch_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 128,0);
    tracep->declArray(c+7,0,"DE_latch_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 237,0);
    tracep->declArray(c+15,0,"AGEX_latch_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 140,0);
    tracep->declArray(c+20,0,"MEM_latch_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 140,0);
    tracep->declBus(c+25,0,"from_DE_to_FE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declQuad(c+26,0,"from_AGEX_to_FE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+186,0,"from_MEM_to_FE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+187,0,"from_WB_to_FE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+28,0,"from_AGEX_to_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+186,0,"from_MEM_to_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declQuad(c+29,0,"from_WB_to_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declBus(c+186,0,"from_MEM_to_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+187,0,"from_WB_to_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+187,0,"from_WB_to_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("my_WB_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpipeline___024root__trace_init_sub__TOP__pipeline__my_WB_stage__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("my_AGEX_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+144,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+186,0,"from_MEM_to_AGEX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+187,0,"from_WB_to_AGEX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declArray(c+7,0,"from_DE_latch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 237,0);
    tracep->declArray(c+15,0,"AGEX_latch_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 140,0);
    tracep->declQuad(c+26,0,"from_AGEX_to_FE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+28,0,"from_AGEX_to_DE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declArray(c+15,0,"AGEX_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 140,0);
    tracep->declArray(c+31,0,"AGEX_latch_contents",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 140,0);
    tracep->declBit(c+36,0,"valid_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"inst_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"PC_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"inst_count_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"pcplus_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"op_I_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+28,0,"br_cond_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"is_br_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"wr_reg_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"wregno_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+45,0,"regval1_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"regval2_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"sxt_imm_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"br_target_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+49,0,"br_mispred_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"aluout_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("my_DE_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+144,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+2,0,"from_FE_latch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 128,0);
    tracep->declBus(c+28,0,"from_AGEX_to_DE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+186,0,"from_MEM_to_DE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declQuad(c+29,0,"from_WB_to_DE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declBus(c+25,0,"from_DE_to_FE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declArray(c+7,0,"DE_latch_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 237,0);
    tracep->declArray(c+7,0,"DE_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 237,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+111+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+51,0,"valid_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"inst_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"PC_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"pcplus_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"inst_count_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+101,0,"DE_latch_contents",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 237,0);
    tracep->declBus(c+56,0,"F3_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+57,0,"F7_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+58,0,"op_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+59,0,"op_I_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+60,0,"type_I_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+61,0,"type_immediate_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+62,0,"sxt_imm_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"rs1_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+64,0,"rs2_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+65,0,"rd_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+109,0,"rs1_val_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"rs2_val_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+66,0,"is_br_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"wr_reg_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"wr_reg_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"wregno_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+70,0,"regval_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+25,0,"pipeline_stall_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"use_rs1_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"use_rs2_DE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"in_use_regs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+74,0,"has_data_hazards",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"br_mispred_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("my_FE_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+144,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"from_DE_to_FE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declQuad(c+26,0,"from_AGEX_to_FE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+186,0,"from_MEM_to_FE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+187,0,"from_WB_to_FE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declArray(c+2,0,"FE_latch_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 128,0);
    tracep->declArray(c+2,0,"FE_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 128,0);
    tracep->declBit(c+188,0,"valid_FE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"PC_FE_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"inst_count_FE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"inst_count_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"inst_FE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"pcplus_FE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+25,0,"stall_pipe_FE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+79,0,"FE_latch_contents",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 128,0);
    tracep->declBit(c+49,0,"br_mispred_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"br_target_AGEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("my_MEM_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+144,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+187,0,"from_WB_to_MEM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declArray(c+15,0,"from_AGEX_latch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 140,0);
    tracep->declArray(c+20,0,"MEM_latch_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 140,0);
    tracep->declBus(c+186,0,"from_MEM_to_FE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+186,0,"from_MEM_to_DE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+186,0,"from_MEM_to_AGEX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declArray(c+20,0,"MEM_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 140,0);
    tracep->declBit(c+84,0,"valid_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+15,0,"MEM_latch_contents",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 140,0);
    tracep->declBus(c+85,0,"op_I_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+86,0,"inst_count_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"inst_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"PC_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"aluout_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"wregno_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+91,0,"wr_reg_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+190,0,"memaddr_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"rd_val_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"wr_val_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+192,0,"wr_mem_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__pipeline__my_WB_stage__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_sub__TOP__pipeline__my_WB_stage__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+144,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+20,0,"from_MEM_latch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 140,0);
    tracep->declBus(c+186,0,"from_WB_to_FE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declQuad(c+29,0,"from_WB_to_DE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declBus(c+186,0,"from_WB_to_AGEX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+186,0,"from_WB_to_MEM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+93,0,"valid_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,0,"op_I_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+95,0,"inst_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"PC_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"inst_count_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+98,0,"wr_reg_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"wregno_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+100,0,"regval_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"aluout_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+193,0,"rd_val_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("last_WB_value", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+146,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+148,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+149,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+154,0,"[8]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+155,0,"[9]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+156,0,"[10]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+157,0,"[11]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+158,0,"[12]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+159,0,"[13]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"[14]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"[15]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"[16]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"[17]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+164,0,"[18]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"[19]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"[20]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"[21]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"[22]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"[23]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"[24]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"[25]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"[26]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"[27]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"[28]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"[29]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"[30]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"[31]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("WB_counters", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+178,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+181,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+182,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+143,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpipeline___024root__trace_init_top(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_top\n"); );
    // Body
    Vpipeline___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vpipeline___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vpipeline___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpipeline___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpipeline___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vpipeline___024root__trace_register(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vpipeline___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vpipeline___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vpipeline___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vpipeline___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vpipeline___024root__trace_const_0_sub_0(Vpipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpipeline___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_const_0\n"); );
    // Init
    Vpipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpipeline___024root*>(voidSelf);
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpipeline___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpipeline___024root__trace_const_0_sub_0(Vpipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+186,(0U));
    bufp->fullBit(oldp+187,(0U));
    bufp->fullBit(oldp+188,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__valid_FE));
    bufp->fullIData(oldp+189,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__inst_count_AGEX),32);
    bufp->fullIData(oldp+190,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__memaddr_MEM),32);
    bufp->fullIData(oldp+191,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__wr_val_MEM),32);
    bufp->fullBit(oldp+192,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__wr_mem_MEM));
    bufp->fullIData(oldp+193,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__rd_val_WB),32);
}

VL_ATTR_COLD void Vpipeline___024root__trace_full_0_sub_0(Vpipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpipeline___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_full_0\n"); );
    // Init
    Vpipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpipeline___024root*>(voidSelf);
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpipeline___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpipeline___024root__trace_full_0_sub_0(Vpipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<5>/*159:0*/ __Vtemp_6;
    VlWide<5>/*159:0*/ __Vtemp_9;
    VlWide<5>/*159:0*/ __Vtemp_15;
    VlWide<8>/*255:0*/ __Vtemp_17;
    // Body
    bufp->fullIData(oldp+1,(vlSymsp->TOP__pipeline.__PVT__cycle_count),32);
    bufp->fullWData(oldp+2,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch),129);
    bufp->fullWData(oldp+7,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch),238);
    bufp->fullWData(oldp+15,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch),141);
    bufp->fullWData(oldp+20,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch),141);
    bufp->fullBit(oldp+25,(vlSymsp->TOP__pipeline.__PVT__from_DE_to_FE));
    bufp->fullQData(oldp+26,((((QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__br_mispred_AGEX)) 
                               << 0x20U) | (QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__br_target_AGEX)))),33);
    bufp->fullBit(oldp+28,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__br_cond_AGEX));
    bufp->fullQData(oldp+29,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE),38);
    __Vtemp_6[0U] = vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[0U];
    __Vtemp_6[1U] = vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[1U];
    __Vtemp_6[2U] = vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[2U];
    __Vtemp_6[3U] = ((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__aluout_AGEX 
                      << 8U) | (((IData)(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__br_cond_AGEX) 
                                 << 7U) | (0x7fU & 
                                           vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U])));
    __Vtemp_6[4U] = ((0x1f00U & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U] 
                                 << 1U)) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__aluout_AGEX 
                                            >> 0x18U));
    bufp->fullWData(oldp+31,(__Vtemp_6),141);
    bufp->fullBit(oldp+36,((1U & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                                  >> 0xdU))));
    bufp->fullIData(oldp+37,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                               << 0x13U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                            >> 0xdU))),32);
    bufp->fullIData(oldp+38,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                               << 0x13U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[5U] 
                                            >> 0xdU))),32);
    bufp->fullIData(oldp+39,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U] 
                               << 0x19U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U] 
                                            >> 7U))),32);
    bufp->fullIData(oldp+40,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[5U] 
                               << 0x13U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U] 
                                            >> 0xdU))),32);
    bufp->fullCData(oldp+41,((0x3fU & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U] 
                                       >> 7U))),6);
    bufp->fullBit(oldp+42,((1U & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[0U] 
                                  >> 6U))));
    bufp->fullBit(oldp+43,((1U & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[0U] 
                                  >> 5U))));
    bufp->fullCData(oldp+44,((0x1fU & vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[0U])),5);
    bufp->fullIData(oldp+45,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U] 
                               << 0x19U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[2U] 
                                            >> 7U))),32);
    bufp->fullIData(oldp+46,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[2U] 
                               << 0x19U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[1U] 
                                            >> 7U))),32);
    bufp->fullIData(oldp+47,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[1U] 
                               << 0x19U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[0U] 
                                            >> 7U))),32);
    bufp->fullIData(oldp+48,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__br_target_AGEX),32);
    bufp->fullBit(oldp+49,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__br_mispred_AGEX));
    bufp->fullIData(oldp+50,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__aluout_AGEX),32);
    bufp->fullBit(oldp+51,((1U & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[4U])));
    bufp->fullIData(oldp+52,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U]),32);
    bufp->fullIData(oldp+53,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[2U]),32);
    bufp->fullIData(oldp+54,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[1U]),32);
    bufp->fullIData(oldp+55,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U]),32);
    bufp->fullCData(oldp+56,((7U & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+57,((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                              >> 0x19U)),7);
    bufp->fullCData(oldp+58,((0x7fU & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U])),7);
    bufp->fullCData(oldp+59,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE),6);
    bufp->fullCData(oldp+60,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_I_DE),4);
    bufp->fullCData(oldp+61,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE),3);
    bufp->fullIData(oldp+62,(((1U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                               ? (((- (IData)((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                               >> 0x1fU))) 
                                   << 0xbU) | (0x7ffU 
                                               & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                  >> 0x14U)))
                               : ((5U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                   ? (((- (IData)((
                                                   vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (
                                                   (0x800U 
                                                    & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                            >> 7U)))))
                                   : 0U))),32);
    bufp->fullCData(oldp+63,((0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+64,((0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+65,((0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                       >> 7U))),5);
    bufp->fullBit(oldp+66,(((0x1cU == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                            | (0x1dU == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)))));
    bufp->fullBit(oldp+67,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__wr_reg_DE));
    bufp->fullBit(oldp+68,((1U & (IData)((vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE 
                                          >> 0x25U)))));
    bufp->fullCData(oldp+69,((0x1fU & (IData)((vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE 
                                               >> 0x20U)))),5);
    bufp->fullIData(oldp+70,((IData)(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE)),32);
    bufp->fullBit(oldp+71,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__use_rs1_DE));
    bufp->fullBit(oldp+72,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__use_rs2_DE));
    bufp->fullIData(oldp+73,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__in_use_regs),32);
    bufp->fullBit(oldp+74,((((IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__use_rs1_DE) 
                             & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__in_use_regs 
                                >> (0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                             >> 0xfU)))) 
                            | ((IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__use_rs2_DE) 
                               & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__in_use_regs 
                                  >> (0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                               >> 0x14U)))))));
    bufp->fullIData(oldp+75,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch),32);
    bufp->fullIData(oldp+76,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__inst_count_FE),32);
    bufp->fullIData(oldp+77,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__imem
                             [(0x3fffU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch 
                                          >> 2U))]),32);
    bufp->fullIData(oldp+78,(((IData)(4U) + vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch)),32);
    __Vtemp_9[0U] = vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__inst_count_FE;
    __Vtemp_9[1U] = ((IData)(4U) + vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch);
    __Vtemp_9[2U] = (IData)((((QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__imem
                                              [(0x3fffU 
                                                & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch 
                                                   >> 2U))])) 
                              << 0x20U) | (QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch))));
    __Vtemp_9[3U] = (IData)(((((QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__imem
                                               [(0x3fffU 
                                                 & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch 
                                                    >> 2U))])) 
                               << 0x20U) | (QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch))) 
                             >> 0x20U));
    __Vtemp_9[4U] = vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__valid_FE;
    bufp->fullWData(oldp+79,(__Vtemp_9),129);
    bufp->fullBit(oldp+84,((1U & (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[4U] 
                                  >> 0xcU))));
    bufp->fullCData(oldp+85,((0x3fU & (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] 
                                       >> 6U))),6);
    bufp->fullIData(oldp+86,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] 
                               << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[1U] 
                                            >> 6U))),32);
    bufp->fullIData(oldp+87,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[4U] 
                               << 0x14U) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[3U] 
                                            >> 0xcU))),32);
    bufp->fullIData(oldp+88,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[3U] 
                               << 0x14U) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] 
                                            >> 0xcU))),32);
    bufp->fullIData(oldp+89,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[1U] 
                               << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[0U] 
                                            >> 6U))),32);
    bufp->fullCData(oldp+90,((0x1fU & vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[0U])),5);
    bufp->fullBit(oldp+91,((1U & (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[0U] 
                                  >> 5U))));
    bufp->fullIData(oldp+92,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__dmem
                             [(0x3fffU & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__memaddr_MEM 
                                          >> 2U))]),32);
    bufp->fullBit(oldp+93,((1U & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                                  >> 0xcU))));
    bufp->fullCData(oldp+94,((0x3fU & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                       >> 6U))),6);
    bufp->fullIData(oldp+95,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                               << 0x14U) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                                            >> 0xcU))),32);
    bufp->fullIData(oldp+96,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                               << 0x14U) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                            >> 0xcU))),32);
    bufp->fullIData(oldp+97,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                               << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                                            >> 6U))),32);
    bufp->fullBit(oldp+98,((1U & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                  >> 5U))));
    bufp->fullCData(oldp+99,((0x1fU & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U])),5);
    bufp->fullIData(oldp+100,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                                << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                             >> 6U))),32);
    __Vtemp_15[0U] = ((((1U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                         ? (((- (IData)((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                         >> 0x1fU))) 
                             << 0xbU) | (0x7ffU & (
                                                   vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                   >> 0x14U)))
                         : ((5U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                             ? (((- (IData)((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                             >> 0x1fU))) 
                                 << 0xcU) | ((0x800U 
                                              & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 7U)))))
                             : 0U)) << 7U) | ((((0x1cU 
                                                 == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                                                | (0x1dU 
                                                   == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE))) 
                                               << 6U) 
                                              | (((IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__wr_reg_DE) 
                                                  << 5U) 
                                                 | (0x1fU 
                                                    & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                       >> 7U)))));
    __Vtemp_17[0U] = __Vtemp_15[0U];
    __Vtemp_17[1U] = ((((1U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                         ? (((- (IData)((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                         >> 0x1fU))) 
                             << 0xbU) | (0x7ffU & (
                                                   vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                   >> 0x14U)))
                         : ((5U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                             ? (((- (IData)((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                             >> 0x1fU))) 
                                 << 0xcU) | ((0x800U 
                                              & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 7U)))))
                             : 0U)) >> 0x19U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                                 [(0x1fU 
                                                   & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 0x14U))] 
                                                 << 7U));
    __Vtemp_17[2U] = ((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                       [(0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                  >> 0x14U))] >> 0x19U) 
                      | ((IData)((((QData)((IData)(
                                                   vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                                               [
                                                               (0x1fU 
                                                                & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                   >> 0xfU))])))) 
                         << 7U));
    __Vtemp_17[3U] = (((IData)((((QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                 << 0x20U) | (QData)((IData)(
                                                             vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                                             [
                                                             (0x1fU 
                                                              & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                 >> 0xfU))])))) 
                       >> 0x19U) | ((IData)(((((QData)((IData)(
                                                               vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                                                [
                                                                (0x1fU 
                                                                 & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                    >> 0xfU))]))) 
                                             >> 0x20U)) 
                                    << 7U));
    __Vtemp_17[4U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[1U] 
                       << 0xdU) | (((IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE) 
                                    << 7U) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                                                          [
                                                                          (0x1fU 
                                                                           & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                              >> 0xfU))]))) 
                                                       >> 0x20U)) 
                                              >> 0x19U)));
    __Vtemp_17[5U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[1U] 
                       >> 0x13U) | (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[2U] 
                                    << 0xdU));
    __Vtemp_17[6U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[2U] 
                       >> 0x13U) | (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                    << 0xdU));
    __Vtemp_17[7U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                       >> 0x13U) | (0x2000U & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[4U] 
                                               << 0xdU)));
    bufp->fullWData(oldp+101,(__Vtemp_17),238);
    bufp->fullIData(oldp+109,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                              [(0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                         >> 0xfU))]),32);
    bufp->fullIData(oldp+110,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                              [(0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                         >> 0x14U))]),32);
    bufp->fullIData(oldp+111,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[0]),32);
    bufp->fullIData(oldp+112,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[1]),32);
    bufp->fullIData(oldp+113,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[2]),32);
    bufp->fullIData(oldp+114,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[3]),32);
    bufp->fullIData(oldp+115,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[4]),32);
    bufp->fullIData(oldp+116,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[5]),32);
    bufp->fullIData(oldp+117,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[6]),32);
    bufp->fullIData(oldp+118,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[7]),32);
    bufp->fullIData(oldp+119,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[8]),32);
    bufp->fullIData(oldp+120,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[9]),32);
    bufp->fullIData(oldp+121,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[10]),32);
    bufp->fullIData(oldp+122,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[11]),32);
    bufp->fullIData(oldp+123,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[12]),32);
    bufp->fullIData(oldp+124,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[13]),32);
    bufp->fullIData(oldp+125,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[14]),32);
    bufp->fullIData(oldp+126,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[15]),32);
    bufp->fullIData(oldp+127,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[16]),32);
    bufp->fullIData(oldp+128,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[17]),32);
    bufp->fullIData(oldp+129,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[18]),32);
    bufp->fullIData(oldp+130,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[19]),32);
    bufp->fullIData(oldp+131,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[20]),32);
    bufp->fullIData(oldp+132,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[21]),32);
    bufp->fullIData(oldp+133,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[22]),32);
    bufp->fullIData(oldp+134,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[23]),32);
    bufp->fullIData(oldp+135,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[24]),32);
    bufp->fullIData(oldp+136,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[25]),32);
    bufp->fullIData(oldp+137,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[26]),32);
    bufp->fullIData(oldp+138,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[27]),32);
    bufp->fullIData(oldp+139,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[28]),32);
    bufp->fullIData(oldp+140,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[29]),32);
    bufp->fullIData(oldp+141,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[30]),32);
    bufp->fullIData(oldp+142,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[31]),32);
    bufp->fullIData(oldp+143,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+144,(vlSelf->clk));
    bufp->fullBit(oldp+145,(vlSelf->reset));
    bufp->fullIData(oldp+146,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0U]),32);
    bufp->fullIData(oldp+147,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[1U]),32);
    bufp->fullIData(oldp+148,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[2U]),32);
    bufp->fullIData(oldp+149,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[3U]),32);
    bufp->fullIData(oldp+150,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[4U]),32);
    bufp->fullIData(oldp+151,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[5U]),32);
    bufp->fullIData(oldp+152,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[6U]),32);
    bufp->fullIData(oldp+153,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[7U]),32);
    bufp->fullIData(oldp+154,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[8U]),32);
    bufp->fullIData(oldp+155,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[9U]),32);
    bufp->fullIData(oldp+156,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xaU]),32);
    bufp->fullIData(oldp+157,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xbU]),32);
    bufp->fullIData(oldp+158,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xcU]),32);
    bufp->fullIData(oldp+159,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xdU]),32);
    bufp->fullIData(oldp+160,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xeU]),32);
    bufp->fullIData(oldp+161,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xfU]),32);
    bufp->fullIData(oldp+162,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x10U]),32);
    bufp->fullIData(oldp+163,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x11U]),32);
    bufp->fullIData(oldp+164,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x12U]),32);
    bufp->fullIData(oldp+165,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x13U]),32);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x14U]),32);
    bufp->fullIData(oldp+167,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x15U]),32);
    bufp->fullIData(oldp+168,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x16U]),32);
    bufp->fullIData(oldp+169,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x17U]),32);
    bufp->fullIData(oldp+170,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x18U]),32);
    bufp->fullIData(oldp+171,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x19U]),32);
    bufp->fullIData(oldp+172,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1aU]),32);
    bufp->fullIData(oldp+173,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1bU]),32);
    bufp->fullIData(oldp+174,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1cU]),32);
    bufp->fullIData(oldp+175,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1dU]),32);
    bufp->fullIData(oldp+176,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1eU]),32);
    bufp->fullIData(oldp+177,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1fU]),32);
    bufp->fullIData(oldp+178,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[0U]),32);
    bufp->fullIData(oldp+179,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[1U]),32);
    bufp->fullIData(oldp+180,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[2U]),32);
    bufp->fullIData(oldp+181,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[3U]),32);
    bufp->fullIData(oldp+182,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[4U]),32);
    bufp->fullIData(oldp+183,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[5U]),32);
    bufp->fullIData(oldp+184,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[6U]),32);
    bufp->fullIData(oldp+185,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[7U]),32);
}
