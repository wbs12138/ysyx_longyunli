ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  ROM : ORIGIN = 0x20000000 , LENGTH = 4K
  RAM : ORIGIN = 0x0f000000 , LENGTH = 8K
}

REGION_ALIAS("REGION_TEXT",ROM);

REGION_ALIAS("REGION_RODATA",ROM);

REGION_ALIAS("REGION_DATA",RAM);

REGION_ALIAS("REGION_BSS",RAM);

SECTIONS {
  . =  0xf001ffc;
  _stack_pointer = .;
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;
  .text : {
    *(entry)
    *(.text*)
  } > REGION_TEXT :text
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
    rodata_end = .;
  } > REGION_RODATA
  .data : AT (rodata_end){
    data_start = .;
    *(.data)
  } > REGION_DATA :data
  data_size = SIZEOF(.data);

  data_load_start = LOADADDR(.data);
  edata = .;
  _data = .;
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > REGION_BSS
}
