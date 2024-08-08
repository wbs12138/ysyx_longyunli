#include <common.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include </home/wangbaosen/ysyx/ysyx-workbench/nemu/src/utils/itrace.h>

#define MAX_IRINGBUF 16
#define MAX_MRINGBUF 32

#define OUTPUT_FILE "ftrace.txt"

typedef struct {
  word_t pc;
  uint32_t inst;
} ItraceNode;

typedef struct {
  word_t pc;
  uint32_t inst;
  paddr_t addr;
  int len;
  word_t data; 
  int wr;
} MtraceNode;

ItraceNode iringbuf[MAX_IRINGBUF];
MtraceNode mringbuf[MAX_MRINGBUF];


int p_cur = 0;
bool full = false;

int pm_cur = 0;
bool full_m = false;



void trace_inst(word_t pc, uint32_t inst) {
  
  iringbuf[p_cur].pc = pc;
  iringbuf[p_cur].inst = inst;
  p_cur = (p_cur + 1) % MAX_IRINGBUF;
  full = full || p_cur == 0;
}

void display_inst() {
  if (!full && !p_cur) return;

  int end = p_cur;
  int i = full?p_cur:0;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  char buf[128]; // 128 should be enough!
  char *p;
  int msg1_over=0;
  do {
    if(msg1_over==0){
      printf("     the instruction saved is:\n");
      msg1_over=1;
    }
    p = buf;
    p += sprintf(buf, "%s" FMT_WORD ": %08x ", (i+1)%MAX_IRINGBUF==end?" --> ":"     ", iringbuf[i].pc, iringbuf[i].inst);
    disassemble(p, buf+sizeof(buf)-p, iringbuf[i].pc, (uint8_t *)&iringbuf[i].inst, 4);

    if ((i+1)%MAX_IRINGBUF==end) printf(ANSI_FG_RED);
    puts(buf);
  } while ((i = (i+1)%MAX_IRINGBUF) != end);
  puts(ANSI_NONE);
}


void trace_memory(paddr_t addr, int len , word_t data , int wr) {
  
  mringbuf[pm_cur].pc = (p_cur==0) ? iringbuf[15].pc : iringbuf[p_cur-1].pc;
  mringbuf[pm_cur].inst = (p_cur==0) ? iringbuf[15].inst : iringbuf[p_cur-1].inst;
  mringbuf[pm_cur].addr = addr;
  mringbuf[pm_cur].len = len;
  mringbuf[pm_cur].data = data;
  mringbuf[pm_cur].wr   = wr;
  pm_cur = (pm_cur + 1) % MAX_MRINGBUF;
  full_m = full_m || pm_cur == 0;
}


void display_memory() {
  if (!full_m && !pm_cur) return;

  int end_m = pm_cur;
  int i_m = full_m?pm_cur:0;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  char buf_m[128]; // 128 should be enough!
  char *pm;
  int msg2_over=0;
  do {
    if(msg2_over==0){
      printf("     the memory inst saved is:\n");
      msg2_over=1;
    }
    pm = buf_m;
    pm += sprintf(buf_m, "%s" FMT_WORD ": %08x ", (i_m+1)%MAX_MRINGBUF==end_m?" --> ":"     ", mringbuf[i_m].pc, mringbuf[i_m].inst);
    disassemble(pm, buf_m+sizeof(buf_m)-pm, mringbuf[i_m].pc, (uint8_t *)&mringbuf[i_m].inst, 4);
    if(mringbuf[i_m].wr==0)
    printf("     read from addr=%x,len=%d\n",mringbuf[i_m].addr,mringbuf[i_m].len);
    else
    printf("     write to  addr=%x,len=%d,data=%u\n",mringbuf[i_m].addr,mringbuf[i_m].len,mringbuf[i_m].data);
    if ((i_m+1)%MAX_MRINGBUF==end_m) printf(ANSI_FG_RED);
    puts(buf_m);
  } while ((i_m = (i_m+1)%MAX_MRINGBUF) != end_m);
  puts(ANSI_NONE);
}


