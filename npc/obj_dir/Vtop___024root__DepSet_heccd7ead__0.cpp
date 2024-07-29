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

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->Y) == vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->Y) == vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->Y) == vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->Y) == vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__pair_list[0U] 
        = (0xcU | (IData)(vlSelf->X3));
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__pair_list[1U] 
        = (8U | (IData)(vlSelf->X2));
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__pair_list[2U] 
        = (4U | (IData)(vlSelf->X1));
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__pair_list[3U] 
        = vlSelf->X0;
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__data_list[0U] 
        = vlSelf->X3;
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__data_list[1U] 
        = vlSelf->X2;
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__data_list[2U] 
        = vlSelf->X1;
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__data_list[3U] 
        = vlSelf->X0;
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->Y) == vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->Y) == vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->Y) == vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->Y) == vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->F = vlSelf->top__DOT__inst_muxkey__DOT__i0__DOT__lut_out;
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
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
    if (VL_UNLIKELY((vlSelf->Y & 0xfcU))) {
        Verilated::overWidthError("Y");}
    if (VL_UNLIKELY((vlSelf->X0 & 0xfcU))) {
        Verilated::overWidthError("X0");}
    if (VL_UNLIKELY((vlSelf->X1 & 0xfcU))) {
        Verilated::overWidthError("X1");}
    if (VL_UNLIKELY((vlSelf->X2 & 0xfcU))) {
        Verilated::overWidthError("X2");}
    if (VL_UNLIKELY((vlSelf->X3 & 0xfcU))) {
        Verilated::overWidthError("X3");}
}
#endif  // VL_DEBUG
