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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(mem_valid,0,0);
        VL_OUT8(mem_wen_dg,0,0);
        CData/*0:0*/ top__DOT__jalr;
        CData/*0:0*/ top__DOT__beq;
        CData/*0:0*/ top__DOT__bne;
        CData/*0:0*/ top__DOT__blt;
        CData/*0:0*/ top__DOT__bge;
        CData/*0:0*/ top__DOT__bltu;
        CData/*0:0*/ top__DOT__bgeu;
        CData/*0:0*/ top__DOT__lb;
        CData/*0:0*/ top__DOT__lh;
        CData/*0:0*/ top__DOT__lw;
        CData/*0:0*/ top__DOT__lbu;
        CData/*0:0*/ top__DOT__lhu;
        CData/*0:0*/ top__DOT__sb;
        CData/*0:0*/ top__DOT__sh;
        CData/*0:0*/ top__DOT__sw;
        CData/*0:0*/ top__DOT__addi;
        CData/*0:0*/ top__DOT__slti;
        CData/*0:0*/ top__DOT__sltiu;
        CData/*0:0*/ top__DOT__xori;
        CData/*0:0*/ top__DOT__ori;
        CData/*0:0*/ top__DOT__andi;
        CData/*0:0*/ top__DOT__slli;
        CData/*0:0*/ top__DOT__srli;
        CData/*0:0*/ top__DOT__srai;
        CData/*0:0*/ top__DOT__add;
        CData/*0:0*/ top__DOT__sub;
        CData/*0:0*/ top__DOT__sll;
        CData/*0:0*/ top__DOT__slt;
        CData/*0:0*/ top__DOT__sltu;
        CData/*0:0*/ top__DOT__xorr;
        CData/*0:0*/ top__DOT__srl;
        CData/*0:0*/ top__DOT__sra;
        CData/*0:0*/ top__DOT__orr;
        CData/*0:0*/ top__DOT__andd;
        CData/*0:0*/ top__DOT____VdfgRegularize_h245778ca_0_13;
        CData/*0:0*/ top__DOT____VdfgRegularize_h245778ca_0_16;
        CData/*0:0*/ top__DOT____VdfgRegularize_h245778ca_0_17;
        CData/*0:0*/ top__DOT____VdfgRegularize_h245778ca_0_22;
        CData/*0:0*/ top__DOT____VdfgRegularize_h245778ca_0_25;
        CData/*0:0*/ top__DOT____VdfgRegularize_h245778ca_0_28;
        CData/*0:0*/ top__DOT____VdfgRegularize_h245778ca_0_29;
        CData/*0:0*/ top__DOT____VdfgRegularize_h245778ca_0_31;
        CData/*0:0*/ top__DOT____VdfgRegularize_h245778ca_0_35;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ top__DOT____VdfgRegularize_h245778ca_0_34;
        VL_OUT(pc,31,0);
        VL_IN(ist,31,0);
        VL_OUT(mem_raddr,31,0);
        IData/*31:0*/ top__DOT__imm;
        IData/*31:0*/ top__DOT__rdata_mem;
        IData/*31:0*/ top__DOT__rf_wdata;
        IData/*31:0*/ top__DOT__rf_rdata1;
        IData/*31:0*/ top__DOT__rf_rdata2;
        IData/*31:0*/ top__DOT__pc_next;
        IData/*31:0*/ top__DOT__mem_waddr;
        IData/*31:0*/ top__DOT____VdfgExtracted_h6de86b92__0;
        IData/*31:0*/ top__DOT____VdfgRegularize_h245778ca_0_20;
    };
    struct {
        IData/*30:0*/ top__DOT____VdfgRegularize_h245778ca_0_24;
        IData/*31:0*/ top__DOT____VdfgRegularize_h245778ca_0_26;
        IData/*31:0*/ top__DOT____VdfgRegularize_h245778ca_0_27;
        IData/*30:0*/ top__DOT____VdfgRegularize_h245778ca_0_30;
        IData/*31:0*/ top__DOT____VdfgRegularize_h245778ca_0_32;
        IData/*31:0*/ top__DOT____VdfgRegularize_h245778ca_0_33;
        IData/*31:0*/ __Vfunc_top__DOT__npc_pmem_read__1__Vfuncout;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__inst_RegisterFile__DOT__rf;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
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
