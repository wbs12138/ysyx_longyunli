// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

extern "C" void ebreak();

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__inst_dpi_c_ebreak__DOT__ebreak_TOP\n"); );
    // Body
    ebreak();
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
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}
