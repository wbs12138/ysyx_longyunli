.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  la sp, _stack_pointer
  la a0, text_start
  la a1, text_load_start
  beq a0, a1, skip_memcpy
  la a2, text_size
_copy_loop:
  lw a3, 0(a1)          
  sw a3, 0(a0)       
  addi a0, a0, 4       
  addi a1, a1, 4      
  addi a2, a2, -4       
  bnez a2, _copy_loop   
skip_memcpy:
  la a0, _trm_init
  jalr a0
