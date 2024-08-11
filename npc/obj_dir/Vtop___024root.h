// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ top__DOT__addi;
    CData/*0:0*/ top__DOT__inst_u;
    CData/*0:0*/ top__DOT__inst_dpi_c_ftrace__DOT__jalr;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(pc,31,0);
    VL_IN(ist,31,0);
    VL_OUT(rf0,31,0);
    VL_OUT(rf1,31,0);
    VL_OUT(rf2,31,0);
    VL_OUT(rf3,31,0);
    VL_OUT(rf4,31,0);
    VL_OUT(rf5,31,0);
    VL_OUT(rf6,31,0);
    VL_OUT(rf7,31,0);
    VL_OUT(rf8,31,0);
    VL_OUT(rf9,31,0);
    VL_OUT(rf10,31,0);
    VL_OUT(rf11,31,0);
    VL_OUT(rf12,31,0);
    VL_OUT(rf13,31,0);
    VL_OUT(rf14,31,0);
    VL_OUT(rf15,31,0);
    VL_OUT(rf16,31,0);
    VL_OUT(rf17,31,0);
    VL_OUT(rf18,31,0);
    VL_OUT(rf19,31,0);
    VL_OUT(rf20,31,0);
    VL_OUT(rf21,31,0);
    VL_OUT(rf22,31,0);
    VL_OUT(rf23,31,0);
    VL_OUT(rf24,31,0);
    VL_OUT(rf25,31,0);
    VL_OUT(rf26,31,0);
    VL_OUT(rf27,31,0);
    VL_OUT(rf28,31,0);
    VL_OUT(rf29,31,0);
    VL_OUT(rf30,31,0);
    VL_OUT(rf31,31,0);
    IData/*31:0*/ top__DOT__imm;
    IData/*31:0*/ top__DOT__rf_rdata;
    IData/*31:0*/ top__DOT__pc_next;
    IData/*31:0*/ top__DOT____VdfgRegularize_h245778ca_0_3;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__inst_RegisterFile__DOT__rf;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
