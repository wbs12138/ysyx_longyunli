ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  ROM : ORIGIN = 0x20000000 , LENGTH = 4K
  RAM : ORIGIN = 0x0f000000 , LENGTH = 8K
}

SECTIONS {
  . =  0xf001fff;
  _stack_pointer = .;
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;
  .text : {
    *(entry)
    *(.text*)
  } > ROM AT>ROM :text
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
  } >ROM AT>ROM

  .data : {
    data_start = .;
    *(.data)
  } > RAM AT>ROM :data

  data_size = SIZEOF(.data);

  data_load_start = LOADADDR(.data);

  edata = .;
  _data = .;
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  }
}
