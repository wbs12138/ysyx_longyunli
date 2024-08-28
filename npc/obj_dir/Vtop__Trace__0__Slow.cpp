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
    tracep->declBit(c+75,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+77,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+79,0,"mem_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"mem_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+81,0,"mem_wen_dg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"mepc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"mtvec",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"mcause",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"mstatus",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+75,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+77,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+79,0,"mem_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"mem_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+81,0,"mem_wen_dg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"mepc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"mtvec",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"mcause",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"mstatus",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+87,0,"func7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+88,0,"func3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+89,0,"lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
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
    tracep->declBit(c+92,0,"ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"csrrw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"csrrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"inst_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"inst_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"inst_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"inst_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"inst_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+96,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+97,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+98,0,"rdata_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"rf_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"rf_rdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"rf_rdata2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"rf_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+95,0,"rf_raddr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+96,0,"rf_raddr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+102,0,"rf_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+103,0,"csr_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"mepc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+105,0,"mtvec_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"mcause_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"mstatus_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+108,0,"mepc_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"mtvec_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"mcause_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"mstatus_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"a0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+81,0,"mem_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"mem_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"mem_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"mem_wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("inst_RegisterFile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+119,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+120,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+75,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+102,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+96,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+42,0,"a0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+43+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("inst_dpi_c_ebreak", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+78,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"a0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("inst_dpi_c_ftrace", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+78,0,"ist",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"pc_next",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+91,0,"jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+114,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+115,0,"ftrace1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"ftrace2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"ftrace3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"ftrace4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("inst_mcause", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+120,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+75,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+109,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("inst_mepc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+120,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+75,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+108,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("inst_mstatus", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+120,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+75,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+110,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("inst_mtvec", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+120,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+75,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+40,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("inst_pc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+120,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+75,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+111,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+124,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
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
    bufp->fullIData(oldp+119,(5U),32);
    bufp->fullIData(oldp+120,(0x20U),32);
    bufp->fullIData(oldp+121,(0U),32);
    bufp->fullIData(oldp+122,(0x1800U),32);
    bufp->fullIData(oldp+123,(0x80000000U),32);
    bufp->fullBit(oldp+124,(1U));
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
    bufp->fullBit(oldp+35,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+36,(vlSelf->top__DOT__csrrs));
    bufp->fullBit(oldp+37,(((IData)(vlSelf->top__DOT__jalr) 
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
                                                                   | ((IData)(vlSelf->top__DOT__srai) 
                                                                      | (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_44))))))))))))))))));
    bufp->fullBit(oldp+38,(((IData)(vlSelf->top__DOT__beq) 
                            | ((IData)(vlSelf->top__DOT__bne) 
                               | ((IData)(vlSelf->top__DOT__blt) 
                                  | ((IData)(vlSelf->top__DOT__bge) 
                                     | ((IData)(vlSelf->top__DOT__bltu) 
                                        | (IData)(vlSelf->top__DOT__bgeu))))))));
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+40,(((0x305U == vlSelf->top__DOT__imm) 
                            & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_44))));
    bufp->fullCData(oldp+41,(((IData)(vlSelf->top__DOT__sb)
                               ? 1U : ((IData)(vlSelf->top__DOT__sh)
                                        ? 3U : ((IData)(vlSelf->top__DOT__sw)
                                                 ? 0xfU
                                                 : 0U)))),4);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf
                             [0xaU]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[0]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[1]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[2]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[3]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[4]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[5]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[6]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[7]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[8]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[9]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[10]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[11]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[12]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[13]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[14]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[15]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[16]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[17]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[18]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[19]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[20]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[21]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[22]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[23]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[24]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[25]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[26]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[27]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[28]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[29]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[30]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__inst_RegisterFile__DOT__rf[31]),32);
    bufp->fullBit(oldp+75,(vlSelf->clk));
    bufp->fullBit(oldp+76,(vlSelf->reset));
    bufp->fullIData(oldp+77,(vlSelf->pc),32);
    bufp->fullIData(oldp+78,(vlSelf->ist),32);
    bufp->fullBit(oldp+79,(vlSelf->mem_valid));
    bufp->fullIData(oldp+80,(vlSelf->mem_raddr),32);
    bufp->fullBit(oldp+81,(vlSelf->mem_wen_dg));
    bufp->fullIData(oldp+82,(vlSelf->mepc),32);
    bufp->fullIData(oldp+83,(vlSelf->mtvec),32);
    bufp->fullIData(oldp+84,(vlSelf->mcause),32);
    bufp->fullIData(oldp+85,(vlSelf->mstatus),32);
    bufp->fullCData(oldp+86,((0x7fU & vlSelf->ist)),7);
    bufp->fullCData(oldp+87,((vlSelf->ist >> 0x19U)),7);
    bufp->fullCData(oldp+88,((7U & (vlSelf->ist >> 0xcU))),3);
    bufp->fullBit(oldp+89,((0x37U == (0x7fU & vlSelf->ist))));
    bufp->fullBit(oldp+90,((0x17U == (0x7fU & vlSelf->ist))));
    bufp->fullBit(oldp+91,((0x6fU == (0x7fU & vlSelf->ist))));
    bufp->fullBit(oldp+92,((0x73U == vlSelf->ist)));
    bufp->fullBit(oldp+93,((0x30200073U == vlSelf->ist)));
    bufp->fullBit(oldp+94,(((0x17U == (0x7fU & vlSelf->ist)) 
                            | (0x37U == (0x7fU & vlSelf->ist)))));
    bufp->fullCData(oldp+95,((0x1fU & (vlSelf->ist 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+96,((0x1fU & (vlSelf->ist 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+97,((0x1fU & (vlSelf->ist 
                                       >> 7U))),5);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__rdata_mem),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__rf_wdata),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__rf_rdata1),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__rf_rdata2),32);
    bufp->fullBit(oldp+102,(((0x37U == (0x7fU & vlSelf->ist)) 
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
                                                                                | ((IData)(vlSelf->top__DOT__andd) 
                                                                                | ((IData)(vlSelf->top__DOT__csrrs) 
                                                                                | (IData)(vlSelf->top__DOT__csrrw))))))))))))))))))))))))))))))));
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__csr_sel),32);
    bufp->fullIData(oldp+104,(((IData)(vlSelf->top__DOT__csrrw)
                                ? vlSelf->top__DOT__rf_rdata1
                                : ((IData)(vlSelf->top__DOT__csrrs)
                                    ? (vlSelf->mepc 
                                       | vlSelf->top__DOT__rf_rdata1)
                                    : ((0x73U == vlSelf->ist)
                                        ? vlSelf->pc
                                        : 0U)))),32);
    bufp->fullIData(oldp+105,(((IData)(vlSelf->top__DOT__csrrw)
                                ? vlSelf->top__DOT__rf_rdata1
                                : ((IData)(vlSelf->top__DOT__csrrs)
                                    ? (vlSelf->mtvec 
                                       | vlSelf->top__DOT__rf_rdata1)
                                    : 0U))),32);
    bufp->fullIData(oldp+106,(((IData)(vlSelf->top__DOT__csrrw)
                                ? vlSelf->top__DOT__rf_rdata1
                                : ((IData)(vlSelf->top__DOT__csrrs)
                                    ? (vlSelf->mcause 
                                       | vlSelf->top__DOT__rf_rdata1)
                                    : ((0x73U == vlSelf->ist)
                                        ? 0xbU : 0U)))),32);
    bufp->fullIData(oldp+107,(((IData)(vlSelf->top__DOT__csrrw)
                                ? vlSelf->top__DOT__rf_rdata1
                                : ((IData)(vlSelf->top__DOT__csrrs)
                                    ? (vlSelf->mstatus 
                                       | vlSelf->top__DOT__rf_rdata1)
                                    : ((0x30200073U 
                                        == vlSelf->ist)
                                        ? (0x80U | 
                                           ((0xffffe000U 
                                             & vlSelf->mstatus) 
                                            | ((0x700U 
                                                & vlSelf->mstatus) 
                                               | ((0x70U 
                                                   & vlSelf->mstatus) 
                                                  | ((8U 
                                                      & (vlSelf->mstatus 
                                                         >> 4U)) 
                                                     | (7U 
                                                        & vlSelf->mstatus))))))
                                        : ((0x73U == vlSelf->ist)
                                            ? (0x1800U 
                                               | ((0xffffe000U 
                                                   & vlSelf->mstatus) 
                                                  | ((0x700U 
                                                      & vlSelf->mstatus) 
                                                     | ((0x80U 
                                                         & (vlSelf->mstatus 
                                                            << 4U)) 
                                                        | (0x77U 
                                                           & vlSelf->mstatus)))))
                                            : 0U))))),32);
    bufp->fullBit(oldp+108,((((0x341U == vlSelf->top__DOT__imm) 
                              & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_44)) 
                             | (0x73U == vlSelf->ist))));
    bufp->fullBit(oldp+109,((((0x342U == vlSelf->top__DOT__imm) 
                              & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_44)) 
                             | (0x73U == vlSelf->ist))));
    bufp->fullBit(oldp+110,((((0x300U == vlSelf->top__DOT__imm) 
                              & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_44)) 
                             | ((0x30200073U == vlSelf->ist) 
                                | (0x73U == vlSelf->ist)))));
    bufp->fullIData(oldp+111,(((IData)(vlSelf->top__DOT__jalr)
                                ? (0xfffffffeU & vlSelf->top__DOT__mem_waddr)
                                : ((0x6fU == (0x7fU 
                                              & vlSelf->ist))
                                    ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_21
                                    : (((IData)(vlSelf->top__DOT__beq) 
                                        & (vlSelf->top__DOT__rf_rdata1 
                                           == vlSelf->top__DOT__rf_rdata2))
                                        ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_45
                                        : (((IData)(vlSelf->top__DOT__bne) 
                                            & (vlSelf->top__DOT__rf_rdata1 
                                               != vlSelf->top__DOT__rf_rdata2))
                                            ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_45
                                            : (((IData)(vlSelf->top__DOT__blt) 
                                                & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_34))
                                                ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_45
                                                : (
                                                   ((IData)(vlSelf->top__DOT__bltu) 
                                                    & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_35))
                                                    ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_45
                                                    : 
                                                   (((IData)(vlSelf->top__DOT__bge) 
                                                     & (((~ (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_25)) 
                                                         & (IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_31)) 
                                                        | ((IData)(vlSelf->top__DOT____VdfgRegularize_h245778ca_0_32) 
                                                           & (vlSelf->top__DOT____VdfgRegularize_h245778ca_0_27 
                                                              >= vlSelf->top__DOT____VdfgRegularize_h245778ca_0_33))))
                                                     ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_45
                                                     : 
                                                    (((IData)(vlSelf->top__DOT__bgeu) 
                                                      & (vlSelf->top__DOT__rf_rdata1 
                                                         >= vlSelf->top__DOT__rf_rdata2))
                                                      ? vlSelf->top__DOT____VdfgRegularize_h245778ca_0_45
                                                      : 
                                                     ((0x30200073U 
                                                       == vlSelf->ist)
                                                       ? vlSelf->mepc
                                                       : 
                                                      ((0x73U 
                                                        == vlSelf->ist)
                                                        ? vlSelf->mtvec
                                                        : 
                                                       ((IData)(4U) 
                                                        + vlSelf->pc)))))))))))),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__mem_waddr),32);
    bufp->fullBit(oldp+113,((IData)((0x67U == (0x707fU 
                                               & vlSelf->ist)))));
    bufp->fullIData(oldp+114,(VL_SHIFTR_III(32,32,32, vlSelf->ist, 0x14U)),32);
    bufp->fullBit(oldp+115,((IData)((0xefU == (0xfffU 
                                               & vlSelf->ist)))));
    bufp->fullBit(oldp+116,((0x8067U == vlSelf->ist)));
    bufp->fullBit(oldp+117,((IData)((0xe7U == (0x7fffU 
                                               & vlSelf->ist)))));
    bufp->fullBit(oldp+118,((IData)((0x67U == (0xfff07fffU 
                                               & vlSelf->ist)))));
}
