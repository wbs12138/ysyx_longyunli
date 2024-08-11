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

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
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

void Vtop___024root____Vdpiimwrap_top__DOT__inst_RegisterFile__DOT__regfile_update_TOP(IData/*31:0*/ rf1, IData/*31:0*/ rf2, IData/*31:0*/ rf3, IData/*31:0*/ rf4, IData/*31:0*/ rf5, IData/*31:0*/ rf6, IData/*31:0*/ rf7, IData/*31:0*/ rf8, IData/*31:0*/ rf9, IData/*31:0*/ rf10, IData/*31:0*/ rf11, IData/*31:0*/ rf12, IData/*31:0*/ rf13, IData/*31:0*/ rf14, IData/*31:0*/ rf15, IData/*31:0*/ rf16, IData/*31:0*/ rf17, IData/*31:0*/ rf18, IData/*31:0*/ rf19, IData/*31:0*/ rf20, IData/*31:0*/ rf21, IData/*31:0*/ rf22, IData/*31:0*/ rf23, IData/*31:0*/ rf24, IData/*31:0*/ rf25, IData/*31:0*/ rf26, IData/*31:0*/ rf27, IData/*31:0*/ rf28, IData/*31:0*/ rf29, IData/*31:0*/ rf30, IData/*31:0*/ rf31);
void Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP();
void Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ftrace__DOT__ftrace_update_TOP(IData/*31:0*/ dnpc_v, IData/*31:0*/ trace1, IData/*31:0*/ trace2, IData/*31:0*/ trace3, IData/*31:0*/ trace4);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    Vtop___024root____Vdpiimwrap_top__DOT__inst_RegisterFile__DOT__regfile_update_TOP(
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [1U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [2U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [3U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [4U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [5U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [6U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [7U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [8U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [9U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xaU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xbU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xcU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xdU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xeU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xfU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x10U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x11U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x12U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x13U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x14U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x15U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x16U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x17U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x18U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x19U], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x1aU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x1bU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x1cU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x1dU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x1eU], 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0x1fU]);
    if ((0x100073U == vlSelf->ist)) {
        Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP();
    }
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
    vlSelf->top__DOT__inst_dpi_c_ftrace__DOT__jalr 
        = (IData)((0x67U == (0x707fU & vlSelf->ist)));
    vlSelf->top__DOT__imm = (((IData)(vlSelf->top__DOT__addi) 
                              | (IData)(vlSelf->top__DOT__inst_dpi_c_ftrace__DOT__jalr))
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
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3 
        = (vlSelf->pc + vlSelf->top__DOT__imm);
    Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ftrace__DOT__ftrace_update_TOP(
                                                                                ((IData)(vlSelf->top__DOT__inst_dpi_c_ftrace__DOT__jalr)
                                                                                 ? 
                                                                                (0xfffffffeU 
                                                                                & (vlSelf->top__DOT__rf_rdata 
                                                                                + vlSelf->top__DOT__imm))
                                                                                 : 
                                                                                ((0x6fU 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlSelf->ist))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3
                                                                                 : 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->pc))), 
                                                                                ((0x6fU 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlSelf->ist)) 
                                                                                & (1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->ist 
                                                                                >> 7U)))), 
                                                                                (0x8067U 
                                                                                == vlSelf->ist), 
                                                                                ((IData)(vlSelf->top__DOT__inst_dpi_c_ftrace__DOT__jalr) 
                                                                                & (1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->ist 
                                                                                >> 7U)))), 
                                                                                ((IData)(vlSelf->top__DOT__inst_dpi_c_ftrace__DOT__jalr) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                == 
                                                                                (0xfff00f80U 
                                                                                & vlSelf->ist)))));
    vlSelf->top__DOT__pc_next = ((IData)(vlSelf->top__DOT__inst_dpi_c_ftrace__DOT__jalr)
                                  ? (0xfffffffeU & 
                                     (vlSelf->top__DOT__rf_rdata 
                                      + vlSelf->top__DOT__imm))
                                  : ((0x6fU == (0x7fU 
                                                & vlSelf->ist))
                                      ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3
                                      : ((IData)(4U) 
                                         + vlSelf->pc)));
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
    vlSelf->top__DOT__addi = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__inst_u = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rf_rdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc_next = VL_RAND_RESET_I(32);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__inst_RegisterFile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__inst_dpi_c_ftrace__DOT__jalr = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
