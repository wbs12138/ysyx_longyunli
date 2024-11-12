.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  la sp, _stack_pointer
skip_memcpy:
  la a0, _trm_init
  jalr a0
