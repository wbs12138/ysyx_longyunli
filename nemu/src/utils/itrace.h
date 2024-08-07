
#ifndef __ITRACE_H__
#define __ITRACE_H__


#include <common.h>
#include <common.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>



void trace_inst(word_t pc, uint32_t inst);

void display_inst();

void trace_memory(paddr_t addr, int len , word_t data, int wr );

void display_memory();

void parse_elf(const char *elf_file);

void trace_func_call(paddr_t pc, paddr_t target, bool is_tail);

void trace_func_ret(paddr_t pc);

#endif