typedef struct {
	char name[32]; // func name, 32 should be enough
	paddr_t addr;
	unsigned char info;
	Elf64_Xword size;
} SymEntry;

SymEntry *symbol_tbl = NULL; // dynamic allocated
int symbol_tbl_size = 0;
int call_depth = 0;

typedef struct tail_rec_node {
	paddr_t pc;
	paddr_t depend;
	struct tail_rec_node *next;
} TailRecNode;
TailRecNode *tail_rec_head = NULL; // linklist with head, dynamic allocated

static void read_elf_header(int fd, Elf64_Ehdr *eh) {
	assert(lseek(fd, 0, SEEK_SET) == 0);
  assert(read(fd, (void *)eh, sizeof(Elf64_Ehdr)) == sizeof(Elf64_Ehdr));

   if (eh->e_ident[EI_MAG0] != ELFMAG0 ||
        eh->e_ident[EI_MAG1] != ELFMAG1 ||
        eh->e_ident[EI_MAG2] != ELFMAG2 ||
        eh->e_ident[EI_MAG3] != ELFMAG3) {
        printf("Not an ELF file\n");
        
    }
	

	  // check if is elf using fixed format of Magic: 7f 45 4c 46 ...
  if(strncmp((char*)eh->e_ident, "\177ELF", 4)) {
		panic("malformed ELF file");
	}
}


void ftrace_write(const char *format, ...) {
    FILE *fp = fopen(OUTPUT_FILE, "a"); // 以追加模式打开文件
    if (fp != NULL) {
        va_list args;
        va_start(args, format);
        vfprintf(fp, format, args); // 使用 vfprintf() 进行格式化输出
        va_end(args);
        fclose(fp); // 关闭文件
    } else {
        printf("Error opening file %s\n", OUTPUT_FILE);
    }
}


