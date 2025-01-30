// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_var_seq.h for the primary calling header

#include "Vadder_var_seq__pch.h"
#include "Vadder_var_seq___024root.h"

VL_INLINE_OPT void Vadder_var_seq___024root___ico_sequent__TOP__0(Vadder_var_seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->adder_var_seq__DOT__calcuate_en = (IData)(
                                                      ((3U 
                                                        == (IData)(vlSelf->i_valid)) 
                                                       & (IData)(vlSelf->i_en)));
}

void Vadder_var_seq___024root___eval_ico(Vadder_var_seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vadder_var_seq___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vadder_var_seq___024root___eval_triggers__ico(Vadder_var_seq___024root* vlSelf);

bool Vadder_var_seq___024root___eval_phase__ico(Vadder_var_seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vadder_var_seq___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vadder_var_seq___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vadder_var_seq___024root___eval_act(Vadder_var_seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vadder_var_seq___024root___nba_sequent__TOP__0(Vadder_var_seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->adder_var_seq__DOT__o_valid_inner = ((IData)(vlSelf->rst_n) 
                                                 && ((IData)(vlSelf->i_en) 
                                                     && (IData)(vlSelf->adder_var_seq__DOT__calcuate_en)));
    vlSelf->adder_var_seq__DOT__o_data_inner = ((IData)(vlSelf->rst_n)
                                                 ? 
                                                ((IData)(vlSelf->i_en)
                                                  ? 
                                                 ((IData)(vlSelf->adder_var_seq__DOT__calcuate_en)
                                                   ? 
                                                  (0x1ffffU 
                                                   & (((0x10000U 
                                                        & (vlSelf->i_data 
                                                           << 1U)) 
                                                       | (0xffffU 
                                                          & vlSelf->i_data)) 
                                                      + 
                                                      ((0x10000U 
                                                        & (vlSelf->i_data 
                                                           >> 0xfU)) 
                                                       | (vlSelf->i_data 
                                                          >> 0x10U))))
                                                   : 0U)
                                                  : 0U)
                                                 : 0U);
    vlSelf->o_valid = vlSelf->adder_var_seq__DOT__o_valid_inner;
    vlSelf->o_data = vlSelf->adder_var_seq__DOT__o_data_inner;
}

void Vadder_var_seq___024root___eval_nba(Vadder_var_seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vadder_var_seq___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vadder_var_seq___024root___eval_triggers__act(Vadder_var_seq___024root* vlSelf);

bool Vadder_var_seq___024root___eval_phase__act(Vadder_var_seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadder_var_seq___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vadder_var_seq___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vadder_var_seq___024root___eval_phase__nba(Vadder_var_seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadder_var_seq___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_var_seq___024root___dump_triggers__ico(Vadder_var_seq___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_var_seq___024root___dump_triggers__nba(Vadder_var_seq___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_var_seq___024root___dump_triggers__act(Vadder_var_seq___024root* vlSelf);
#endif  // VL_DEBUG

void Vadder_var_seq___024root___eval(Vadder_var_seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vadder_var_seq___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("adder_var_seq.v", 29, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vadder_var_seq___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vadder_var_seq___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("adder_var_seq.v", 29, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vadder_var_seq___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("adder_var_seq.v", 29, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vadder_var_seq___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vadder_var_seq___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadder_var_seq___024root___eval_debug_assertions(Vadder_var_seq___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->i_valid & 0xfcU))) {
        Verilated::overWidthError("i_valid");}
    if (VL_UNLIKELY((vlSelf->i_en & 0xfeU))) {
        Verilated::overWidthError("i_en");}
}
#endif  // VL_DEBUG
