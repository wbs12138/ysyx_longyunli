ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  FLASH : ORIGIN = 0x30000000 , LENGTH = 256M
  RAM :   ORIGIN = 0x0f000000 , LENGTH = 8K
  PSRAM : ORIGIN = 0x80000000 , LENGTH = 4M
}

SECTIONS {
  . =  0xf002000 ;
  _stack_pointer = . ;
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;
  .text : {
    *(entry)
    *(.text*)
    . = ALIGN(4);
  } > FLASH :text

  .rodata : {
    *(.rodata*)
    . = ALIGN(4);
  } >FLASH

  .data : {
    data_start = .;
    *(.data)
    *(.data*)
    *(.sdata)
    *(.sdata*)
    . = ALIGN(4);
    data_end = .;
  } > PSRAM AT>FLASH :data

  _heap_start = . + 4 ;

  data_size = data_end - data_start ;

  data_load_start = LOADADDR(.data);

  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
  } > PSRAM
}