static void display_elf_hedaer(Elf64_Ehdr eh) {
	/* Storage capacity class */
	ftrace_write("Storage class\t= ");
	switch(eh.e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			ftrace_write("32-bit objects\n");
			break;

		case ELFCLASS64:
			ftrace_write("64-bit objects\n");
			break;

		default:
			ftrace_write("INVALID CLASS\n");
			break;
	}

	/* Data Format */
	ftrace_write("Data format\t= ");
	switch(eh.e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			ftrace_write("2's complement, little endian\n");
			break;

		case ELFDATA2MSB:
			ftrace_write("2's complement, big endian\n");
			break;

		default:
			ftrace_write("INVALID Format\n");
			break;
	}

	/* OS ABI */
	ftrace_write("OS ABI\t\t= ");
	switch(eh.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			ftrace_write("UNIX System V ABI\n");
			break;

		case ELFOSABI_HPUX:
			ftrace_write("HP-UX\n");
			break;

		case ELFOSABI_NETBSD:
			ftrace_write("NetBSD\n");
			break;

		case ELFOSABI_LINUX:
			ftrace_write("Linux\n");
			break;

		case ELFOSABI_SOLARIS:
			ftrace_write("Sun Solaris\n");
			break;

		case ELFOSABI_AIX:
			ftrace_write("IBM AIX\n");
			break;

		case ELFOSABI_IRIX:
			ftrace_write("SGI Irix\n");
			break;

		case ELFOSABI_FREEBSD:
			ftrace_write("FreeBSD\n");
			break;

		case ELFOSABI_TRU64:
			ftrace_write("Compaq TRU64 UNIX\n");
			break;

		case ELFOSABI_MODESTO:
			ftrace_write("Novell Modesto\n");
			break;

		case ELFOSABI_OPENBSD:
			ftrace_write("OpenBSD\n");
			break;

		case ELFOSABI_ARM_AEABI:
			ftrace_write("ARM EABI\n");
			break;

		case ELFOSABI_ARM:
			ftrace_write("ARM\n");
			break;

		case ELFOSABI_STANDALONE:
			ftrace_write("Standalone (embedded) app\n");
			break;

		default:
			ftrace_write("Unknown (0x%x)\n", eh.e_ident[EI_OSABI]);
			break;
	}

	/* ELF filetype */
	ftrace_write("Filetype \t= ");
	switch(eh.e_type)
	{
		case ET_NONE:
			ftrace_write("N/A (0x0)\n");
			break;

		case ET_REL:
			ftrace_write("Relocatable\n");
			break;

		case ET_EXEC:
			ftrace_write("Executable\n");
			break;

		case ET_DYN:
			ftrace_write("Shared Object\n");
			break;
		default:
			ftrace_write("Unknown (0x%x)\n", eh.e_type);
			break;
	}

	/* ELF Machine-id */
	ftrace_write("Machine\t\t= ");
	switch(eh.e_machine)
	{
		case EM_NONE:
			ftrace_write("None (0x0)\n");
			break;

		case EM_386:
			ftrace_write("INTEL x86 (0x%x)\n", EM_386);
			break;

		case EM_X86_64:
			ftrace_write("AMD x86_64 (0x%x)\n", EM_X86_64);
			break;

		case EM_AARCH64:
			ftrace_write("AARCH64 (0x%x)\n", EM_AARCH64);
			break;

		default:
			ftrace_write(" 0x%x\n", eh.e_machine);
			break;
	}

	/* Entry point */
	ftrace_write("Entry point\t= 0x%08lx\n", eh.e_entry);

	/* ELF header size in bytes */
	ftrace_write("ELF header size\t= 0x%08x\n", eh.e_ehsize);

	/* Program Header */
	ftrace_write("Program Header\t= ");
	ftrace_write("0x%08lx\n", eh.e_phoff);		/* start */
	ftrace_write("\t\t  %d entries\n", eh.e_phnum);	/* num entry */
	ftrace_write("\t\t  %d bytes\n", eh.e_phentsize);	/* size/entry */

	/* Section header starts at */
	ftrace_write("Section Header\t= ");
	ftrace_write("0x%08lx\n", eh.e_shoff);		/* start */
	ftrace_write("\t\t  %d entries\n", eh.e_shnum);	/* num entry */
	ftrace_write("\t\t  %d bytes\n", eh.e_shentsize);	/* size/entry */
	ftrace_write("\t\t  0x%08x (string table offset)\n", eh.e_shstrndx);

	/* File flags (Machine specific)*/
	ftrace_write("File flags \t= 0x%08x\n", eh.e_flags);

	/* ELF file flags are machine specific.
	 * INTEL implements NO flags.
	 * ARM implements a few.
	 * Add support below to parse ELF file flags on ARM
	 */
	int32_t ef = eh.e_flags;
	ftrace_write("\t\t  ");

	if(ef & EF_ARM_RELEXEC)
		ftrace_write(",RELEXEC ");

	if(ef & EF_ARM_HASENTRY)
		ftrace_write(",HASENTRY ");

	if(ef & EF_ARM_INTERWORK)
		ftrace_write(",INTERWORK ");

	if(ef & EF_ARM_APCS_26)
		ftrace_write(",APCS_26 ");

	if(ef & EF_ARM_APCS_FLOAT)
		ftrace_write(",APCS_FLOAT ");

	if(ef & EF_ARM_PIC)
		ftrace_write(",PIC ");

	if(ef & EF_ARM_ALIGN8)
		ftrace_write(",ALIGN8 ");

	if(ef & EF_ARM_NEW_ABI)
		ftrace_write(",NEW_ABI ");

	if(ef & EF_ARM_OLD_ABI)
		ftrace_write(",OLD_ABI ");

	if(ef & EF_ARM_SOFT_FLOAT)
		ftrace_write(",SOFT_FLOAT ");

	if(ef & EF_ARM_VFP_FLOAT)
		ftrace_write(",VFP_FLOAT ");

	if(ef & EF_ARM_MAVERICK_FLOAT)
		ftrace_write(",MAVERICK_FLOAT ");

	ftrace_write("\n");

	/* MSB of flags conatins ARM EABI version */
	ftrace_write("ARM EABI\t= Version %d\n", (ef & EF_ARM_EABIMASK)>>24);

	ftrace_write("\n");	/* End of ELF header */
}

