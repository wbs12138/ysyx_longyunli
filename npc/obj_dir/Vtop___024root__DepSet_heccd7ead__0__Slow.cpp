// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->rf0 = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

void Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP();

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    if ((0x100073U == vlSelf->ist)) {
        Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP();
    }
    vlSelf->rf1 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [1U];
    vlSelf->rf2 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [2U];
    vlSelf->rf3 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [3U];
    vlSelf->rf4 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [4U];
    vlSelf->rf5 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [5U];
    vlSelf->rf6 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [6U];
    vlSelf->rf7 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [7U];
    vlSelf->rf8 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [8U];
    vlSelf->rf9 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [9U];
    vlSelf->rf10 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0xaU];
    vlSelf->rf11 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0xbU];
    vlSelf->rf12 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0xcU];
    vlSelf->rf13 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0xdU];
    vlSelf->rf14 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0xeU];
    vlSelf->rf15 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0xfU];
    vlSelf->rf16 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x10U];
    vlSelf->rf17 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x11U];
    vlSelf->rf18 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x12U];
    vlSelf->rf19 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x13U];
    vlSelf->rf20 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x14U];
    vlSelf->rf21 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x15U];
    vlSelf->rf22 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x16U];
    vlSelf->rf23 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x17U];
    vlSelf->rf24 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x18U];
    vlSelf->rf25 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x19U];
    vlSelf->rf26 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x1aU];
    vlSelf->rf27 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x1bU];
    vlSelf->rf28 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x1cU];
    vlSelf->rf29 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x1dU];
    vlSelf->rf30 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x1eU];
    vlSelf->rf31 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0x1fU];
    vlSelf->ftrace1 = (IData)((0xefU == (0xfffU & vlSelf->ist)));
    vlSelf->ftrace2 = (0x8067U == vlSelf->ist);
    vlSelf->top__DOT__rf_rdata = ((0U == (0x1fU & (vlSelf->ist 
                                                   >> 0xfU)))
                                   ? 0U : vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                  [(0x1fU & (vlSelf->ist 
                                             >> 0xfU))]);
    vlSelf->top__DOT__addi = (IData)((0x13U == (0x707fU 
                                                & vlSelf->ist)));
    vlSelf->top__DOT__inst_u = ((0x17U == (0x7fU & vlSelf->ist)) 
                                | (0x37U == (0x7fU 
                                             & vlSelf->ist)));
    vlSelf->top__DOT__jalr = (IData)((0x67U == (0x707fU 
                                                & vlSelf->ist)));
    vlSelf->ftrace3 = ((IData)(vlSelf->top__DOT__jalr) 
                       & (0x80U == (0xf80U & vlSelf->ist)));
    vlSelf->top__DOT__imm = (((IData)(vlSelf->top__DOT__addi) 
                              | (IData)(vlSelf->top__DOT__jalr))
                              ? VL_SHIFTR_III(32,32,32, vlSelf->ist, 0x14U)
                              : ((IData)(vlSelf->top__DOT__inst_u)
                                  ? (0xfffff000U & vlSelf->ist)
                                  : ((0x6fU == (0x7fU 
                                                & vlSelf->ist))
                                      ? (((- (IData)(
                                                     (vlSelf->ist 
                                                      >> 0x1fU))) 
                                          << 0x15U) 
                                         | ((0x100000U 
                                             & (vlSelf->ist 
                                                >> 0xbU)) 
                                            | ((0xff000U 
                                                & vlSelf->ist) 
                                               | ((0x800U 
                                                   & (vlSelf->ist 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlSelf->ist 
                                                        >> 0x14U))))))
                                      : 0U)));
    vlSelf->ftrace4 = ((IData)(vlSelf->top__DOT__jalr) 
                       & (IData)(((0U == (0xf80U & vlSelf->ist)) 
                                  & (0U == vlSelf->top__DOT__imm))));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3 
        = (vlSelf->pc + vlSelf->top__DOT__imm);
    vlSelf->dnpc = ((IData)(vlSelf->top__DOT__jalr)
                     ? (0xfffffffeU & (vlSelf->top__DOT__rf_rdata 
                                       + vlSelf->top__DOT__imm))
                     : ((0x6fU == (0x7fU & vlSelf->ist))
                         ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3
                         : ((IData)(4U) + vlSelf->pc)));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ vlSelf->__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->ist = VL_RAND_RESET_I(32);
    vlSelf->rf0 = VL_RAND_RESET_I(32);
    vlSelf->rf1 = VL_RAND_RESET_I(32);
    vlSelf->rf2 = VL_RAND_RESET_I(32);
    vlSelf->rf3 = VL_RAND_RESET_I(32);
    vlSelf->rf4 = VL_RAND_RESET_I(32);
    vlSelf->rf5 = VL_RAND_RESET_I(32);
    vlSelf->rf6 = VL_RAND_RESET_I(32);
    vlSelf->rf7 = VL_RAND_RESET_I(32);
    vlSelf->rf8 = VL_RAND_RESET_I(32);
    vlSelf->rf9 = VL_RAND_RESET_I(32);
    vlSelf->rf10 = VL_RAND_RESET_I(32);
    vlSelf->rf11 = VL_RAND_RESET_I(32);
    vlSelf->rf12 = VL_RAND_RESET_I(32);
    vlSelf->rf13 = VL_RAND_RESET_I(32);
    vlSelf->rf14 = VL_RAND_RESET_I(32);
    vlSelf->rf15 = VL_RAND_RESET_I(32);
    vlSelf->rf16 = VL_RAND_RESET_I(32);
    vlSelf->rf17 = VL_RAND_RESET_I(32);
    vlSelf->rf18 = VL_RAND_RESET_I(32);
    vlSelf->rf19 = VL_RAND_RESET_I(32);
    vlSelf->rf20 = VL_RAND_RESET_I(32);
    vlSelf->rf21 = VL_RAND_RESET_I(32);
    vlSelf->rf22 = VL_RAND_RESET_I(32);
    vlSelf->rf23 = VL_RAND_RESET_I(32);
    vlSelf->rf24 = VL_RAND_RESET_I(32);
    vlSelf->rf25 = VL_RAND_RESET_I(32);
    vlSelf->rf26 = VL_RAND_RESET_I(32);
    vlSelf->rf27 = VL_RAND_RESET_I(32);
    vlSelf->rf28 = VL_RAND_RESET_I(32);
    vlSelf->rf29 = VL_RAND_RESET_I(32);
    vlSelf->rf30 = VL_RAND_RESET_I(32);
    vlSelf->rf31 = VL_RAND_RESET_I(32);
    vlSelf->ftrace1 = VL_RAND_RESET_I(1);
    vlSelf->ftrace2 = VL_RAND_RESET_I(1);
    vlSelf->ftrace3 = VL_RAND_RESET_I(1);
    vlSelf->ftrace4 = VL_RAND_RESET_I(1);
    vlSelf->dnpc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__addi = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__inst_u = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rf_rdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__inst_RegisterFile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
