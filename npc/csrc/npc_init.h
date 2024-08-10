#ifndef NPC_INIT_H
#define NPC_INIT_H


void load_img(char *img_file);

void init_mem();

uint32_t pmem_read(uint32_t addr, int len);

void pmem_write(uint32_t addr, int len, uint32_t data);







#endif