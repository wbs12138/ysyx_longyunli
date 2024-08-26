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
void Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP(IData/*31:0*/ back_right);
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
        Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP(
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xaU]);
    }
    vlSelf->top__DOT__slt = (IData)((0x2033U == (0xfe00707fU 
                                                 & vlSelf->ist)));
    vlSelf->top__DOT__sltu = (IData)((0x3033U == (0xfe00707fU 
                                                  & vlSelf->ist)));
    vlSelf->top__DOT__xorr = (IData)((0x4033U == (0xfe00707fU 
                                                  & vlSelf->ist)));
    vlSelf->top__DOT__orr = (IData)((0x6033U == (0xfe00707fU 
                                                 & vlSelf->ist)));
    vlSelf->top__DOT__andd = (IData)((0x7033U == (0xfe00707fU 
                                                  & vlSelf->ist)));
    if ((0U == (0x1fU & (vlSelf->ist >> 0x14U)))) {
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35 = 0U;
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32 = 0U;
        vlSelf->top__DOT__rf_rdata2 = 0U;
    } else {
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35 
            = (0x1fU & vlSelf->top__DOT__inst_RegisterFile__DOT__rf
               [(0x1fU & (vlSelf->ist >> 0x14U))]);
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32 
            = (0x7fffffffU & vlSelf->top__DOT__inst_RegisterFile__DOT__rf
               [(0x1fU & (vlSelf->ist >> 0x14U))]);
        vlSelf->top__DOT__rf_rdata2 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
            [(0x1fU & (vlSelf->ist >> 0x14U))];
    }
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_16 
        = (IData)((0x33U == (0x707fU & vlSelf->ist)));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_17 
        = (IData)((0x5033U == (0x707fU & vlSelf->ist)));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30 
        = ((0U != (0x1fU & (vlSelf->ist >> 0x14U))) 
           & (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
              [(0x1fU & (vlSelf->ist >> 0x14U))] >> 0x1fU));
    vlSelf->top__DOT__sb = (IData)((0x23U == (0x707fU 
                                              & vlSelf->ist)));
    vlSelf->top__DOT__sh = (IData)((0x1023U == (0x707fU 
                                                & vlSelf->ist)));
    vlSelf->top__DOT__sw = (IData)((0x2023U == (0x707fU 
                                                & vlSelf->ist)));
    vlSelf->top__DOT__beq = (IData)((0x63U == (0x707fU 
                                               & vlSelf->ist)));
    vlSelf->top__DOT__bne = (IData)((0x1063U == (0x707fU 
                                                 & vlSelf->ist)));
    vlSelf->top__DOT__blt = (IData)((0x4063U == (0x707fU 
                                                 & vlSelf->ist)));
    vlSelf->top__DOT__bge = (IData)((0x5063U == (0x707fU 
                                                 & vlSelf->ist)));
    vlSelf->top__DOT__bltu = (IData)((0x6063U == (0x707fU 
                                                  & vlSelf->ist)));
    vlSelf->top__DOT__bgeu = (IData)((0x7063U == (0x707fU 
                                                  & vlSelf->ist)));
    vlSelf->top__DOT__addi = (IData)((0x13U == (0x707fU 
                                                & vlSelf->ist)));
    vlSelf->top__DOT__slti = (IData)((0x2013U == (0x707fU 
                                                  & vlSelf->ist)));
    vlSelf->top__DOT__sltiu = (IData)((0x3013U == (0x707fU 
                                                   & vlSelf->ist)));
    vlSelf->top__DOT__xori = (IData)((0x4013U == (0x707fU 
                                                  & vlSelf->ist)));
    vlSelf->top__DOT__ori = (IData)((0x6013U == (0x707fU 
                                                 & vlSelf->ist)));
    vlSelf->top__DOT__andi = (IData)((0x7013U == (0x707fU 
                                                  & vlSelf->ist)));
    vlSelf->top__DOT__lb = (IData)((3U == (0x707fU 
                                           & vlSelf->ist)));
    vlSelf->top__DOT__lbu = (IData)((0x4003U == (0x707fU 
                                                 & vlSelf->ist)));
    vlSelf->top__DOT__lh = (IData)((0x1003U == (0x707fU 
                                                & vlSelf->ist)));
    vlSelf->top__DOT__lhu = (IData)((0x5003U == (0x707fU 
                                                 & vlSelf->ist)));
    vlSelf->top__DOT__lw = (IData)((0x2003U == (0x707fU 
                                                & vlSelf->ist)));
    vlSelf->top__DOT__jalr = (IData)((0x67U == (0x707fU 
                                                & vlSelf->ist)));
    vlSelf->top__DOT__csrrw = (IData)((0x1073U == (0x707fU 
                                                   & vlSelf->ist)));
    vlSelf->top__DOT__csrrs = (IData)((0x2073U == (0x707fU 
                                                   & vlSelf->ist)));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_39 
        = (IData)((0x1000U == (0xfe007000U & vlSelf->ist)));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_13 
        = (IData)((0x5013U == (0x707fU & vlSelf->ist)));
    vlSelf->top__DOT__add = ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_16) 
                             & (0U == (vlSelf->ist 
                                       >> 0x19U)));
    vlSelf->top__DOT__sub = ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_16) 
                             & (0x20U == (vlSelf->ist 
                                          >> 0x19U)));
    vlSelf->top__DOT__srl = ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_17) 
                             & (0U == (vlSelf->ist 
                                       >> 0x19U)));
    vlSelf->top__DOT__sra = ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_17) 
                             & (0x20U == (vlSelf->ist 
                                          >> 0x19U)));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34 
        = (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
           [0xfU] < vlSelf->top__DOT__rf_rdata2);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31 
        = ((vlSelf->top__DOT__inst_RegisterFile__DOT__rf
            [0xfU] >> 0x1fU) == (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30));
    vlSelf->mem_wen_dg = ((IData)(vlSelf->top__DOT__sb) 
                          | ((IData)(vlSelf->top__DOT__sh) 
                             | (IData)(vlSelf->top__DOT__sw)));
    vlSelf->mem_valid = ((IData)(vlSelf->top__DOT__lb) 
                         | ((IData)(vlSelf->top__DOT__lbu) 
                            | ((IData)(vlSelf->top__DOT__lh) 
                               | ((IData)(vlSelf->top__DOT__lhu) 
                                  | (IData)(vlSelf->top__DOT__lw)))));
    if (vlSelf->top__DOT__csrrw) {
        vlSelf->top__DOT__mtvec_next = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
            [0xfU];
        vlSelf->top__DOT__mcause_next = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
            [0xfU];
        vlSelf->top__DOT__mstatus_next = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
            [0xfU];
        vlSelf->top__DOT__mepc_next = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
            [0xfU];
    } else if (vlSelf->top__DOT__csrrs) {
        vlSelf->top__DOT__mtvec_next = (vlSelf->top__DOT__mtvec 
                                        | vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                        [0xfU]);
        vlSelf->top__DOT__mcause_next = (vlSelf->top__DOT__mcause 
                                         | vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                         [0xfU]);
        vlSelf->top__DOT__mstatus_next = (vlSelf->top__DOT__mstatus 
                                          | vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                          [0xfU]);
        vlSelf->top__DOT__mepc_next = (vlSelf->top__DOT__mepc 
                                       | vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                       [0xfU]);
    } else {
        vlSelf->top__DOT__mtvec_next = 0U;
        vlSelf->top__DOT__mcause_next = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
            [0xfU];
        vlSelf->top__DOT__mstatus_next = (0x80U | (
                                                   (0xffffe000U 
                                                    & vlSelf->top__DOT__mstatus) 
                                                   | ((0x700U 
                                                       & vlSelf->top__DOT__mstatus) 
                                                      | ((0x70U 
                                                          & vlSelf->top__DOT__mstatus) 
                                                         | ((8U 
                                                             & (vlSelf->top__DOT__mstatus 
                                                                >> 4U)) 
                                                            | (7U 
                                                               & vlSelf->top__DOT__mstatus))))));
        vlSelf->top__DOT__mepc_next = vlSelf->pc;
    }
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_37 
        = ((IData)(vlSelf->top__DOT__csrrw) | (IData)(vlSelf->top__DOT__csrrs));
    vlSelf->top__DOT__sll = ((0x33U == (0x7fU & vlSelf->ist)) 
                             & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_39));
    vlSelf->top__DOT__slli = ((0x13U == (0x7fU & vlSelf->ist)) 
                              & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_39));
    vlSelf->top__DOT__srli = ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_13) 
                              & (0U == (vlSelf->ist 
                                        >> 0x19U)));
    vlSelf->top__DOT__srai = ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_13) 
                              & (0x20U == (vlSelf->ist 
                                           >> 0x19U)));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33 
        = (1U & (((~ (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30)) 
                  & (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                     [0xfU] >> 0x1fU)) | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31) 
                                          & ((0x7fffffffU 
                                              & vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                              [0xfU]) 
                                             < vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32))));
    vlSelf->top__DOT__imm = (((IData)(vlSelf->top__DOT__jalr) 
                              | ((IData)(vlSelf->top__DOT__lb) 
                                 | ((IData)(vlSelf->top__DOT__lh) 
                                    | ((IData)(vlSelf->top__DOT__lw) 
                                       | ((IData)(vlSelf->top__DOT__lbu) 
                                          | ((IData)(vlSelf->top__DOT__lhu) 
                                             | ((IData)(vlSelf->top__DOT__addi) 
                                                | ((IData)(vlSelf->top__DOT__slti) 
                                                   | ((IData)(vlSelf->top__DOT__sltiu) 
                                                      | ((IData)(vlSelf->top__DOT__xori) 
                                                         | ((IData)(vlSelf->top__DOT__ori) 
                                                            | ((IData)(vlSelf->top__DOT__andi) 
                                                               | ((IData)(vlSelf->top__DOT__srli) 
                                                                  | ((IData)(vlSelf->top__DOT__slli) 
                                                                     | ((IData)(vlSelf->top__DOT__srai) 
                                                                        | (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_37))))))))))))))))
                              ? (((- (IData)((vlSelf->ist 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelf->ist 
                                              >> 0x14U))
                              : (((0x17U == (0x7fU 
                                             & vlSelf->ist)) 
                                  | (0x37U == (0x7fU 
                                               & vlSelf->ist)))
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
                                      : ((IData)(vlSelf->mem_wen_dg)
                                          ? (((- (IData)(
                                                         (vlSelf->ist 
                                                          >> 0x1fU))) 
                                              << 0xcU) 
                                             | ((0xfe0U 
                                                 & (vlSelf->ist 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSelf->ist 
                                                      >> 7U))))
                                          : (((IData)(vlSelf->top__DOT__beq) 
                                              | ((IData)(vlSelf->top__DOT__bne) 
                                                 | ((IData)(vlSelf->top__DOT__blt) 
                                                    | ((IData)(vlSelf->top__DOT__bge) 
                                                       | ((IData)(vlSelf->top__DOT__bltu) 
                                                          | (IData)(vlSelf->top__DOT__bgeu))))))
                                              ? (((- (IData)(
                                                             (vlSelf->ist 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0x800U 
                                                     & (vlSelf->ist 
                                                        >> 0x14U)) 
                                                    | ((0x400U 
                                                        & (vlSelf->ist 
                                                           << 3U)) 
                                                       | ((0x3f0U 
                                                           & (vlSelf->ist 
                                                              >> 0x15U)) 
                                                          | (0xfU 
                                                             & (vlSelf->ist 
                                                                >> 8U))))))
                                              : 0U)))));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_38 
        = (vlSelf->pc + VL_SHIFTL_III(32,32,32, vlSelf->top__DOT__imm, 1U));
    vlSelf->top__DOT__csr_sel = ((0x341U == vlSelf->top__DOT__imm)
                                  ? vlSelf->top__DOT__mepc
                                  : ((0x342U == vlSelf->top__DOT__imm)
                                      ? vlSelf->top__DOT__mcause
                                      : ((0x300U == vlSelf->top__DOT__imm)
                                          ? vlSelf->top__DOT__mstatus
                                          : ((0x305U 
                                              == vlSelf->top__DOT__imm)
                                              ? vlSelf->top__DOT__mtvec
                                              : 0U))));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_21 
        = (vlSelf->pc + vlSelf->top__DOT__imm);
    vlSelf->top__DOT__mem_waddr = (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                   [0xfU] + vlSelf->top__DOT__imm);
    vlSelf->mem_raddr = ((IData)(vlSelf->top__DOT__lb)
                          ? vlSelf->top__DOT__mem_waddr
                          : ((IData)(vlSelf->top__DOT__lbu)
                              ? vlSelf->top__DOT__mem_waddr
                              : ((IData)(vlSelf->top__DOT__lh)
                                  ? vlSelf->top__DOT__mem_waddr
                                  : ((IData)(vlSelf->top__DOT__lhu)
                                      ? vlSelf->top__DOT__mem_waddr
                                      : ((IData)(vlSelf->top__DOT__lw)
                                          ? vlSelf->top__DOT__mem_waddr
                                          : 0U)))));
    Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ftrace__DOT__ftrace_update_TOP(
                                                                                ((IData)(vlSelf->top__DOT__jalr)
                                                                                 ? 
                                                                                (0xfffffffeU 
                                                                                & vlSelf->top__DOT__mem_waddr)
                                                                                 : 
                                                                                ((0x6fU 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlSelf->ist))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_21
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__beq) 
                                                                                & (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xfU] 
                                                                                == vlSelf->top__DOT__rf_rdata2))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_38
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bne) 
                                                                                & (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xfU] 
                                                                                != vlSelf->top__DOT__rf_rdata2))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_38
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__blt) 
                                                                                & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_38
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bltu) 
                                                                                & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_38
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bge) 
                                                                                & (((~ 
                                                                                (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xfU] 
                                                                                >> 0x1fU)) 
                                                                                & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30)) 
                                                                                | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31) 
                                                                                & ((0x7fffffffU 
                                                                                & vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xfU]) 
                                                                                >= vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32))))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_38
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bgeu) 
                                                                                & (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xfU] 
                                                                                >= vlSelf->top__DOT__rf_rdata2))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_38
                                                                                 : vlSelf->top__DOT__mepc)))))))), 
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
                                                                                ((IData)(
                                                                                (0x67U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->ist))) 
                                                                                & (1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->ist 
                                                                                >> 7U)))), 
                                                                                ((IData)(
                                                                                (0x67U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->ist))) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                == 
                                                                                (0xfff00f80U 
                                                                                & vlSelf->ist)))));
    vlSelf->top__DOT__rf_wdata = ((0x37U == (0x7fU 
                                             & vlSelf->ist))
                                   ? vlSelf->top__DOT__imm
                                   : ((0x17U == (0x7fU 
                                                 & vlSelf->ist))
                                       ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_21
                                       : ((0x6fU == 
                                           (0x7fU & vlSelf->ist))
                                           ? ((IData)(4U) 
                                              + vlSelf->pc)
                                           : ((IData)(vlSelf->top__DOT__jalr)
                                               ? ((IData)(4U) 
                                                  + vlSelf->pc)
                                               : ((IData)(vlSelf->top__DOT__lb)
                                                   ? 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelf->top__DOT__rdata_mem 
                                                                   >> 7U)))) 
                                                    << 8U) 
                                                   | (0xffU 
                                                      & vlSelf->top__DOT__rdata_mem))
                                                   : 
                                                  ((IData)(vlSelf->top__DOT__lh)
                                                    ? 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->top__DOT__rdata_mem 
                                                                    >> 0xfU)))) 
                                                     << 0x10U) 
                                                    | (0xffffU 
                                                       & vlSelf->top__DOT__rdata_mem))
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__lw)
                                                     ? vlSelf->top__DOT__rdata_mem
                                                     : 
                                                    ((IData)(vlSelf->top__DOT__lbu)
                                                      ? 
                                                     (0xffU 
                                                      & vlSelf->top__DOT__rdata_mem)
                                                      : 
                                                     ((IData)(vlSelf->top__DOT__lhu)
                                                       ? 
                                                      (0xffffU 
                                                       & vlSelf->top__DOT__rdata_mem)
                                                       : 
                                                      ((IData)(vlSelf->top__DOT__addi)
                                                        ? vlSelf->top__DOT__mem_waddr
                                                        : 
                                                       (((IData)(vlSelf->top__DOT__slti) 
                                                         & (((~ 
                                                              (vlSelf->top__DOT__imm 
                                                               >> 0x1fU)) 
                                                             & (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                [0xfU] 
                                                                >> 0x1fU)) 
                                                            | (((vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                 [0xfU] 
                                                                 >> 0x1fU) 
                                                                == 
                                                                (vlSelf->top__DOT__imm 
                                                                 >> 0x1fU)) 
                                                               & ((0x7fffffffU 
                                                                   & vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                   [0xfU]) 
                                                                  < 
                                                                  (0x7fffffffU 
                                                                   & vlSelf->top__DOT__imm)))))
                                                         ? 1U
                                                         : 
                                                        (((IData)(vlSelf->top__DOT__sltiu) 
                                                          & (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                             [0xfU] 
                                                             < vlSelf->top__DOT__imm))
                                                          ? 1U
                                                          : 
                                                         ((IData)(vlSelf->top__DOT__xori)
                                                           ? 
                                                          (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                           [0xfU] 
                                                           ^ vlSelf->top__DOT__imm)
                                                           : 
                                                          ((IData)(vlSelf->top__DOT__ori)
                                                            ? 
                                                           (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                            [0xfU] 
                                                            | vlSelf->top__DOT__imm)
                                                            : 
                                                           ((IData)(vlSelf->top__DOT__andi)
                                                             ? 
                                                            (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                             [0xfU] 
                                                             & vlSelf->top__DOT__imm)
                                                             : 
                                                            ((IData)(vlSelf->top__DOT__slli)
                                                              ? 
                                                             VL_SHIFTL_III(32,32,32, 
                                                                           vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                           [0xfU], vlSelf->top__DOT__imm)
                                                              : 
                                                             ((IData)(vlSelf->top__DOT__srli)
                                                               ? 
                                                              VL_SHIFTR_III(32,32,32, 
                                                                            vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                            [0xfU], vlSelf->top__DOT__imm)
                                                               : 
                                                              ((IData)(vlSelf->top__DOT__srai)
                                                                ? 
                                                               (VL_SHIFTL_III(32,32,6, 
                                                                              (- (IData)(
                                                                                (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xfU] 
                                                                                >> 0x1fU))), 
                                                                              (0x3fU 
                                                                               & ((IData)(0x20U) 
                                                                                - 
                                                                                (0x1fU 
                                                                                & vlSelf->top__DOT__imm)))) 
                                                                | (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                   [0xfU] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & vlSelf->top__DOT__imm)))
                                                                : 
                                                               ((IData)(vlSelf->top__DOT__add)
                                                                 ? 
                                                                (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                 [0xfU] 
                                                                 + vlSelf->top__DOT__rf_rdata2)
                                                                 : 
                                                                ((IData)(vlSelf->top__DOT__sub)
                                                                  ? 
                                                                 (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                  [0xfU] 
                                                                  - vlSelf->top__DOT__rf_rdata2)
                                                                  : 
                                                                 ((IData)(vlSelf->top__DOT__sll)
                                                                   ? 
                                                                  VL_SHIFTL_III(32,32,32, 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xfU], vlSelf->top__DOT__rf_rdata2)
                                                                   : 
                                                                  (((IData)(vlSelf->top__DOT__slt) 
                                                                    & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33))
                                                                    ? 1U
                                                                    : 
                                                                   (((IData)(vlSelf->top__DOT__sltu) 
                                                                     & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34))
                                                                     ? 1U
                                                                     : 
                                                                    ((IData)(vlSelf->top__DOT__xorr)
                                                                      ? 
                                                                     (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                      [0xfU] 
                                                                      ^ vlSelf->top__DOT__rf_rdata2)
                                                                      : 
                                                                     ((IData)(vlSelf->top__DOT__srl)
                                                                       ? 
                                                                      VL_SHIFTR_III(32,32,32, 
                                                                                vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xfU], vlSelf->top__DOT__rf_rdata2)
                                                                       : 
                                                                      ((IData)(vlSelf->top__DOT__sra)
                                                                        ? 
                                                                       (VL_SHIFTL_III(32,32,6, 
                                                                                (- (IData)(
                                                                                (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                                [0xfU] 
                                                                                >> 0x1fU))), 
                                                                                (0x3fU 
                                                                                & ((IData)(0x20U) 
                                                                                - (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35)))) 
                                                                        | (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                           [0xfU] 
                                                                           >> (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35)))
                                                                        : 
                                                                       ((IData)(vlSelf->top__DOT__orr)
                                                                         ? 
                                                                        (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                         [0xfU] 
                                                                         | vlSelf->top__DOT__rf_rdata2)
                                                                         : 
                                                                        ((IData)(vlSelf->top__DOT__andd)
                                                                          ? 
                                                                         (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                                                          [0xfU] 
                                                                          & vlSelf->top__DOT__rf_rdata2)
                                                                          : 
                                                                         ((IData)(vlSelf->top__DOT__csrrs)
                                                                           ? vlSelf->top__DOT__csr_sel
                                                                           : 
                                                                          ((IData)(vlSelf->top__DOT__csrrw)
                                                                            ? vlSelf->top__DOT__csr_sel
                                                                            : 0U))))))))))))))))))))))))))))));
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
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(negedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(negedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
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
    vlSelf->mem_valid = VL_RAND_RESET_I(1);
    vlSelf->mem_raddr = VL_RAND_RESET_I(32);
    vlSelf->mem_wen_dg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__beq = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__bne = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__blt = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__bge = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__bltu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__bgeu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lb = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lh = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lw = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lhu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sb = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sh = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sw = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__addi = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__slti = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sltiu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xori = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ori = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__andi = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__slli = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__srli = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__srai = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__add = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sub = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sll = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__slt = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sltu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xorr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__srl = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sra = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__orr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__andd = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rdata_mem = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rf_wdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rf_rdata2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csr_sel = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mepc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mtvec = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mcause = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mstatus = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mepc_next = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mtvec_next = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mcause_next = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mstatus_next = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_waddr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csrrw = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__csrrs = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_13 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_16 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_17 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_21 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32 = VL_RAND_RESET_I(31);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_37 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_38 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_39 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__inst_RegisterFile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
