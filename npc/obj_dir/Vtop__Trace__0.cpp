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
        bufp->chgBit(oldp+0,(vlSelf->top__DOT__addi));
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__jalr));
        bufp->chgBit(oldp+2,(((IData)(vlSelf->top__DOT__addi) 
                              | (IData)(vlSelf->top__DOT__jalr))));
        bufp->chgBit(oldp+3,(vlSelf->top__DOT__inst_u));
        bufp->chgIData(oldp+4,(vlSelf->top__DOT__imm),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[0]),32);
        bufp->chgIData(oldp+6,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[1]),32);
        bufp->chgIData(oldp+7,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[2]),32);
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[3]),32);
        bufp->chgIData(oldp+9,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[4]),32);
        bufp->chgIData(oldp+10,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[5]),32);
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[6]),32);
        bufp->chgIData(oldp+12,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[7]),32);
        bufp->chgIData(oldp+13,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[8]),32);
        bufp->chgIData(oldp+14,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[9]),32);
        bufp->chgIData(oldp+15,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[10]),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[11]),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[12]),32);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[13]),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[14]),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[15]),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[16]),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[17]),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[18]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[19]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[20]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[21]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[22]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[23]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[24]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[25]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[26]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[27]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[28]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[29]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[30]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+37,(vlSelf->clk));
    bufp->chgBit(oldp+38,(vlSelf->reset));
    bufp->chgIData(oldp+39,(vlSelf->pc),32);
    bufp->chgIData(oldp+40,(vlSelf->ist),32);
    bufp->chgIData(oldp+41,(vlSelf->rf0),32);
    bufp->chgIData(oldp+42,(vlSelf->rf1),32);
    bufp->chgIData(oldp+43,(vlSelf->rf2),32);
    bufp->chgIData(oldp+44,(vlSelf->rf3),32);
    bufp->chgIData(oldp+45,(vlSelf->rf4),32);
    bufp->chgIData(oldp+46,(vlSelf->rf5),32);
    bufp->chgIData(oldp+47,(vlSelf->rf6),32);
    bufp->chgIData(oldp+48,(vlSelf->rf7),32);
    bufp->chgIData(oldp+49,(vlSelf->rf8),32);
    bufp->chgIData(oldp+50,(vlSelf->rf9),32);
    bufp->chgIData(oldp+51,(vlSelf->rf10),32);
    bufp->chgIData(oldp+52,(vlSelf->rf11),32);
    bufp->chgIData(oldp+53,(vlSelf->rf12),32);
    bufp->chgIData(oldp+54,(vlSelf->rf13),32);
    bufp->chgIData(oldp+55,(vlSelf->rf14),32);
    bufp->chgIData(oldp+56,(vlSelf->rf15),32);
    bufp->chgIData(oldp+57,(vlSelf->rf16),32);
    bufp->chgIData(oldp+58,(vlSelf->rf17),32);
    bufp->chgIData(oldp+59,(vlSelf->rf18),32);
    bufp->chgIData(oldp+60,(vlSelf->rf19),32);
    bufp->chgIData(oldp+61,(vlSelf->rf20),32);
    bufp->chgIData(oldp+62,(vlSelf->rf21),32);
    bufp->chgIData(oldp+63,(vlSelf->rf22),32);
    bufp->chgIData(oldp+64,(vlSelf->rf23),32);
    bufp->chgIData(oldp+65,(vlSelf->rf24),32);
    bufp->chgIData(oldp+66,(vlSelf->rf25),32);
    bufp->chgIData(oldp+67,(vlSelf->rf26),32);
    bufp->chgIData(oldp+68,(vlSelf->rf27),32);
    bufp->chgIData(oldp+69,(vlSelf->rf28),32);
    bufp->chgIData(oldp+70,(vlSelf->rf29),32);
    bufp->chgIData(oldp+71,(vlSelf->rf30),32);
    bufp->chgIData(oldp+72,(vlSelf->rf31),32);
    bufp->chgBit(oldp+73,((0x6fU == (0x7fU & vlSelf->ist))));
    bufp->chgBit(oldp+74,((0x17U == (0x7fU & vlSelf->ist))));
    bufp->chgBit(oldp+75,((0x37U == (0x7fU & vlSelf->ist))));
    bufp->chgCData(oldp+76,((0x1fU & (vlSelf->ist >> 0xfU))),5);
    bufp->chgCData(oldp+77,((0x1fU & (vlSelf->ist >> 7U))),5);
    bufp->chgIData(oldp+78,(((IData)(vlSelf->top__DOT__addi)
                              ? (vlSelf->top__DOT__rf_rdata 
                                 + (((- (IData)((1U 
                                                 & (vlSelf->top__DOT__imm 
                                                    >> 0xbU)))) 
                                     << 0xcU) | (0xfffU 
                                                 & vlSelf->top__DOT__imm)))
                              : ((0x17U == (0x7fU & vlSelf->ist))
                                  ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3
                                  : ((0x37U == (0x7fU 
                                                & vlSelf->ist))
                                      ? vlSelf->top__DOT__imm
                                      : ((0x6fU == 
                                          (0x7fU & vlSelf->ist))
                                          ? ((IData)(4U) 
                                             + vlSelf->pc)
                                          : ((IData)(vlSelf->top__DOT__jalr)
                                              ? ((IData)(4U) 
                                                 + vlSelf->pc)
                                              : 0U)))))),32);
    bufp->chgIData(oldp+79,(vlSelf->top__DOT__rf_rdata),32);
    bufp->chgBit(oldp+80,(((IData)(vlSelf->top__DOT__addi) 
                           | ((IData)(vlSelf->top__DOT__inst_u) 
                              | ((0x6fU == (0x7fU & vlSelf->ist)) 
                                 | (IData)(vlSelf->top__DOT__jalr))))));
    bufp->chgIData(oldp+81,(((IData)(vlSelf->top__DOT__jalr)
                              ? (0xfffffffeU & (vlSelf->top__DOT__rf_rdata 
                                                + vlSelf->top__DOT__imm))
                              : ((0x6fU == (0x7fU & vlSelf->ist))
                                  ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_3
                                  : ((IData)(4U) + vlSelf->pc)))),32);
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
