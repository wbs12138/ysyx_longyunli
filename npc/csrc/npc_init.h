#ifndef NPC_INIT_H
#define NPC_INIT_H

static char *img_file = NULL;

void load_img();

static uint32_t pmem_read(uint32_t addr, int len);

static void pmem_write(uint32_t addr, int len, uint32_t data);







#endif