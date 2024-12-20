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
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/dpi_c_ebreak.v:6:30
    extern void ebreak(int back_right);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/ysyxSoC/perip/flash/flash.v:84:30
    extern void flash_read(int addr, int* data);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/dpi_c_ftrace.v:2:30
    extern void ftrace_update(int dnpc_v, int trace1, int trace2, int trace3, int trace4);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v:4716:30
    extern void mrom_read(int raddr, int* rdata);
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/RegisterFile.v:13:30
    extern void regfile_update(int rf1, int rf2, int rf3, int rf4, int rf5, int rf6, int rf7, int rf8, int rf9, int rf10, int rf11, int rf12, int rf13, int rf14, int rf15, int rf16, int rf17, int rf18, int rf19, int rf20, int rf21, int rf22, int rf23, int rf24, int rf25, int rf26, int rf27, int rf28, int rf29, int rf30, int rf31);

#ifdef __cplusplus
}
#endif

#endif  // guard
