// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+33,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+33,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"imm1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+39,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+40,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+41,0,"addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"rf_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"rf_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"rf_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+39,0,"rf_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+44,0,"rf_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("inst_RegisterFile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+45,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+44,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("inst_dpi_c_ebreak", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+36,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("inst_pc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+46,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+44,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+44,(1U));
    bufp->fullIData(oldp+45,(5U),32);
    bufp->fullIData(oldp+46,(0x20U),32);
    bufp->fullIData(oldp+47,(0x80000000U),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[31]),32);
    bufp->fullBit(oldp+33,(vlSelf->clk));
    bufp->fullBit(oldp+34,(vlSelf->reset));
    bufp->fullIData(oldp+35,(vlSelf->pc),32);
    bufp->fullIData(oldp+36,(vlSelf->ist),32);
    bufp->fullIData(oldp+37,(((IData)(4U) + vlSelf->pc)),32);
    bufp->fullSData(oldp+38,(((IData)(vlSelf->top__DOT__addi)
                               ? (vlSelf->ist >> 0x14U)
                               : 0U)),12);
    bufp->fullCData(oldp+39,(vlSelf->top__DOT__rf_raddr),5);
    bufp->fullCData(oldp+40,(((IData)(vlSelf->top__DOT__addi)
                               ? (0x1fU & (vlSelf->ist 
                                           >> 7U)) : 0U)),5);
    bufp->fullBit(oldp+41,(vlSelf->top__DOT__addi));
    bufp->fullIData(oldp+42,((((0U == (IData)(vlSelf->top__DOT__rf_raddr))
                                ? 0U : vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                               [vlSelf->top__DOT__rf_raddr]) 
                              + (((- (IData)(((IData)(vlSelf->top__DOT__addi) 
                                              & (vlSelf->ist 
                                                 >> 0x1fU)))) 
                                  << 0xcU) | ((IData)(vlSelf->top__DOT__addi)
                                               ? (vlSelf->ist 
                                                  >> 0x14U)
                                               : 0U)))),32);
    bufp->fullIData(oldp+43,(((0U == (IData)(vlSelf->top__DOT__rf_raddr))
                               ? 0U : vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                              [vlSelf->top__DOT__rf_raddr])),32);
}