static void read_section(int fd, Elf64_Shdr sh, void *dst) {
	assert(dst != NULL);
	assert(lseek(fd, (off_t)sh.sh_offset, SEEK_SET) == (off_t)sh.sh_offset);
	assert(read(fd, dst, sh.sh_size) == sh.sh_size);
}

static void read_section_headers(int fd, Elf64_Ehdr eh, Elf64_Shdr *sh_tbl) {
	printf("e_shoff=%lx,lseek=%ld\n",eh.e_shoff,lseek(fd, eh.e_shoff, SEEK_SET));
	assert(lseek(fd, eh.e_shoff, SEEK_SET) == eh.e_shoff);
	for(int i = 0; i < eh.e_shnum; i++) {
		assert(read(fd, (void *)&sh_tbl[i], eh.e_shentsize) == eh.e_shentsize);
	}
}

static void display_section_headers(int fd, Elf64_Ehdr eh, Elf64_Shdr sh_tbl[]) {
  // warn: C99
	char sh_str[sh_tbl[eh.e_shstrndx].sh_size];
  read_section(fd, sh_tbl[eh.e_shstrndx], sh_str);
  
	/* Read section-header string-table */

	ftrace_write("========================================");
	ftrace_write("========================================\n");
	ftrace_write(" idx offset     load-addr  size       algn"
			" flags      type       section\n");
	ftrace_write("========================================");
	ftrace_write("========================================\n");

	for(int i = 0; i < eh.e_shnum; i++) {
		ftrace_write(" %03d ", i);
		ftrace_write("0x%08lx ", sh_tbl[i].sh_offset);
		ftrace_write("0x%08lx ", sh_tbl[i].sh_addr);
		ftrace_write("0x%08lx ", sh_tbl[i].sh_size);
		ftrace_write("%-4ld ", sh_tbl[i].sh_addralign);
		ftrace_write("0x%08lx ", sh_tbl[i].sh_flags);
		ftrace_write("0x%08x ", sh_tbl[i].sh_type);
		ftrace_write("%s\t", (sh_str + sh_tbl[i].sh_name));
		ftrace_write("\n");
	}
	ftrace_write("========================================");
	ftrace_write("========================================\n");
	ftrace_write("\n");	/* end of section header table */
}

static void read_symbol_table(int fd, Elf64_Ehdr eh, Elf64_Shdr sh_tbl[], int sym_idx) {
  Elf64_Sym sym_tbl[sh_tbl[sym_idx].sh_size];
  read_section(fd, sh_tbl[sym_idx], sym_tbl);
  
  int str_idx = sh_tbl[sym_idx].sh_link;
  char str_tbl[sh_tbl[str_idx].sh_size];
  read_section(fd, sh_tbl[str_idx], str_tbl);
  
  int sym_count = (sh_tbl[sym_idx].sh_size / sizeof(Elf64_Sym));
	// log
  ftrace_write("Symbol count: %d\n", sym_count);
  ftrace_write("====================================================\n");
  ftrace_write(" num    value            type size       name\n");
  ftrace_write("====================================================\n");
  for (int i = 0; i < sym_count; i++) {
    ftrace_write(" %-3d    %016lx %-4d %-10ld %s\n",
      i,
      sym_tbl[i].st_value, 
      ELF64_ST_TYPE(sym_tbl[i].st_info),
			sym_tbl[i].st_size,
      str_tbl + sym_tbl[i].st_name
    );
  }
  ftrace_write("====================================================\n\n");

	// read
	symbol_tbl_size = sym_count;
	symbol_tbl = malloc(sizeof(SymEntry) * sym_count);
  for (int i = 0; i < sym_count; i++) {
    symbol_tbl[i].addr = sym_tbl[i].st_value;
		symbol_tbl[i].info = sym_tbl[i].st_info;
		symbol_tbl[i].size = sym_tbl[i].st_size;
		memset(symbol_tbl[i].name, 0, 32);
		strncpy(symbol_tbl[i].name, str_tbl + sym_tbl[i].st_name, 31);
  }
}

static void read_symbols(int fd, Elf64_Ehdr eh, Elf64_Shdr sh_tbl[]) {
  for (int i = 0; i < eh.e_shnum; i++) {
		switch (sh_tbl[i].sh_type) {
		case SHT_SYMTAB: case SHT_DYNSYM:
			read_symbol_table(fd, eh, sh_tbl, i); break;
		}
  }
}

