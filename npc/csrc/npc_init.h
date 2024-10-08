#ifndef NPC_INIT_H
#define NPC_INIT_H
#include "npc_sources.h"

uint8_t* guest_to_host_extern(uint32_t addr);

long load_img(char *img_file);

void init_mem();

uint32_t pmem_read(uint32_t addr, int len);

void pmem_write(uint32_t addr, int len, uint32_t data);







#endif