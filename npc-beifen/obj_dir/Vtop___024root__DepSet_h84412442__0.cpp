// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

extern "C" int npc_pmem_read(int raddr);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__npc_pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &npc_pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__npc_pmem_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int npc_pmem_read__Vfuncrtn__Vcvt;
    npc_pmem_read__Vfuncrtn__Vcvt = npc_pmem_read(raddr__Vcvt);
    npc_pmem_read__Vfuncrtn = npc_pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void npc_pmem_write(int waddr, int wdata, char wmask);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__npc_pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__npc_pmem_write_TOP\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    char wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    npc_pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

extern "C" void regfile_update(int rf1, int rf2, int rf3, int rf4, int rf5, int rf6, int rf7, int rf8, int rf9, int rf10, int rf11, int rf12, int rf13, int rf14, int rf15, int rf16, int rf17, int rf18, int rf19, int rf20, int rf21, int rf22, int rf23, int rf24, int rf25, int rf26, int rf27, int rf28, int rf29, int rf30, int rf31);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__inst_RegisterFile__DOT__regfile_update_TOP(IData/*31:0*/ rf1, IData/*31:0*/ rf2, IData/*31:0*/ rf3, IData/*31:0*/ rf4, IData/*31:0*/ rf5, IData/*31:0*/ rf6, IData/*31:0*/ rf7, IData/*31:0*/ rf8, IData/*31:0*/ rf9, IData/*31:0*/ rf10, IData/*31:0*/ rf11, IData/*31:0*/ rf12, IData/*31:0*/ rf13, IData/*31:0*/ rf14, IData/*31:0*/ rf15, IData/*31:0*/ rf16, IData/*31:0*/ rf17, IData/*31:0*/ rf18, IData/*31:0*/ rf19, IData/*31:0*/ rf20, IData/*31:0*/ rf21, IData/*31:0*/ rf22, IData/*31:0*/ rf23, IData/*31:0*/ rf24, IData/*31:0*/ rf25, IData/*31:0*/ rf26, IData/*31:0*/ rf27, IData/*31:0*/ rf28, IData/*31:0*/ rf29, IData/*31:0*/ rf30, IData/*31:0*/ rf31) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__inst_RegisterFile__DOT__regfile_update_TOP\n"); );
    // Body
    int rf1__Vcvt;
    for (size_t rf1__Vidx = 0; rf1__Vidx < 1; ++rf1__Vidx) rf1__Vcvt = rf1;
    int rf2__Vcvt;
    for (size_t rf2__Vidx = 0; rf2__Vidx < 1; ++rf2__Vidx) rf2__Vcvt = rf2;
    int rf3__Vcvt;
    for (size_t rf3__Vidx = 0; rf3__Vidx < 1; ++rf3__Vidx) rf3__Vcvt = rf3;
    int rf4__Vcvt;
    for (size_t rf4__Vidx = 0; rf4__Vidx < 1; ++rf4__Vidx) rf4__Vcvt = rf4;
    int rf5__Vcvt;
    for (size_t rf5__Vidx = 0; rf5__Vidx < 1; ++rf5__Vidx) rf5__Vcvt = rf5;
    int rf6__Vcvt;
    for (size_t rf6__Vidx = 0; rf6__Vidx < 1; ++rf6__Vidx) rf6__Vcvt = rf6;
    int rf7__Vcvt;
    for (size_t rf7__Vidx = 0; rf7__Vidx < 1; ++rf7__Vidx) rf7__Vcvt = rf7;
    int rf8__Vcvt;
    for (size_t rf8__Vidx = 0; rf8__Vidx < 1; ++rf8__Vidx) rf8__Vcvt = rf8;
    int rf9__Vcvt;
    for (size_t rf9__Vidx = 0; rf9__Vidx < 1; ++rf9__Vidx) rf9__Vcvt = rf9;
    int rf10__Vcvt;
    for (size_t rf10__Vidx = 0; rf10__Vidx < 1; ++rf10__Vidx) rf10__Vcvt = rf10;
    int rf11__Vcvt;
    for (size_t rf11__Vidx = 0; rf11__Vidx < 1; ++rf11__Vidx) rf11__Vcvt = rf11;
    int rf12__Vcvt;
    for (size_t rf12__Vidx = 0; rf12__Vidx < 1; ++rf12__Vidx) rf12__Vcvt = rf12;
    int rf13__Vcvt;
    for (size_t rf13__Vidx = 0; rf13__Vidx < 1; ++rf13__Vidx) rf13__Vcvt = rf13;
    int rf14__Vcvt;
    for (size_t rf14__Vidx = 0; rf14__Vidx < 1; ++rf14__Vidx) rf14__Vcvt = rf14;
    int rf15__Vcvt;
    for (size_t rf15__Vidx = 0; rf15__Vidx < 1; ++rf15__Vidx) rf15__Vcvt = rf15;
    int rf16__Vcvt;
    for (size_t rf16__Vidx = 0; rf16__Vidx < 1; ++rf16__Vidx) rf16__Vcvt = rf16;
    int rf17__Vcvt;
    for (size_t rf17__Vidx = 0; rf17__Vidx < 1; ++rf17__Vidx) rf17__Vcvt = rf17;
    int rf18__Vcvt;
    for (size_t rf18__Vidx = 0; rf18__Vidx < 1; ++rf18__Vidx) rf18__Vcvt = rf18;
    int rf19__Vcvt;
    for (size_t rf19__Vidx = 0; rf19__Vidx < 1; ++rf19__Vidx) rf19__Vcvt = rf19;
    int rf20__Vcvt;
    for (size_t rf20__Vidx = 0; rf20__Vidx < 1; ++rf20__Vidx) rf20__Vcvt = rf20;
    int rf21__Vcvt;
    for (size_t rf21__Vidx = 0; rf21__Vidx < 1; ++rf21__Vidx) rf21__Vcvt = rf21;
    int rf22__Vcvt;
    for (size_t rf22__Vidx = 0; rf22__Vidx < 1; ++rf22__Vidx) rf22__Vcvt = rf22;
    int rf23__Vcvt;
    for (size_t rf23__Vidx = 0; rf23__Vidx < 1; ++rf23__Vidx) rf23__Vcvt = rf23;
    int rf24__Vcvt;
    for (size_t rf24__Vidx = 0; rf24__Vidx < 1; ++rf24__Vidx) rf24__Vcvt = rf24;
    int rf25__Vcvt;
    for (size_t rf25__Vidx = 0; rf25__Vidx < 1; ++rf25__Vidx) rf25__Vcvt = rf25;
    int rf26__Vcvt;
    for (size_t rf26__Vidx = 0; rf26__Vidx < 1; ++rf26__Vidx) rf26__Vcvt = rf26;
    int rf27__Vcvt;
    for (size_t rf27__Vidx = 0; rf27__Vidx < 1; ++rf27__Vidx) rf27__Vcvt = rf27;
    int rf28__Vcvt;
    for (size_t rf28__Vidx = 0; rf28__Vidx < 1; ++rf28__Vidx) rf28__Vcvt = rf28;
    int rf29__Vcvt;
    for (size_t rf29__Vidx = 0; rf29__Vidx < 1; ++rf29__Vidx) rf29__Vcvt = rf29;
    int rf30__Vcvt;
    for (size_t rf30__Vidx = 0; rf30__Vidx < 1; ++rf30__Vidx) rf30__Vcvt = rf30;
    int rf31__Vcvt;
    for (size_t rf31__Vidx = 0; rf31__Vidx < 1; ++rf31__Vidx) rf31__Vcvt = rf31;
    regfile_update(rf1__Vcvt, rf2__Vcvt, rf3__Vcvt, rf4__Vcvt, rf5__Vcvt, rf6__Vcvt, rf7__Vcvt, rf8__Vcvt, rf9__Vcvt, rf10__Vcvt, rf11__Vcvt, rf12__Vcvt, rf13__Vcvt, rf14__Vcvt, rf15__Vcvt, rf16__Vcvt, rf17__Vcvt, rf18__Vcvt, rf19__Vcvt, rf20__Vcvt, rf21__Vcvt, rf22__Vcvt, rf23__Vcvt, rf24__Vcvt, rf25__Vcvt, rf26__Vcvt, rf27__Vcvt, rf28__Vcvt, rf29__Vcvt, rf30__Vcvt, rf31__Vcvt);
}

