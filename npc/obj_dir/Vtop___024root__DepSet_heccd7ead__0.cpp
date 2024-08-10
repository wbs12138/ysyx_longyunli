// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP();

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
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
    vlSelf->top__DOT__jalr = (IData)((0x67U == (0x707fU 
                                                & vlSelf->ist)));
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
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3 
        = (vlSelf->pc + vlSelf->top__DOT__imm);
    vlSelf->top__DOT__pc_next = ((IData)(vlSelf->top__DOT__jalr)
                                  ? (0xfffffffeU & 
                                     (vlSelf->top__DOT__rf_rdata 
                                      + vlSelf->top__DOT__imm))
                                  : ((0x6fU == (0x7fU 
                                                & vlSelf->ist))
                                      ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3
                                      : ((IData)(4U) 
                                         + vlSelf->pc)));
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __VdlyVal__top__DOT__inst_RegisterFile__DOT__rf__v0;
    __VdlyVal__top__DOT__inst_RegisterFile__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__inst_RegisterFile__DOT__rf__v0;
    __VdlyDim0__top__DOT__inst_RegisterFile__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__inst_RegisterFile__DOT__rf__v0;
    __VdlySet__top__DOT__inst_RegisterFile__DOT__rf__v0 = 0;
    // Body
    __VdlySet__top__DOT__inst_RegisterFile__DOT__rf__v0 = 0U;
    if (((IData)(vlSelf->top__DOT__addi) | ((IData)(vlSelf->top__DOT__inst_u) 
                                            | ((0x6fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->ist)) 
                                               | (IData)(vlSelf->top__DOT__jalr))))) {
        __VdlyVal__top__DOT__inst_RegisterFile__DOT__rf__v0 
            = ((IData)(vlSelf->top__DOT__addi) ? (vlSelf->top__DOT__rf_rdata 
                                                  + 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelf->top__DOT__imm 
                                                                   >> 0xbU)))) 
                                                    << 0xcU) 
                                                   | (0xfffU 
                                                      & vlSelf->top__DOT__imm)))
                : ((0x17U == (0x7fU & vlSelf->ist))
                    ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3
                    : ((0x37U == (0x7fU & vlSelf->ist))
                        ? vlSelf->top__DOT__imm : (
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->ist))
                                                    ? 
                                                   ((IData)(4U) 
                                                    + vlSelf->pc)
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__jalr)
                                                     ? 
                                                    ((IData)(4U) 
                                                     + vlSelf->pc)
                                                     : 0U)))));
        __VdlyDim0__top__DOT__inst_RegisterFile__DOT__rf__v0 
            = (0x1fU & (vlSelf->ist >> 7U));
        __VdlySet__top__DOT__inst_RegisterFile__DOT__rf__v0 = 1U;
    }
    if (__VdlySet__top__DOT__inst_RegisterFile__DOT__rf__v0) {
        vlSelf->top__DOT__inst_RegisterFile__DOT__rf[__VdlyDim0__top__DOT__inst_RegisterFile__DOT__rf__v0] 
            = __VdlyVal__top__DOT__inst_RegisterFile__DOT__rf__v0;
    }
    vlSelf->pc = ((IData)(vlSelf->reset) ? 0x80000000U
                   : vlSelf->top__DOT__pc_next);
    vlSelf->rf0 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
        [0U];
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
    vlSelf->top__DOT__rf_rdata = ((0U == (0x1fU & (vlSelf->ist 
                                                   >> 0xfU)))
                                   ? 0U : vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                  [(0x1fU & (vlSelf->ist 
                                             >> 0xfU))]);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3 
        = (vlSelf->pc + vlSelf->top__DOT__imm);
    vlSelf->top__DOT__pc_next = ((IData)(vlSelf->top__DOT__jalr)
                                  ? (0xfffffffeU & 
                                     (vlSelf->top__DOT__rf_rdata 
                                      + vlSelf->top__DOT__imm))
                                  : ((0x6fU == (0x7fU 
                                                & vlSelf->ist))
                                      ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3
                                      : ((IData)(4U) 
                                         + vlSelf->pc)));
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
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
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/top.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/top.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
