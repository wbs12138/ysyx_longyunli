ENTRY(_start)
PHDRS { trm_init PT_LOAD ;entry PT_LOAD ;text PT_LOAD; data PT_LOAD; rodata PT_LOAD; }

MEMORY {
  FLASH : ORIGIN = 0x30000000 , LENGTH = 256M
  RAM   : ORIGIN = 0x0f000000 , LENGTH = 8K
  PSRAM : ORIGIN = 0x80000000 , LENGTH = 4M
}

SECTIONS {
  . =  0xf002000 ;
  _stack_pointer = . ;
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;

  .entry : {
    KEEP(*(_trm_init))
    . = ALIGN(4) ;
  } > FLASH :entry

  .trm_init : {
    KEEP(*(_trm_init))
    . = ALIGN(4) ;
  } > FLASH :trm_init

  .text : {
    text_start = .;
    *(.text .text.*)
    . = ALIGN(4);
    text_end = .;
  } >PSRAM AT>FLASH :text

  text_size = text_end - text_start ;

  text_load_start = LOADADDR(.text);

  . = .+4;

  .rodata : {
    rodata_start = . ;
    *(.rodata*)
    . = ALIGN(4);
    rodata_end = .;
  } >PSRAM AT>FLASH :rodata

  rodata_size = rodata_end - rodata_start ;

  rodata_load_start = LOADADDR(.rodata);

  . = .+4;

  .data : {
    data_start = .;
    *(.data)
    *(.data*)
    *(.sdata)
    *(.sdata*)
    . = ALIGN(4);
    data_end = .;
  } > PSRAM AT>FLASH :data

  data_size = data_end - data_start ;

  data_load_start = LOADADDR(.data);

  . = .+4;

  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
  } > PSRAM

  _heap_start = . + 4 ;
}
