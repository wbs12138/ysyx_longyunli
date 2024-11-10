.section entry, "ax"
.globl _start
.type _start, @function
.globl text_start
.globl text_load_start
.globl text_size

_start:
  mv s0, zero
  la sp, _stack_pointer
  jal _trm_init

  // 加载text_start和text_load_start的值到寄存器中
  la a0, text_start
  la a1, text_load_start

  lw a0, 0(a0) // 将text_start的实际地址加载到a0
  lw a1, 0(a1) // 将text_load_start的实际地址加载到a1
  beq a0, a1, skip_memcpy

  // 加载text_size的值到a2寄存器
  la a2, text_size
  lw a2, 0(a2) // 将text_size的值加载到a2

  // 加载text_load_start的值到a0寄存器
  lw a0, 0(a1) // 将text_load_start的值加载到a0

  // 加载text_start的值到a1寄存器
  lw a1, 0(a0) // 将text_start的值加载到a1

_copy_loop:
  lw a3, 0(a0)          // 从源地址加载一个字
  sw a3, 0(a1)          // 将字存储到目标地址
  addi a0, a0, 4       // 增加源地址
  addi a1, a1, 4       // 增加目标地址
  addi a2, a2, -1       // 减少复制大小（因为text_size是以字为单位的）
  bnez a2, _copy_loop   // 如果还有数据要复制，继续循环

skip_memcpy:
  // 跳转到初始化函数
  jal _trm_init