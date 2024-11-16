#ifndef CPU_EXEC_H
#define CPU_EXEC_H

void init_cpu();

void end_cpu();

void exec_cpu(uint32_t exec_time);

void isa_reg_display();

uint32_t isa_reg_str2val(const char *s, bool *success);

uint32_t read_cpu_state_pc();

uint32_t read_cpu_state_mtvec();

uint32_t read_cpu_state_mepc();

uint32_t read_cpu_state_mstatus();

uint32_t read_cpu_state_mcause();

uint32_t read_cpu_state_gpr(int ind);

#endif