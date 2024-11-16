run:
	riscv64-linux-gnu-gcc -Wall -Wextra -Os -nostartfiles -nostdlib char-test.c -o char-test.elf
	riscv64-linux-gnu-objcopy -O binary --only-section=.text char-test.elf char-test.bin

clean: 
	rm -rf char-test.bin char-test.elf