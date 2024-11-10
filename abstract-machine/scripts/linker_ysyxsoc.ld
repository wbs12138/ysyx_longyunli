ENTRY(_start)
PHDRS { entry PT_LOAD ;text PT_LOAD; rodata PT_LOAD; data PT_LOAD; }

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
    *(entry)
    . = ALIGN(4);
  } >FLASH :entry
  
  .text : {
    text_start = .;
    *(.text*)
    text_end = .;
    . = ALIGN(4);
  } >PSRAM AT>FLASH :text

  text_size = text_end - text_start ;

  text_load_start = LOADADDR(.text);

  .rodata : {
    rodata_start = . ;
    *(.rodata*)
    rodata_end = .;
    . = ALIGN(4);
    _end_rodata = .;
  } >PSRAM AT>FLASH :rodata

  rodata_size = rodata_end - rodata_start ;

  rodata_load_start = LOADADDR(.rodata);

  .data : {
    data_start = _end_rodata;
    *(.data)
    *(.data*)
    *(.sdata)
    *(.sdata*)
    data_end = .;
    . = ALIGN(4);
    _end_data = .;
  } >PSRAM AT>FLASH :data

  data_size = data_end - data_start ;

  data_load_start = LOADADDR(.data);

  .bss : {
	_bss_start = _end_data;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
  } >PSRAM

  _heap_start = . ;
}
