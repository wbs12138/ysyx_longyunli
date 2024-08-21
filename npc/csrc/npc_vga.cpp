
#include "npc_vga.h"

#define SCREEN_W    400 
#define SCREEN_H    300

static uint32_t screen_width() {
  return SCREEN_W;
}

static uint32_t screen_height() {
  return SCREEN_H;
}

static uint32_t screen_size() {
  return screen_width() * screen_height() * sizeof(uint32_t);
}

uint8_t vmem[SCREEN_W*SCREEN_H*4] PG_ALIGN = {};

uint32_t *vgactl_port_base = NULL;

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

//no doubt
static void init_screen() {
  SDL_Window *window = NULL;
  char title[128];
  sprintf(title, "%s-NPC", "wangbaosen");
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(
      SCREEN_W * 2,
      SCREEN_H * 2,
      0, &window, &renderer);
  SDL_SetWindowTitle(window, title);
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
      SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);
  SDL_RenderPresent(renderer);
}

//update screen due to vmem
static inline void update_screen() {
  SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}

//if sync , do update
void vga_update_screen() {

  uint32_t sync = vgactl_port_base[1];
  if (sync) {
    update_screen();
    vgactl_port_base[1] = 0;
  }
}

void init_vga() {

  vgactl_port_base = (uint32_t *)malloc(2*sizeof(uint32_t));

  vgactl_port_base[0] = (screen_width() << 16) | screen_height();

  init_screen();

  memset(vmem, 0, sizeof(vmem));
}

uint8_t* v_guest_to_host(uint32_t addr) { return vmem + addr - 0xa1000000; }

static inline void v_host_write(void *addr, int len, uint32_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default:assert(0);
  }
}

void vmem_write(uint32_t addr, int len, uint32_t data){
    v_host_write(v_guest_to_host(addr), len, data);
}

void free_vgactl_port_base(){
    free(vgactl_port_base);
}

int read_vgactl(){
  //int size = (screen_size() + ((1ul<<12) - 1)) & ~((1ul<<12)-1);
  //printf("size=%d\n",size);483328
    return vgactl_port_base[0];
};

void write_vgactl(int wdata){
    vgactl_port_base[1]=wdata;
    return ;
}
