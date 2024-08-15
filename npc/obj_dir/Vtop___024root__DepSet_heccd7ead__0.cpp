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
void Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ftrace__DOT__ftrace_update_TOP(IData/*31:0*/ dnpc_v, IData/*31:0*/ trace1, IData/*31:0*/ trace2, IData/*31:0*/ trace3, IData/*31:0*/ trace4);

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    if ((0x100073U == vlSelf->ist)) {
        Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP();
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
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34 = 0U;
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32 = 0U;
        vlSelf->top__DOT__rf_rdata2 = 0U;
    } else {
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34 
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
    if ((0U == (0x1fU & (vlSelf->ist >> 0xfU)))) {
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 = 0U;
        vlSelf->top__DOT__rf_rdata1 = 0U;
    } else {
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
            = (0x7fffffffU & vlSelf->top__DOT__inst_RegisterFile__DOT__rf
               [(0x1fU & (vlSelf->ist >> 0xfU))]);
        vlSelf->top__DOT__rf_rdata1 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
            [(0x1fU & (vlSelf->ist >> 0xfU))];
    }
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
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24 
        = ((0U != (0x1fU & (vlSelf->ist >> 0xfU))) 
           & (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
              [(0x1fU & (vlSelf->ist >> 0xfU))] >> 0x1fU));
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
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_36 
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
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27 
        = (vlSelf->top__DOT__rf_rdata1 < vlSelf->top__DOT__rf_rdata2);
    vlSelf->mem_wen_dg = ((IData)(vlSelf->top__DOT__sb) 
                          | ((IData)(vlSelf->top__DOT__sh) 
                             | (IData)(vlSelf->top__DOT__sw)));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31 
        = ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24) 
           == (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30));
    vlSelf->mem_valid = ((IData)(vlSelf->top__DOT__lb) 
                         | ((IData)(vlSelf->top__DOT__lbu) 
                            | ((IData)(vlSelf->top__DOT__lh) 
                               | ((IData)(vlSelf->top__DOT__lhu) 
                                  | (IData)(vlSelf->top__DOT__lw)))));
    vlSelf->top__DOT__sll = ((0x33U == (0x7fU & vlSelf->ist)) 
                             & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_36));
    vlSelf->top__DOT__slli = ((0x13U == (0x7fU & vlSelf->ist)) 
                              & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_36));
    vlSelf->top__DOT__srli = ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_13) 
                              & (0U == (vlSelf->ist 
                                        >> 0x19U)));
    vlSelf->top__DOT__srai = ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_13) 
                              & (0x20U == (vlSelf->ist 
                                           >> 0x19U)));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33 
        = (((~ (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30)) 
            & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24)) 
           | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31) 
              & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
                 < vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32)));
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
                                                                     | (IData)(vlSelf->top__DOT__srai)))))))))))))))
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
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35 
        = (vlSelf->pc + VL_SHIFTL_III(32,32,32, vlSelf->top__DOT__imm, 1U));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20 
        = (vlSelf->pc + vlSelf->top__DOT__imm);
    vlSelf->top__DOT__mem_waddr = (vlSelf->top__DOT__rf_rdata1 
                                   + vlSelf->top__DOT__imm);
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
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__beq) 
                                                                                & (vlSelf->top__DOT__rf_rdata1 
                                                                                == vlSelf->top__DOT__rf_rdata2))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bne) 
                                                                                & (vlSelf->top__DOT__rf_rdata1 
                                                                                != vlSelf->top__DOT__rf_rdata2))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__blt) 
                                                                                & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bltu) 
                                                                                & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bge) 
                                                                                & (((~ (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24)) 
                                                                                & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30)) 
                                                                                | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31) 
                                                                                & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
                                                                                >= vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32))))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bgeu) 
                                                                                & (vlSelf->top__DOT__rf_rdata1 
                                                                                >= vlSelf->top__DOT__rf_rdata2))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->pc))))))))), 
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
    vlSelf->top__DOT__pc_next = ((IData)(vlSelf->top__DOT__jalr)
                                  ? (0xfffffffeU & vlSelf->top__DOT__mem_waddr)
                                  : ((0x6fU == (0x7fU 
                                                & vlSelf->ist))
                                      ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20
                                      : (((IData)(vlSelf->top__DOT__beq) 
                                          & (vlSelf->top__DOT__rf_rdata1 
                                             == vlSelf->top__DOT__rf_rdata2))
                                          ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                          : (((IData)(vlSelf->top__DOT__bne) 
                                              & (vlSelf->top__DOT__rf_rdata1 
                                                 != vlSelf->top__DOT__rf_rdata2))
                                              ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                              : (((IData)(vlSelf->top__DOT__blt) 
                                                  & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33))
                                                  ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                  : 
                                                 (((IData)(vlSelf->top__DOT__bltu) 
                                                   & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27))
                                                   ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                   : 
                                                  (((IData)(vlSelf->top__DOT__bge) 
                                                    & (((~ (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24)) 
                                                        & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30)) 
                                                       | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31) 
                                                          & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
                                                             >= vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32))))
                                                    ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                    : 
                                                   (((IData)(vlSelf->top__DOT__bgeu) 
                                                     & (vlSelf->top__DOT__rf_rdata1 
                                                        >= vlSelf->top__DOT__rf_rdata2))
                                                     ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelf->pc)))))))));
    vlSelf->top__DOT__rf_wdata = ((0x37U == (0x7fU 
                                             & vlSelf->ist))
                                   ? vlSelf->top__DOT__imm
                                   : ((0x17U == (0x7fU 
                                                 & vlSelf->ist))
                                       ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20
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
                                                             & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24)) 
                                                            | (((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24) 
                                                                == 
                                                                (vlSelf->top__DOT__imm 
                                                                 >> 0x1fU)) 
                                                               & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
                                                                  < 
                                                                  (0x7fffffffU 
                                                                   & vlSelf->top__DOT__imm)))))
                                                         ? 1U
                                                         : 
                                                        (((IData)(vlSelf->top__DOT__sltiu) 
                                                          & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27))
                                                          ? 1U
                                                          : 
                                                         ((IData)(vlSelf->top__DOT__xori)
                                                           ? 
                                                          (vlSelf->top__DOT__rf_rdata1 
                                                           ^ vlSelf->top__DOT__imm)
                                                           : 
                                                          ((IData)(vlSelf->top__DOT__ori)
                                                            ? 
                                                           (vlSelf->top__DOT__rf_rdata1 
                                                            | vlSelf->top__DOT__imm)
                                                            : 
                                                           ((IData)(vlSelf->top__DOT__andi)
                                                             ? 
                                                            (vlSelf->top__DOT__rf_rdata1 
                                                             & vlSelf->top__DOT__imm)
                                                             : 
                                                            ((IData)(vlSelf->top__DOT__slli)
                                                              ? 
                                                             VL_SHIFTL_III(32,32,32, vlSelf->top__DOT__rf_rdata1, vlSelf->top__DOT__imm)
                                                              : 
                                                             ((IData)(vlSelf->top__DOT__srli)
                                                               ? 
                                                              VL_SHIFTR_III(32,32,32, vlSelf->top__DOT__rf_rdata1, vlSelf->top__DOT__imm)
                                                               : 
                                                              ((IData)(vlSelf->top__DOT__srai)
                                                                ? 
                                                               (VL_SHIFTL_III(32,32,6, 
                                                                              (- (IData)((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24))), 
                                                                              (0x3fU 
                                                                               & ((IData)(0x20U) 
                                                                                - 
                                                                                (0x1fU 
                                                                                & vlSelf->top__DOT__imm)))) 
                                                                | (vlSelf->top__DOT__rf_rdata1 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & vlSelf->top__DOT__imm)))
                                                                : 
                                                               ((IData)(vlSelf->top__DOT__add)
                                                                 ? 
                                                                (vlSelf->top__DOT__rf_rdata1 
                                                                 + vlSelf->top__DOT__rf_rdata2)
                                                                 : 
                                                                ((IData)(vlSelf->top__DOT__sub)
                                                                  ? 
                                                                 (vlSelf->top__DOT__rf_rdata1 
                                                                  - vlSelf->top__DOT__rf_rdata2)
                                                                  : 
                                                                 ((IData)(vlSelf->top__DOT__sll)
                                                                   ? 
                                                                  VL_SHIFTL_III(32,32,32, vlSelf->top__DOT__rf_rdata1, vlSelf->top__DOT__rf_rdata2)
                                                                   : 
                                                                  (((IData)(vlSelf->top__DOT__slt) 
                                                                    & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33))
                                                                    ? 1U
                                                                    : 
                                                                   (((IData)(vlSelf->top__DOT__sltu) 
                                                                     & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27))
                                                                     ? 1U
                                                                     : 
                                                                    ((IData)(vlSelf->top__DOT__xorr)
                                                                      ? 
                                                                     (vlSelf->top__DOT__rf_rdata1 
                                                                      ^ vlSelf->top__DOT__rf_rdata2)
                                                                      : 
                                                                     ((IData)(vlSelf->top__DOT__srl)
                                                                       ? 
                                                                      VL_SHIFTR_III(32,32,32, vlSelf->top__DOT__rf_rdata1, vlSelf->top__DOT__rf_rdata2)
                                                                       : 
                                                                      ((IData)(vlSelf->top__DOT__sra)
                                                                        ? 
                                                                       (VL_SHIFTL_III(32,32,6, 
                                                                                (- (IData)((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24))), 
                                                                                (0x3fU 
                                                                                & ((IData)(0x20U) 
                                                                                - (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34)))) 
                                                                        | (vlSelf->top__DOT__rf_rdata1 
                                                                           >> (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34)))
                                                                        : 
                                                                       ((IData)(vlSelf->top__DOT__orr)
                                                                         ? 
                                                                        (vlSelf->top__DOT__rf_rdata1 
                                                                         | vlSelf->top__DOT__rf_rdata2)
                                                                         : 
                                                                        ((IData)(vlSelf->top__DOT__andd)
                                                                          ? 
                                                                         (vlSelf->top__DOT__rf_rdata1 
                                                                          & vlSelf->top__DOT__rf_rdata2)
                                                                          : 0U))))))))))))))))))))))))))));
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
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vtop___024root____Vdpiimwrap_top__DOT__npc_pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);
void Vtop___024root____Vdpiimwrap_top__DOT__inst_RegisterFile__DOT__regfile_update_TOP(IData/*31:0*/ rf1, IData/*31:0*/ rf2, IData/*31:0*/ rf3, IData/*31:0*/ rf4, IData/*31:0*/ rf5, IData/*31:0*/ rf6, IData/*31:0*/ rf7, IData/*31:0*/ rf8, IData/*31:0*/ rf9, IData/*31:0*/ rf10, IData/*31:0*/ rf11, IData/*31:0*/ rf12, IData/*31:0*/ rf13, IData/*31:0*/ rf14, IData/*31:0*/ rf15, IData/*31:0*/ rf16, IData/*31:0*/ rf17, IData/*31:0*/ rf18, IData/*31:0*/ rf19, IData/*31:0*/ rf20, IData/*31:0*/ rf21, IData/*31:0*/ rf22, IData/*31:0*/ rf23, IData/*31:0*/ rf24, IData/*31:0*/ rf25, IData/*31:0*/ rf26, IData/*31:0*/ rf27, IData/*31:0*/ rf28, IData/*31:0*/ rf29, IData/*31:0*/ rf30, IData/*31:0*/ rf31);

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
    if (vlSelf->mem_wen_dg) {
        Vtop___024root____Vdpiimwrap_top__DOT__npc_pmem_write_TOP(vlSelf->top__DOT__mem_waddr, vlSelf->top__DOT__rf_rdata2, 
                                                                  ((IData)(vlSelf->top__DOT__sb)
                                                                    ? 1U
                                                                    : 
                                                                   ((IData)(vlSelf->top__DOT__sh)
                                                                     ? 3U
                                                                     : 
                                                                    ((IData)(vlSelf->top__DOT__sw)
                                                                      ? 0xfU
                                                                      : 0U))));
    }
    __VdlySet__top__DOT__inst_RegisterFile__DOT__rf__v0 = 0U;
    if (((0x37U == (0x7fU & vlSelf->ist)) | ((0x17U 
                                              == (0x7fU 
                                                  & vlSelf->ist)) 
                                             | ((0x6fU 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->ist)) 
                                                | ((IData)(vlSelf->top__DOT__jalr) 
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
                                                                                | ((IData)(vlSelf->top__DOT__slli) 
                                                                                | ((IData)(vlSelf->top__DOT__srli) 
                                                                                | ((IData)(vlSelf->top__DOT__srai) 
                                                                                | ((IData)(vlSelf->top__DOT__add) 
                                                                                | ((IData)(vlSelf->top__DOT__sub) 
                                                                                | ((IData)(vlSelf->top__DOT__sll) 
                                                                                | ((IData)(vlSelf->top__DOT__slt) 
                                                                                | ((IData)(vlSelf->top__DOT__sltu) 
                                                                                | ((IData)(vlSelf->top__DOT__xorr) 
                                                                                | ((IData)(vlSelf->top__DOT__srl) 
                                                                                | ((IData)(vlSelf->top__DOT__sra) 
                                                                                | ((IData)(vlSelf->top__DOT__orr) 
                                                                                | (IData)(vlSelf->top__DOT__andd))))))))))))))))))))))))))))) {
        __VdlyVal__top__DOT__inst_RegisterFile__DOT__rf__v0 
            = vlSelf->top__DOT__rf_wdata;
        __VdlyDim0__top__DOT__inst_RegisterFile__DOT__rf__v0 
            = (0x1fU & (vlSelf->ist >> 7U));
        __VdlySet__top__DOT__inst_RegisterFile__DOT__rf__v0 = 1U;
    }
    vlSelf->pc = ((IData)(vlSelf->reset) ? 0x80000000U
                   : vlSelf->top__DOT__pc_next);
    if (__VdlySet__top__DOT__inst_RegisterFile__DOT__rf__v0) {
        vlSelf->top__DOT__inst_RegisterFile__DOT__rf[__VdlyDim0__top__DOT__inst_RegisterFile__DOT__rf__v0] 
            = __VdlyVal__top__DOT__inst_RegisterFile__DOT__rf__v0;
    }
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
    if ((0U == (0x1fU & (vlSelf->ist >> 0x14U)))) {
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34 = 0U;
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32 = 0U;
        vlSelf->top__DOT__rf_rdata2 = 0U;
    } else {
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34 
            = (0x1fU & vlSelf->top__DOT__inst_RegisterFile__DOT__rf
               [(0x1fU & (vlSelf->ist >> 0x14U))]);
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32 
            = (0x7fffffffU & vlSelf->top__DOT__inst_RegisterFile__DOT__rf
               [(0x1fU & (vlSelf->ist >> 0x14U))]);
        vlSelf->top__DOT__rf_rdata2 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
            [(0x1fU & (vlSelf->ist >> 0x14U))];
    }
    if ((0U == (0x1fU & (vlSelf->ist >> 0xfU)))) {
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 = 0U;
        vlSelf->top__DOT__rf_rdata1 = 0U;
    } else {
        vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
            = (0x7fffffffU & vlSelf->top__DOT__inst_RegisterFile__DOT__rf
               [(0x1fU & (vlSelf->ist >> 0xfU))]);
        vlSelf->top__DOT__rf_rdata1 = vlSelf->top__DOT__inst_RegisterFile__DOT__rf
            [(0x1fU & (vlSelf->ist >> 0xfU))];
    }
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30 
        = ((0U != (0x1fU & (vlSelf->ist >> 0x14U))) 
           & (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
              [(0x1fU & (vlSelf->ist >> 0x14U))] >> 0x1fU));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24 
        = ((0U != (0x1fU & (vlSelf->ist >> 0xfU))) 
           & (vlSelf->top__DOT__inst_RegisterFile__DOT__rf
              [(0x1fU & (vlSelf->ist >> 0xfU))] >> 0x1fU));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35 
        = (vlSelf->pc + VL_SHIFTL_III(32,32,32, vlSelf->top__DOT__imm, 1U));
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20 
        = (vlSelf->pc + vlSelf->top__DOT__imm);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27 
        = (vlSelf->top__DOT__rf_rdata1 < vlSelf->top__DOT__rf_rdata2);
    vlSelf->top__DOT__mem_waddr = (vlSelf->top__DOT__rf_rdata1 
                                   + vlSelf->top__DOT__imm);
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31 
        = ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24) 
           == (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30));
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
    vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33 
        = (((~ (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30)) 
            & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24)) 
           | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31) 
              & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
                 < vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32)));
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
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__beq) 
                                                                                & (vlSelf->top__DOT__rf_rdata1 
                                                                                == vlSelf->top__DOT__rf_rdata2))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bne) 
                                                                                & (vlSelf->top__DOT__rf_rdata1 
                                                                                != vlSelf->top__DOT__rf_rdata2))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__blt) 
                                                                                & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bltu) 
                                                                                & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bge) 
                                                                                & (((~ (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24)) 
                                                                                & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30)) 
                                                                                | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31) 
                                                                                & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
                                                                                >= vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32))))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                (((IData)(vlSelf->top__DOT__bgeu) 
                                                                                & (vlSelf->top__DOT__rf_rdata1 
                                                                                >= vlSelf->top__DOT__rf_rdata2))
                                                                                 ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                                                 : 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->pc))))))))), 
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
    vlSelf->top__DOT__pc_next = ((IData)(vlSelf->top__DOT__jalr)
                                  ? (0xfffffffeU & vlSelf->top__DOT__mem_waddr)
                                  : ((0x6fU == (0x7fU 
                                                & vlSelf->ist))
                                      ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20
                                      : (((IData)(vlSelf->top__DOT__beq) 
                                          & (vlSelf->top__DOT__rf_rdata1 
                                             == vlSelf->top__DOT__rf_rdata2))
                                          ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                          : (((IData)(vlSelf->top__DOT__bne) 
                                              & (vlSelf->top__DOT__rf_rdata1 
                                                 != vlSelf->top__DOT__rf_rdata2))
                                              ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                              : (((IData)(vlSelf->top__DOT__blt) 
                                                  & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33))
                                                  ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                  : 
                                                 (((IData)(vlSelf->top__DOT__bltu) 
                                                   & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27))
                                                   ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                   : 
                                                  (((IData)(vlSelf->top__DOT__bge) 
                                                    & (((~ (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24)) 
                                                        & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30)) 
                                                       | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31) 
                                                          & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
                                                             >= vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32))))
                                                    ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                    : 
                                                   (((IData)(vlSelf->top__DOT__bgeu) 
                                                     & (vlSelf->top__DOT__rf_rdata1 
                                                        >= vlSelf->top__DOT__rf_rdata2))
                                                     ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelf->pc)))))))));
}

