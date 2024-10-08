#include "npc_sources.h"
#include "npc_init.h"

uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};

uint8_t* guest_to_host(uint32_t addr) { return pmem + addr - CONFIG_MBASE; }
uint32_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

uint8_t* guest_to_host_extern(uint32_t addr){return guest_to_host(addr);}

static inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: assert(0);
  }
}

static inline void host_write(void *addr, int len, uint32_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default:assert(0);
  }
}

uint32_t pmem_read(uint32_t addr, int len) {
  uint32_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

void pmem_write(uint32_t addr, int len, uint32_t data) {
  host_write(guest_to_host(addr), len, data);
}

void init_mem() {
  memset(pmem, 0, CONFIG_MSIZE);
  printf("\033[1;34m[%s:%d]physical memory area [\" %x \", \" %x \"]\033[0m\r\n", __FILE__,__LINE__,PMEM_LEFT, PMEM_RIGHT);
}



//static long load_img() 
long load_img(char *img_file){
  if (img_file == NULL) {
    printf("\033[1;31m[%s:%d]No image is given. Use the default build-in image.\033[0m\n",__FILE__,__LINE__);
    return 0;
  }

  FILE *fp = fopen(img_file, "rb");
  assert(fp);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("\033[1;34m[%s:%d]The image is %s, size = %ld\033[0m\r\n",__FILE__,__LINE__, img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);
  fclose(fp);
  printf("\033[1;34moo      o      ooooo        oooo    \no o    o      o    o      o    o   \no  o   o      o    o     o         \no   o  o      ooooo      o         \no    o o      o          o     o   \no     oo      o           ooooo    \n\033[0m\r\n");
  return size;
}