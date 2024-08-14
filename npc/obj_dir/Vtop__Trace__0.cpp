// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->top__DOT__jalr));
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__beq));
        bufp->chgBit(oldp+2,(vlSelf->top__DOT__bne));
        bufp->chgBit(oldp+3,(vlSelf->top__DOT__blt));
        bufp->chgBit(oldp+4,(vlSelf->top__DOT__bge));
        bufp->chgBit(oldp+5,(vlSelf->top__DOT__bltu));
        bufp->chgBit(oldp+6,(vlSelf->top__DOT__bgeu));
        bufp->chgBit(oldp+7,(vlSelf->top__DOT__lb));
        bufp->chgBit(oldp+8,(vlSelf->top__DOT__lh));
        bufp->chgBit(oldp+9,(vlSelf->top__DOT__lw));
        bufp->chgBit(oldp+10,(vlSelf->top__DOT__lbu));
        bufp->chgBit(oldp+11,(vlSelf->top__DOT__lhu));
        bufp->chgBit(oldp+12,(vlSelf->top__DOT__sb));
        bufp->chgBit(oldp+13,(vlSelf->top__DOT__sh));
        bufp->chgBit(oldp+14,(vlSelf->top__DOT__sw));
        bufp->chgBit(oldp+15,(vlSelf->top__DOT__addi));
        bufp->chgBit(oldp+16,(vlSelf->top__DOT__slti));
        bufp->chgBit(oldp+17,(vlSelf->top__DOT__sltiu));
        bufp->chgBit(oldp+18,(vlSelf->top__DOT__xori));
        bufp->chgBit(oldp+19,(vlSelf->top__DOT__ori));
        bufp->chgBit(oldp+20,(vlSelf->top__DOT__andi));
        bufp->chgBit(oldp+21,(vlSelf->top__DOT__slli));
        bufp->chgBit(oldp+22,(vlSelf->top__DOT__srli));
        bufp->chgBit(oldp+23,(vlSelf->top__DOT__srai));
        bufp->chgBit(oldp+24,(vlSelf->top__DOT__add));
        bufp->chgBit(oldp+25,(vlSelf->top__DOT__sub));
        bufp->chgBit(oldp+26,(vlSelf->top__DOT__sll));
        bufp->chgBit(oldp+27,(vlSelf->top__DOT__slt));
        bufp->chgBit(oldp+28,(vlSelf->top__DOT__sltu));
        bufp->chgBit(oldp+29,(vlSelf->top__DOT__xorr));
        bufp->chgBit(oldp+30,(vlSelf->top__DOT__srl));
        bufp->chgBit(oldp+31,(vlSelf->top__DOT__sra));
        bufp->chgBit(oldp+32,(vlSelf->top__DOT__orr));
        bufp->chgBit(oldp+33,(vlSelf->top__DOT__andd));
        bufp->chgBit(oldp+34,(((IData)(vlSelf->top__DOT__jalr) 
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
                                                             | (IData)(vlSelf->top__DOT__andi))))))))))))));
        bufp->chgBit(oldp+35,(((IData)(vlSelf->top__DOT__beq) 
                               | ((IData)(vlSelf->top__DOT__bne) 
                                  | ((IData)(vlSelf->top__DOT__blt) 
                                     | ((IData)(vlSelf->top__DOT__bge) 
                                        | ((IData)(vlSelf->top__DOT__bltu) 
                                           | (IData)(vlSelf->top__DOT__bgeu))))))));
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__imm),32);
        bufp->chgCData(oldp+37,(((IData)(vlSelf->top__DOT__sb)
                                  ? 1U : ((IData)(vlSelf->top__DOT__sh)
                                           ? 3U : ((IData)(vlSelf->top__DOT__sw)
                                                    ? 0xfU
                                                    : 0U)))),4);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[0]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[1]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[2]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[3]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[4]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[5]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[6]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[7]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[8]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[9]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[10]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[11]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[12]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[13]),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[14]),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[15]),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[16]),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[17]),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[18]),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[19]),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[20]),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[21]),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[22]),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[23]),32);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[24]),32);
        bufp->chgIData(oldp+63,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[25]),32);
        bufp->chgIData(oldp+64,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[26]),32);
        bufp->chgIData(oldp+65,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[27]),32);
        bufp->chgIData(oldp+66,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[28]),32);
        bufp->chgIData(oldp+67,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[29]),32);
        bufp->chgIData(oldp+68,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[30]),32);
        bufp->chgIData(oldp+69,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+70,(vlSelf->clk));
    bufp->chgBit(oldp+71,(vlSelf->reset));
    bufp->chgIData(oldp+72,(vlSelf->pc),32);
    bufp->chgIData(oldp+73,(vlSelf->ist),32);
    bufp->chgBit(oldp+74,(vlSelf->mem_valid));
    bufp->chgIData(oldp+75,(vlSelf->mem_raddr),32);
    bufp->chgBit(oldp+76,(vlSelf->mem_wen_dg));
    bufp->chgCData(oldp+77,((0x7fU & vlSelf->ist)),7);
    bufp->chgCData(oldp+78,((vlSelf->ist >> 0x19U)),7);
    bufp->chgCData(oldp+79,((7U & (vlSelf->ist >> 0xcU))),3);
    bufp->chgBit(oldp+80,((0x37U == (0x7fU & vlSelf->ist))));
    bufp->chgBit(oldp+81,((0x17U == (0x7fU & vlSelf->ist))));
    bufp->chgBit(oldp+82,((0x6fU == (0x7fU & vlSelf->ist))));
    bufp->chgBit(oldp+83,(((0x17U == (0x7fU & vlSelf->ist)) 
                           | (0x37U == (0x7fU & vlSelf->ist)))));
    bufp->chgCData(oldp+84,((0x1fU & (vlSelf->ist >> 0xfU))),5);
    bufp->chgCData(oldp+85,((0x1fU & (vlSelf->ist >> 0x14U))),5);
    bufp->chgCData(oldp+86,((0x1fU & (vlSelf->ist >> 7U))),5);
    bufp->chgIData(oldp+87,(((IData)(vlSelf->mem_valid)
                              ? vlSelf->top__DOT____VdfgExtracted_h6de86b92__0
                              : 0U)),32);
    bufp->chgIData(oldp+88,(vlSelf->top__DOT__rf_wdata),32);
    bufp->chgIData(oldp+89,(vlSelf->top__DOT__rf_rdata1),32);
    bufp->chgIData(oldp+90,(vlSelf->top__DOT__rf_rdata2),32);
    bufp->chgBit(oldp+91,(((0x37U == (0x7fU & vlSelf->ist)) 
                           | ((0x17U == (0x7fU & vlSelf->ist)) 
                              | ((0x6fU == (0x7fU & vlSelf->ist)) 
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
                                                                                | (IData)(vlSelf->top__DOT__andd))))))))))))))))))))))))))))));
    bufp->chgIData(oldp+92,(((IData)(vlSelf->top__DOT__jalr)
                              ? (0xfffffffeU & vlSelf->top__DOT__mem_waddr)
                              : ((0x6fU == (0x7fU & vlSelf->ist))
                                  ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20
                                  : (((IData)(vlSelf->top__DOT__beq) 
                                      & (vlSelf->top__DOT__rf_rdata1 
                                         == vlSelf->top__DOT__rf_rdata2))
                                      ? VL_SHIFTL_III(32,32,32, vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20, 1U)
                                      : (((IData)(vlSelf->top__DOT__bne) 
                                          & (vlSelf->top__DOT__rf_rdata1 
                                             != vlSelf->top__DOT__rf_rdata2))
                                          ? VL_SHIFTL_III(32,32,32, vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20, 1U)
                                          : (((IData)(vlSelf->top__DOT__blt) 
                                              & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31))
                                              ? VL_SHIFTL_III(32,32,32, vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20, 1U)
                                              : (((IData)(vlSelf->top__DOT__bltu) 
                                                  & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_25))
                                                  ? 
                                                 VL_SHIFTL_III(32,32,32, vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20, 1U)
                                                  : 
                                                 (((IData)(vlSelf->top__DOT__bge) 
                                                   & (((~ (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_22)) 
                                                       & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_28)) 
                                                      | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_29) 
                                                         & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24 
                                                            >= vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30))))
                                                   ? 
                                                  VL_SHIFTL_III(32,32,32, vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20, 1U)
                                                   : 
                                                  (((IData)(vlSelf->top__DOT__bgeu) 
                                                    & (vlSelf->top__DOT__rf_rdata1 
                                                       >= vlSelf->top__DOT__rf_rdata2))
                                                    ? 
                                                   VL_SHIFTL_III(32,32,32, vlSelf->top__DOT____VdfgRegularize_h245778ca_0_20, 1U)
                                                    : 
                                                   ((IData)(4U) 
                                                    + vlSelf->pc)))))))))),32);
    bufp->chgIData(oldp+93,(vlSelf->top__DOT__mem_waddr),32);
    bufp->chgBit(oldp+94,((IData)((0x67U == (0x707fU 
                                             & vlSelf->ist)))));
    bufp->chgIData(oldp+95,(VL_SHIFTR_III(32,32,32, vlSelf->ist, 0x14U)),32);
    bufp->chgBit(oldp+96,((IData)((0xefU == (0xfffU 
                                             & vlSelf->ist)))));
    bufp->chgBit(oldp+97,((0x8067U == vlSelf->ist)));
    bufp->chgBit(oldp+98,((IData)((0xe7U == (0x7fffU 
                                             & vlSelf->ist)))));
    bufp->chgBit(oldp+99,((IData)((0x67U == (0xfff07fffU 
                                             & vlSelf->ist)))));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