void Vtop___024root____Vdpiimwrap_top__DOT__npc_pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &npc_pmem_read__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ __Vfunc_top__DOT__npc_pmem_read__0__Vfuncout;
    __Vfunc_top__DOT__npc_pmem_read__0__Vfuncout = 0;
    // Body
    if (vlSelf->mem_valid) {
        Vtop___024root____Vdpiimwrap_top__DOT__npc_pmem_read_TOP(vlSelf->mem_raddr, __Vfunc_top__DOT__npc_pmem_read__0__Vfuncout);
        vlSelf->top__DOT__rdata_mem = __Vfunc_top__DOT__npc_pmem_read__0__Vfuncout;
    } else {
        vlSelf->top__DOT__rdata_mem = 0U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__rf_wdata = ((0x37U == (0x7fU 
                                             & vlSelf->ist))
                                   ? vlSelf->top__DOT__imm
                                   : ((0x17U == (0x7fU 
                                                 & vlSelf->ist))
                                       ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20
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
                                                             & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24)) 
                                                            | (((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24) 
                                                                == 
                                                                (vlSelf->top__DOT__imm 
                                                                 >> 0x1fU)) 
                                                               & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
                                                                  < 
                                                                  (0x7fffffffU 
                                                                   & vlSelf->top__DOT__imm)))))
                                                         ? 1U
                                                         : 
                                                        (((IData)(vlSelf->top__DOT__sltiu) 
                                                          & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27))
                                                          ? 1U
                                                          : 
                                                         ((IData)(vlSelf->top__DOT__xori)
                                                           ? 
                                                          (vlSelf->top__DOT__rf_rdata1 
                                                           ^ vlSelf->top__DOT__imm)
                                                           : 
                                                          ((IData)(vlSelf->top__DOT__ori)
                                                            ? 
                                                           (vlSelf->top__DOT__rf_rdata1 
                                                            | vlSelf->top__DOT__imm)
                                                            : 
                                                           ((IData)(vlSelf->top__DOT__andi)
                                                             ? 
                                                            (vlSelf->top__DOT__rf_rdata1 
                                                             & vlSelf->top__DOT__imm)
                                                             : 
                                                            ((IData)(vlSelf->top__DOT__slli)
                                                              ? 
                                                             VL_SHIFTL_III(32,32,32, vlSelf->top__DOT__rf_rdata1, vlSelf->top__DOT__imm)
                                                              : 
                                                             ((IData)(vlSelf->top__DOT__srli)
                                                               ? 
                                                              VL_SHIFTR_III(32,32,32, vlSelf->top__DOT__rf_rdata1, vlSelf->top__DOT__imm)
                                                               : 
                                                              ((IData)(vlSelf->top__DOT__srai)
                                                                ? 
                                                               (VL_SHIFTL_III(32,32,6, 
                                                                              (- (IData)((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24))), 
                                                                              (0x3fU 
                                                                               & ((IData)(0x20U) 
                                                                                - 
                                                                                (0x1fU 
                                                                                & vlSelf->top__DOT__imm)))) 
                                                                | (vlSelf->top__DOT__rf_rdata1 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & vlSelf->top__DOT__imm)))
                                                                : 
                                                               ((IData)(vlSelf->top__DOT__add)
                                                                 ? 
                                                                (vlSelf->top__DOT__rf_rdata1 
                                                                 + vlSelf->top__DOT__rf_rdata2)
                                                                 : 
                                                                ((IData)(vlSelf->top__DOT__sub)
                                                                  ? 
                                                                 (vlSelf->top__DOT__rf_rdata1 
                                                                  - vlSelf->top__DOT__rf_rdata2)
                                                                  : 
                                                                 ((IData)(vlSelf->top__DOT__sll)
                                                                   ? 
                                                                  VL_SHIFTL_III(32,32,32, vlSelf->top__DOT__rf_rdata1, vlSelf->top__DOT__rf_rdata2)
                                                                   : 
                                                                  (((IData)(vlSelf->top__DOT__slt) 
                                                                    & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33))
                                                                    ? 1U
                                                                    : 
                                                                   (((IData)(vlSelf->top__DOT__sltu) 
                                                                     & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27))
                                                                     ? 1U
                                                                     : 
                                                                    ((IData)(vlSelf->top__DOT__xorr)
                                                                      ? 
                                                                     (vlSelf->top__DOT__rf_rdata1 
                                                                      ^ vlSelf->top__DOT__rf_rdata2)
                                                                      : 
                                                                     ((IData)(vlSelf->top__DOT__srl)
                                                                       ? 
                                                                      VL_SHIFTR_III(32,32,32, vlSelf->top__DOT__rf_rdata1, vlSelf->top__DOT__rf_rdata2)
                                                                       : 
                                                                      ((IData)(vlSelf->top__DOT__sra)
                                                                        ? 
                                                                       (VL_SHIFTL_III(32,32,6, 
                                                                                (- (IData)((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24))), 
                                                                                (0x3fU 
                                                                                & ((IData)(0x20U) 
                                                                                - (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34)))) 
                                                                        | (vlSelf->top__DOT__rf_rdata1 
                                                                           >> (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34)))
                                                                        : 
                                                                       ((IData)(vlSelf->top__DOT__orr)
                                                                         ? 
                                                                        (vlSelf->top__DOT__rf_rdata1 
                                                                         | vlSelf->top__DOT__rf_rdata2)
                                                                         : 
                                                                        ((IData)(vlSelf->top__DOT__andd)
                                                                          ? 
                                                                         (vlSelf->top__DOT__rf_rdata1 
                                                                          & vlSelf->top__DOT__rf_rdata2)
                                                                          : 0U))))))))))))))))))))))))))));
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
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
