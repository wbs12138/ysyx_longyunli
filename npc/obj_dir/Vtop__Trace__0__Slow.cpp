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
    tracep->declBit(c+72,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+76,0,"mem_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+77,0,"mem_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+78,0,"mem_wen_dg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+72,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+76,0,"mem_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+77,0,"mem_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+78,0,"mem_wen_dg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+80,0,"func7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+81,0,"func3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+82,0,"lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"beq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"bne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"blt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"bge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"bltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"bgeu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"lb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"lh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"lw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"lbu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"lhu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"sb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"sh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"sw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"slti",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"sltiu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"xori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"ori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"andi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"slli",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"srli",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"srai",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"sll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"slt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"sltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"xorr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"srl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"sra",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"orr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"andd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"inst_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"inst_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"inst_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"inst_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"inst_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+87,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+88,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+89,0,"rdata_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"rf_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"rf_rdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"rf_rdata2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"rf_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+86,0,"rf_raddr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+87,0,"rf_raddr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+93,0,"rf_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"a0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+78,0,"mem_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"mem_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"mem_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"mem_wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("inst_RegisterFile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+102,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+72,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+93,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+87,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+39,0,"a0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+40+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("inst_dpi_c_ebreak", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+75,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"a0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("inst_dpi_c_ftrace", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+75,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"pc_next",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+84,0,"jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+98,0,"ftrace1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"ftrace2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"ftrace3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"ftrace4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("inst_pc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+103,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+72,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+105,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
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
    bufp->fullIData(oldp+102,(5U),32);
    bufp->fullIData(oldp+103,(0x20U),32);
    bufp->fullIData(oldp+104,(0x80000000U),32);
    bufp->fullBit(oldp+105,(1U));
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
    bufp->fullBit(oldp+1,(vlSelf->top__DOT__jalr));
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__beq));
    bufp->fullBit(oldp+3,(vlSelf->top__DOT__bne));
    bufp->fullBit(oldp+4,(vlSelf->top__DOT__blt));
    bufp->fullBit(oldp+5,(vlSelf->top__DOT__bge));
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__bltu));
    bufp->fullBit(oldp+7,(vlSelf->top__DOT__bgeu));
    bufp->fullBit(oldp+8,(vlSelf->top__DOT__lb));
    bufp->fullBit(oldp+9,(vlSelf->top__DOT__lh));
    bufp->fullBit(oldp+10,(vlSelf->top__DOT__lw));
    bufp->fullBit(oldp+11,(vlSelf->top__DOT__lbu));
    bufp->fullBit(oldp+12,(vlSelf->top__DOT__lhu));
    bufp->fullBit(oldp+13,(vlSelf->top__DOT__sb));
    bufp->fullBit(oldp+14,(vlSelf->top__DOT__sh));
    bufp->fullBit(oldp+15,(vlSelf->top__DOT__sw));
    bufp->fullBit(oldp+16,(vlSelf->top__DOT__addi));
    bufp->fullBit(oldp+17,(vlSelf->top__DOT__slti));
    bufp->fullBit(oldp+18,(vlSelf->top__DOT__sltiu));
    bufp->fullBit(oldp+19,(vlSelf->top__DOT__xori));
    bufp->fullBit(oldp+20,(vlSelf->top__DOT__ori));
    bufp->fullBit(oldp+21,(vlSelf->top__DOT__andi));
    bufp->fullBit(oldp+22,(vlSelf->top__DOT__slli));
    bufp->fullBit(oldp+23,(vlSelf->top__DOT__srli));
    bufp->fullBit(oldp+24,(vlSelf->top__DOT__srai));
    bufp->fullBit(oldp+25,(vlSelf->top__DOT__add));
    bufp->fullBit(oldp+26,(vlSelf->top__DOT__sub));
    bufp->fullBit(oldp+27,(vlSelf->top__DOT__sll));
    bufp->fullBit(oldp+28,(vlSelf->top__DOT__slt));
    bufp->fullBit(oldp+29,(vlSelf->top__DOT__sltu));
    bufp->fullBit(oldp+30,(vlSelf->top__DOT__xorr));
    bufp->fullBit(oldp+31,(vlSelf->top__DOT__srl));
    bufp->fullBit(oldp+32,(vlSelf->top__DOT__sra));
    bufp->fullBit(oldp+33,(vlSelf->top__DOT__orr));
    bufp->fullBit(oldp+34,(vlSelf->top__DOT__andd));
    bufp->fullBit(oldp+35,(((IData)(vlSelf->top__DOT__jalr) 
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
                                                                   | (IData)(vlSelf->top__DOT__srai)))))))))))))))));
    bufp->fullBit(oldp+36,(((IData)(vlSelf->top__DOT__beq) 
                            | ((IData)(vlSelf->top__DOT__bne) 
                               | ((IData)(vlSelf->top__DOT__blt) 
                                  | ((IData)(vlSelf->top__DOT__bge) 
                                     | ((IData)(vlSelf->top__DOT__bltu) 
                                        | (IData)(vlSelf->top__DOT__bgeu))))))));
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__imm),32);
    bufp->fullCData(oldp+38,(((IData)(vlSelf->top__DOT__sb)
                               ? 1U : ((IData)(vlSelf->top__DOT__sh)
                                        ? 3U : ((IData)(vlSelf->top__DOT__sw)
                                                 ? 0xfU
                                                 : 0U)))),4);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                             [0xaU]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[0]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[1]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[2]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[3]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[4]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[5]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[6]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[7]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[8]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[9]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[10]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[11]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[12]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[13]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[14]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[15]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[16]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[17]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[18]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[19]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[20]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[21]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[22]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[23]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[24]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[25]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[26]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[27]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[28]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[29]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[30]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[31]),32);
    bufp->fullBit(oldp+72,(vlSelf->clk));
    bufp->fullBit(oldp+73,(vlSelf->reset));
    bufp->fullIData(oldp+74,(vlSelf->pc),32);
    bufp->fullIData(oldp+75,(vlSelf->ist),32);
    bufp->fullBit(oldp+76,(vlSelf->mem_valid));
    bufp->fullIData(oldp+77,(vlSelf->mem_raddr),32);
    bufp->fullBit(oldp+78,(vlSelf->mem_wen_dg));
    bufp->fullCData(oldp+79,((0x7fU & vlSelf->ist)),7);
    bufp->fullCData(oldp+80,((vlSelf->ist >> 0x19U)),7);
    bufp->fullCData(oldp+81,((7U & (vlSelf->ist >> 0xcU))),3);
    bufp->fullBit(oldp+82,((0x37U == (0x7fU & vlSelf->ist))));
    bufp->fullBit(oldp+83,((0x17U == (0x7fU & vlSelf->ist))));
    bufp->fullBit(oldp+84,((0x6fU == (0x7fU & vlSelf->ist))));
    bufp->fullBit(oldp+85,(((0x17U == (0x7fU & vlSelf->ist)) 
                            | (0x37U == (0x7fU & vlSelf->ist)))));
    bufp->fullCData(oldp+86,((0x1fU & (vlSelf->ist 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+87,((0x1fU & (vlSelf->ist 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+88,((0x1fU & (vlSelf->ist 
                                       >> 7U))),5);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__rdata_mem),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__rf_wdata),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__rf_rdata1),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__rf_rdata2),32);
    bufp->fullBit(oldp+93,(((0x37U == (0x7fU & vlSelf->ist)) 
                            | ((0x17U == (0x7fU & vlSelf->ist)) 
                               | ((0x6fU == (0x7fU 
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
                                                                                | (IData)(vlSelf->top__DOT__andd))))))))))))))))))))))))))))));
    bufp->fullIData(oldp+94,(((IData)(vlSelf->top__DOT__jalr)
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
                                               & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32))
                                               ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                               : (((IData)(vlSelf->top__DOT__bltu) 
                                                   & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33))
                                                   ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                   : 
                                                  (((IData)(vlSelf->top__DOT__bge) 
                                                    & (((~ (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_24)) 
                                                        & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_29)) 
                                                       | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_30) 
                                                          & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_26 
                                                             >= vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31))))
                                                    ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                    : 
                                                   (((IData)(vlSelf->top__DOT__bgeu) 
                                                     & (vlSelf->top__DOT__rf_rdata1 
                                                        >= vlSelf->top__DOT__rf_rdata2))
                                                     ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelf->pc)))))))))),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__mem_waddr),32);
    bufp->fullBit(oldp+96,((IData)((0x67U == (0x707fU 
                                              & vlSelf->ist)))));
    bufp->fullIData(oldp+97,(VL_SHIFTR_III(32,32,32, vlSelf->ist, 0x14U)),32);
    bufp->fullBit(oldp+98,((IData)((0xefU == (0xfffU 
                                              & vlSelf->ist)))));
    bufp->fullBit(oldp+99,((0x8067U == vlSelf->ist)));
    bufp->fullBit(oldp+100,((IData)((0xe7U == (0x7fffU 
                                               & vlSelf->ist)))));
    bufp->fullBit(oldp+101,((IData)((0x67U == (0xfff07fffU 
                                               & vlSelf->ist)))));
}
