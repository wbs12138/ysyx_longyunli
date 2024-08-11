// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/dpi_c_ebreak.v:5:30
    extern void ebreak();
    // DPI import at /home/wangbaosen/ysyx/ysyx-workbench/npc/vsrc/dpi_c_ftrace.v:2:30
    extern void ftrace_update(int dnpc_v, int trace1, int trace2, int trace3, int trace4);

#ifdef __cplusplus
}
#endif

#endif  // guard
