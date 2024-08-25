#define concat_temp(x, y) x ## y
#define concat(x, y) concat_temp(x, y)
#define MAP(c, f) c(f)

#define REGS(f) \
      f( 1) f( 2)       f( 4) f( 5) f( 6) f( 7) f( 8) f( 9) \
f(10) f(11) f(12) f(13) f(14) f(15) f(16) f(17) f(18) f(19) \
f(20) f(21) f(22) f(23) f(24) f(25) f(26) f(27) f(28) f(29) \
f(30) f(31)

#define PUSH(n) st.w $concat(r, n), $sp, (n * 4);
#define POP(n)  ld.w  $concat(r, n), $sp, (n * 4);

#define CONTEXT_SIZE  ((32 + 3) * 4)
#define OFFSET_SP     ( 3 * 4)
#define OFFSET_ESTAT  (32 * 4)
#define OFFSET_PRMD   (33 * 4)
#define OFFSET_ERA    (34 * 4)

#define CSR_ESTAT  0x5
#define CSR_PRMD  0x1
#define CSR_ERA   0x6

.align 6
.globl __am_asm_trap
__am_asm_trap:
	addi sp, sp, -((32 + 3 + 1) * 8)
  	
    # 保存寄存器至栈上
    sd x1, (1 * 8)(sp)
    sd x3, (3 * 8)(sp)
    sd x4, (4 * 8)(sp)
    sd x5, (5 * 8)(sp)
    sd x6, (6 * 8)(sp)
    sd x7, (7 * 8)(sp)
    sd x8, (8 * 8)(sp)
    sd x9, (9 * 8)(sp)
    sd x10, (10 * 8)(sp)
    sd x11, (11 * 8)(sp)
    sd x12, (12 * 8)(sp)
    sd x13, (13 * 8)(sp)
    sd x14, (14 * 8)(sp)
    sd x15, (15 * 8)(sp)
    sd x16, (16 * 8)(sp)
    sd x17, (17 * 8)(sp)
    sd x18, (18 * 8)(sp)
    sd x19, (19 * 8)(sp)
    sd x20, (20 * 8)(sp)
    sd x21, (21 * 8)(sp)
    sd x22, (22 * 8)(sp)
    sd x23, (23 * 8)(sp)
    sd x24, (24 * 8)(sp)
    sd x25, (25 * 8)(sp)
    sd x26, (26 * 8)(sp)
    sd x27, (27 * 8)(sp)
    sd x28, (28 * 8)(sp)
    sd x29, (29 * 8)(sp)
    sd x30, (30 * 8)(sp)
    sd x31, (31 * 8)(sp)

	# 取出CSR并保存至栈上
    csrr t0, mcause
    csrr t1, mstatus
    csrr t2, mepc
    sd t0, ((32 + 0) * 8)(sp)
    sd t1, ((32 + 1) * 8)(sp)
    sd t2, ((32 + 2) * 8)(sp)

    # set mstatus.MPRV to pass difftest
    li a0, (1 << 17)
    or t1, t1, a0
    csrw mstatus, t1

	# a0用于传递__am_irq_handle需要的参数，也就是Context *c,也就是刚刚保存在栈上的上下文
    mv a0, sp
    jal __am_irq_handle

	# 恢复寄存器和CSR
    ld t1, ((32 + 1) * 8)(sp)
    ld t2, ((32 + 2) * 8)(sp)
    csrw mstatus, t1
    csrw mepc, t2

    ld x1, (1 * 8)(sp)
    ld x3, (3 * 8)(sp)
    ld x4, (4 * 8)(sp)
    ld x5, (5 * 8)(sp)
    ld x6, (6 * 8)(sp)
    ld x7, (7 * 8)(sp)
    ld x8, (8 * 8)(sp)
    ld x9, (9 * 8)(sp)
    ld x10, (10 * 8)(sp)
    ld x11, (11 * 8)(sp)
    ld x12, (12 * 8)(sp)
    ld x13, (13 * 8)(sp)
    ld x14, (14 * 8)(sp)
    ld x15, (15 * 8)(sp)
    ld x16, (16 * 8)(sp)
    ld x17, (17 * 8)(sp)
    ld x18, (18 * 8)(sp)
    ld x19, (19 * 8)(sp)
    ld x20, (20 * 8)(sp)
    ld x21, (21 * 8)(sp)
    ld x22, (22 * 8)(sp)
    ld x23, (23 * 8)(sp)
    ld x24, (24 * 8)(sp)
    ld x25, (25 * 8)(sp)
    ld x26, (26 * 8)(sp)
    ld x27, (27 * 8)(sp)
    ld x28, (28 * 8)(sp)
    ld x29, (29 * 8)(sp)
    ld x30, (30 * 8)(sp)
    ld x31, (31 * 8)(sp)
    
	# 跳转回发生异常指令或下一条
    addi sp, sp, ((32 + 3 + 1) * 8)
    mret
@   addi.w $sp, $sp, -CONTEXT_SIZE

@   MAP(REGS, PUSH)

@   csrrd $t0, CSR_ESTAT
@   csrrd $t1, CSR_PRMD
@   csrrd $t2, CSR_ERA

@   st.w $t0, $sp, OFFSET_ESTAT
@   st.w $t1, $sp, OFFSET_PRMD
@   st.w $t2, $sp, OFFSET_ERA

@   move $a0, $sp
@   bl __am_irq_handle

@   ld.w $t1, $sp, OFFSET_PRMD
@   ld.w $t2, $sp, OFFSET_ERA
@   csrwr $t1, CSR_PRMD
@   csrwr $t2, CSR_ERA

@   MAP(REGS, POP)

@   addi.w $sp, $sp, CONTEXT_SIZE
@   ertn