extern "C" void ebreak(int back_right);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP(IData/*31:0*/ back_right) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP\n"); );
    // Body
    int back_right__Vcvt;
    for (size_t back_right__Vidx = 0; back_right__Vidx < 1; ++back_right__Vidx) back_right__Vcvt = back_right;
    ebreak(back_right__Vcvt);
}

extern "C" void ftrace_update(int dnpc_v, int trace1, int trace2, int trace3, int trace4);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ftrace__DOT__ftrace_update_TOP(IData/*31:0*/ dnpc_v, IData/*31:0*/ trace1, IData/*31:0*/ trace2, IData/*31:0*/ trace3, IData/*31:0*/ trace4) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ftrace__DOT__ftrace_update_TOP\n"); );
    // Body
    int dnpc_v__Vcvt;
    for (size_t dnpc_v__Vidx = 0; dnpc_v__Vidx < 1; ++dnpc_v__Vidx) dnpc_v__Vcvt = dnpc_v;
    int trace1__Vcvt;
    for (size_t trace1__Vidx = 0; trace1__Vidx < 1; ++trace1__Vidx) trace1__Vcvt = trace1;
    int trace2__Vcvt;
    for (size_t trace2__Vidx = 0; trace2__Vidx < 1; ++trace2__Vidx) trace2__Vcvt = trace2;
    int trace3__Vcvt;
    for (size_t trace3__Vidx = 0; trace3__Vidx < 1; ++trace3__Vidx) trace3__Vcvt = trace3;
    int trace4__Vcvt;
    for (size_t trace4__Vidx = 0; trace4__Vidx < 1; ++trace4__Vidx) trace4__Vcvt = trace4;
    ftrace_update(dnpc_v__Vcvt, trace1__Vcvt, trace2__Vcvt, trace3__Vcvt, trace4__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((~ (IData)(vlSelf->clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0)));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}
