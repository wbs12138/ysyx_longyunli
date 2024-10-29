// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "VysyxSoCFull__pch.h"
#include "VysyxSoCFull__Syms.h"
#include "VysyxSoCFull___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VysyxSoCFull___024root___dump_triggers__stl(VysyxSoCFull___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VysyxSoCFull___024root___eval_triggers__stl(VysyxSoCFull___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
    vlSelf->__VstlTriggered.set(1U, ((((((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                             != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r__0)) 
                                            | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0) 
                                               != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0__0))) 
                                           | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel) 
                                              != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel__0))) 
                                          | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                                             != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6__0))) 
                                         | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                                            != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3__0))) 
                                        | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                                           != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4__0))) 
                                       | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                                          != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5__0))) 
                                      | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1) 
                                         != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1__0))) 
                                     | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                                        != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2__0))));
    vlSelf->__VstlTriggered.set(2U, ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid__0)));
    vlSelf->__VstlTriggered.set(3U, (((((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0) 
                                            != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0__0)) 
                                           | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel) 
                                              != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel__0))) 
                                          | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                                             != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6__0))) 
                                         | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                                            != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3__0))) 
                                        | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                                           != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4__0))) 
                                       | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                                          != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5__0))) 
                                      | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1) 
                                         != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1__0))) 
                                     | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                                        != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2__0))));
    vlSelf->__VstlTriggered.set(4U, ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1__0)));
    vlSelf->__VstlTriggered.set(5U, ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2__0)));
    vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r__0 
        = vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r;
    vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0__0 
        = vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0;
    vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel__0 
        = vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel;
    vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6__0 
        = vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6;
    vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3__0 
        = vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3;
    vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4__0 
        = vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4;
    vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5__0 
        = vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5;
    vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1__0 
        = vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1;
    vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2__0 
        = vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2;
    vlSelf->__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid__0 
        = vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VstlDidInit))))) {
        vlSelf->__VstlDidInit = 1U;
        vlSelf->__VstlTriggered.set(1U, 1U);
        vlSelf->__VstlTriggered.set(2U, 1U);
        vlSelf->__VstlTriggered.set(3U, 1U);
        vlSelf->__VstlTriggered.set(4U, 1U);
        vlSelf->__VstlTriggered.set(5U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VysyxSoCFull___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