static void init_tail_rec_list() {
	tail_rec_head = (TailRecNode *)malloc(sizeof(TailRecNode));
	tail_rec_head->pc = 0;
	tail_rec_head->next = NULL;
}

/* ELF64 as default */
void parse_elf(const char *elf_file) {
  if (elf_file == NULL) return;
  Log("specified ELF file: %s", elf_file);
  int fd = open(elf_file, O_RDONLY|O_SYNC);
  Assert(fd >= 0, "Error %d: unable to open %s\n", fd, elf_file);
  Elf64_Ehdr eh;
  
  read_elf_header(fd, &eh);
  display_elf_hedaer(eh);



  FILE *fp;
  fp = fopen(elf_file, "rb");
  Assert(fp!=NULL,"%d\n",1);
  Elf64_Ehdr eh2;
  int fread_re;
  fread_re=fread(&eh2, sizeof(Elf64_Ehdr), 1, fp);
  printf("fread_re=%d\n",fread_re);
  printf("eh2_shoff=%lx\n",eh2.e_shoff);
  int is_big_endian = (eh2.e_ident[EI_DATA] == ELFDATA2MSB);
  printf("is_big_endian=%d\n",is_big_endian);
  printf("match=%d",is_big_endian != (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__));
  printf("eh2_shoff_small_endian=%lx\n",__builtin_bswap64(eh2.e_shoff));




  Elf64_Shdr sh_tbl[eh.e_shentsize * eh.e_shnum];
  
	read_section_headers(fd, eh, sh_tbl);
  display_section_headers(fd, eh, sh_tbl);

  read_symbols(fd, eh, sh_tbl);

	init_tail_rec_list();

	close(fd);
}

static int find_symbol_func(paddr_t target, bool is_call) {
	int i;
	for (i = 0; i < symbol_tbl_size; i++) {
		if (ELF64_ST_TYPE(symbol_tbl[i].info) == STT_FUNC) {
			if (is_call) {
				if (symbol_tbl[i].addr == target) break;
			} else {
				if (symbol_tbl[i].addr <= target && target < symbol_tbl[i].addr + symbol_tbl[i].size) break;
			}
		}
	}
	return i<symbol_tbl_size?i:-1;
}

static void insert_tail_rec(paddr_t pc, paddr_t depend) {
	TailRecNode *node = (TailRecNode *)malloc(sizeof(TailRecNode));
	node->pc = pc;
	node->depend = depend;
	node->next = tail_rec_head->next;
	tail_rec_head->next = node;
}

static void remove_tail_rec() {
	TailRecNode *node = tail_rec_head->next;
	tail_rec_head->next = node->next;
	free(node);
}

void trace_func_call(paddr_t pc, paddr_t target, bool is_tail) {
	if (symbol_tbl == NULL) return;

	++call_depth;

	if (call_depth <= 2) return; // ignore _trm_init & main

	int i = find_symbol_func(target, true);
	ftrace_write(FMT_PADDR ": %*scall [%s@" FMT_PADDR "]\n",
		pc,
		(call_depth-3)*2, "",
		i>=0?symbol_tbl[i].name:"???",
		target
	);

	if (is_tail) {
		insert_tail_rec(pc, target);
	}
}

void trace_func_ret(paddr_t pc) {
	if (symbol_tbl == NULL) return;
	
	if (call_depth <= 2) return; // ignore _trm_init & main

	int i = find_symbol_func(pc, false);
	ftrace_write(FMT_PADDR ": %*sret [%s]\n",
		pc,
		(call_depth-3)*2, "",
		i>=0?symbol_tbl[i].name:"???"
	);
	
	--call_depth;

	TailRecNode *node = tail_rec_head->next;
	if (node != NULL) {
		int depend_i = find_symbol_func(node->depend, true);
		if (depend_i == i) {
			paddr_t ret_target = node->pc;
			remove_tail_rec();
			trace_func_ret(ret_target);
		}
	}
}

