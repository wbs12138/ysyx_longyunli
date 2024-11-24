// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYXSOCFULL__DPI_H_
#define VERILATED_VYSYXSOCFULL__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/dpi_c_ecall.v:5:30
    extern void cpu_ecall(int ecall, int mret);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/dpi_c_ebreak.v:6:30
    extern void ebreak(int back_right);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/ysyxSoC/perip/flash/flash.v:84:30
    extern void flash_read(int addr, int* data);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/dpi_c_ftrace.v:2:30
    extern void ftrace_update(int dnpc_v, int trace1, int trace2, int trace3, int trace4);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/ysyx_24080008.v:271:30
    extern void get_csr(int mepc, int mcause, int mtvec, int mstatus);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/axi_interface.v:80:34
    extern void get_inst(int inst);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/axi_interface.v:82:34
    extern void get_pc(int dnpc);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/axi_interface.v:84:34
    extern void memory_access(int npc_state_lsuaw, int npc_state_lsuar, int npc_aw_addr, int npc_aw_len, int npc_aw_data, int npc_ar_addr, int npc_ar_len);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v:4758:30
    extern void mrom_read(int raddr, int* rdata);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/RegisterFile.v:13:30
    extern void regfile_update(int rf1, int rf2, int rf3, int rf4, int rf5, int rf6, int rf7, int rf8, int rf9, int rf10, int rf11, int rf12, int rf13, int rf14, int rf15, int rf16, int rf17, int rf18, int rf19, int rf20, int rf21, int rf22, int rf23, int rf24, int rf25, int rf26, int rf27, int rf28, int rf29, int rf30, int rf31);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/axi_interface.v:74:34
    extern void state_is_exeu(int npc_state);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/axi_interface.v:76:34
    extern void state_is_ifuar(int npc_state);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/axi_interface.v:78:34
    extern void state_is_ifur(int npc_state);

#ifdef __cplusplus
}
#endif

#endif  // guard
