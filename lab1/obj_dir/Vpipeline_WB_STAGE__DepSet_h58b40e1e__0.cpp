// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpipeline.h for the primary calling header

#include "Vpipeline__pch.h"
#include "Vpipeline_WB_STAGE.h"
#include "Vpipeline__Syms.h"

extern const VlWide<8>/*255:0*/ Vpipeline__ConstPool__CONST_h9e67c271_0;

VL_INLINE_OPT void Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__0(Vpipeline_WB_STAGE* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__0\n"); );
    // Body
    if (vlSymsp->TOP.reset) {
        vlSelf->WB_counters[0U] = Vpipeline__ConstPool__CONST_h9e67c271_0[0U];
        vlSelf->WB_counters[1U] = Vpipeline__ConstPool__CONST_h9e67c271_0[1U];
        vlSelf->WB_counters[2U] = Vpipeline__ConstPool__CONST_h9e67c271_0[2U];
        vlSelf->WB_counters[3U] = Vpipeline__ConstPool__CONST_h9e67c271_0[3U];
        vlSelf->WB_counters[4U] = Vpipeline__ConstPool__CONST_h9e67c271_0[4U];
        vlSelf->WB_counters[5U] = Vpipeline__ConstPool__CONST_h9e67c271_0[5U];
        vlSelf->WB_counters[6U] = Vpipeline__ConstPool__CONST_h9e67c271_0[6U];
        vlSelf->WB_counters[7U] = Vpipeline__ConstPool__CONST_h9e67c271_0[7U];
    } else {
        vlSelf->WB_counters[0U] = (1U & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                                         >> 0xcU));
        vlSelf->WB_counters[1U] = ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                                    << 0x14U) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                                 >> 0xcU));
        vlSelf->WB_counters[2U] = (IData)((((QData)((IData)(
                                                            (0x3fU 
                                                             & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                                                >> 6U)))) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                                                               << 0x14U) 
                                                              | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                                                                 >> 0xcU))))));
        vlSelf->WB_counters[3U] = (IData)(((((QData)((IData)(
                                                             (0x3fU 
                                                              & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                                                 >> 6U)))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                                                                << 0x14U) 
                                                               | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                                                                  >> 0xcU))))) 
                                           >> 0x20U));
        vlSelf->WB_counters[4U] = (1U & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                         >> 5U));
        vlSelf->WB_counters[5U] = (IData)((((QData)((IData)(
                                                            ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                                                              << 0x1aU) 
                                                             | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                                                >> 6U)))) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             (0x1fU 
                                                              & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U])))));
        vlSelf->WB_counters[6U] = (IData)(((((QData)((IData)(
                                                             ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                                                               << 0x1aU) 
                                                              | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                                                 >> 6U)))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              (0x1fU 
                                                               & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U])))) 
                                           >> 0x20U));
        vlSelf->WB_counters[7U] = 0U;
    }
}

VL_INLINE_OPT void Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__1(Vpipeline_WB_STAGE* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__1\n"); );
    // Body
    vlSelf->__PVT__from_WB_to_DE = (((QData)((IData)(
                                                     (0x3fU 
                                                      & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U]))) 
                                     << 0x20U) | (QData)((IData)(
                                                                 ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                                                                   << 0x1aU) 
                                                                  | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                                                     >> 6U)))));
}

extern const VlWide<32>/*1023:0*/ Vpipeline__ConstPool__CONST_hd6b7ba52_0;

VL_INLINE_OPT void Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__2(Vpipeline_WB_STAGE* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpipeline_WB_STAGE___nba_sequent__TOP__pipeline__my_WB_stage__2\n"); );
    // Body
    if (vlSymsp->TOP.reset) {
        vlSelf->__PVT__unnamedblk1__DOT__i = 0x20U;
        vlSelf->last_WB_value[0U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0U];
        vlSelf->last_WB_value[1U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[1U];
        vlSelf->last_WB_value[2U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[2U];
        vlSelf->last_WB_value[3U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[3U];
        vlSelf->last_WB_value[4U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[4U];
        vlSelf->last_WB_value[5U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[5U];
        vlSelf->last_WB_value[6U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[6U];
        vlSelf->last_WB_value[7U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[7U];
        vlSelf->last_WB_value[8U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[8U];
        vlSelf->last_WB_value[9U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[9U];
        vlSelf->last_WB_value[0xaU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0xaU];
        vlSelf->last_WB_value[0xbU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0xbU];
        vlSelf->last_WB_value[0xcU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0xcU];
        vlSelf->last_WB_value[0xdU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0xdU];
        vlSelf->last_WB_value[0xeU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0xeU];
        vlSelf->last_WB_value[0xfU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0xfU];
        vlSelf->last_WB_value[0x10U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x10U];
        vlSelf->last_WB_value[0x11U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x11U];
        vlSelf->last_WB_value[0x12U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x12U];
        vlSelf->last_WB_value[0x13U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x13U];
        vlSelf->last_WB_value[0x14U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x14U];
        vlSelf->last_WB_value[0x15U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x15U];
        vlSelf->last_WB_value[0x16U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x16U];
        vlSelf->last_WB_value[0x17U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x17U];
        vlSelf->last_WB_value[0x18U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x18U];
        vlSelf->last_WB_value[0x19U] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x19U];
        vlSelf->last_WB_value[0x1aU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x1aU];
        vlSelf->last_WB_value[0x1bU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x1bU];
        vlSelf->last_WB_value[0x1cU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x1cU];
        vlSelf->last_WB_value[0x1dU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x1dU];
        vlSelf->last_WB_value[0x1eU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x1eU];
        vlSelf->last_WB_value[0x1fU] = Vpipeline__ConstPool__CONST_hd6b7ba52_0[0x1fU];
    } else if ((0x20U & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U])) {
        VL_ASSIGNSEL_WI(1024,32,(0x3ffU & VL_SHIFTL_III(10,32,32, 
                                                        (0x1fU 
                                                         & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U]), 5U)), vlSelf->last_WB_value, 
                        ((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                          << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                       >> 6U)));
    }
}
