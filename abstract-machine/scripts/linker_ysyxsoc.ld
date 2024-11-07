ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  ROM : ORIGIN = 0x30000000 , LENGTH = 260000K
  RAM : ORIGIN = 0x0f000000 , LENGTH = 8K
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
  } > ROM :text

  .rodata : {
    *(.rodata*)
    . = ALIGN(4);
  } >ROM

  .data : {
    data_start = .;
    *(.data)
    *(.data*)
    *(.sdata)
    *(.sdata*)
    . = ALIGN(4);
    data_end = .;
  } > RAM AT>ROM :data

  data_size = data_end - data_start ;

  data_load_start = LOADADDR(.data);

  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
  } > RAM
}
