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
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSelf->top__DOT____Vcellinp__inst_pc____pinNumber1));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+1,(((0U == (IData)(vlSelf->top__DOT__inst_RegisterFile__DOT__raddr))
                                 ? 0U : vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                                [vlSelf->top__DOT__rf_wen])),32);
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[0]),32);
        bufp->chgIData(oldp+3,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[1]),32);
        bufp->chgIData(oldp+4,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[2]),32);
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[3]),32);
        bufp->chgIData(oldp+6,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[4]),32);
        bufp->chgIData(oldp+7,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[5]),32);
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[6]),32);
        bufp->chgIData(oldp+9,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[7]),32);
        bufp->chgIData(oldp+10,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[8]),32);
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[9]),32);
        bufp->chgIData(oldp+12,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[10]),32);
        bufp->chgIData(oldp+13,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[11]),32);
        bufp->chgIData(oldp+14,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[12]),32);
        bufp->chgIData(oldp+15,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[13]),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[14]),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[15]),32);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[16]),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[17]),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[18]),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[19]),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[20]),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[21]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[22]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[23]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[24]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[25]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[26]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[27]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[28]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[29]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[30]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+34,(vlSelf->clk));
    bufp->chgBit(oldp+35,(vlSelf->reset));
    bufp->chgIData(oldp+36,(vlSelf->pc),32);
    bufp->chgIData(oldp+37,(vlSelf->ist),32);
    bufp->chgIData(oldp+38,(((IData)(4U) + vlSelf->pc)),32);
    bufp->chgSData(oldp+39,(((IData)(vlSelf->top__DOT__addi)
                              ? (vlSelf->ist >> 0x14U)
                              : 0U)),12);
    bufp->chgCData(oldp+40,(((IData)(vlSelf->top__DOT__addi)
                              ? (0x1fU & (vlSelf->ist 
                                          >> 0xfU))
                              : 0U)),5);
    bufp->chgCData(oldp+41,(((IData)(vlSelf->top__DOT__addi)
                              ? (0x1fU & (vlSelf->ist 
                                          >> 7U)) : 0U)),5);
    bufp->chgBit(oldp+42,(vlSelf->top__DOT__addi));
    bufp->chgIData(oldp+43,((vlSelf->top__DOT__rf_rdata 
                             + (((- (IData)(((IData)(vlSelf->top__DOT__addi) 
                                             & (vlSelf->ist 
                                                >> 0x1fU)))) 
                                 << 0xcU) | ((IData)(vlSelf->top__DOT__addi)
                                              ? (vlSelf->ist 
                                                 >> 0x14U)
                                              : 0U)))),32);
    bufp->chgBit(oldp+44,((1U & (vlSelf->top__DOT__rf_rdata 
                                 + ((IData)(vlSelf->top__DOT__addi)
                                     ? (vlSelf->ist 
                                        >> 0x14U) : 0U)))));
    bufp->chgIData(oldp+45,(((IData)(vlSelf->top__DOT__addi)
                              ? (0x1fU & (vlSelf->ist 
                                          >> 7U)) : 0U)),32);
    bufp->chgBit(oldp+46,((1U & vlSelf->pc)));
    bufp->chgIData(oldp+47,(vlSelf->top__DOT__inst_pc__DOT__dout),32);
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
}
