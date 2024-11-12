ENTRY(_start)
PHDRS { entry PT_LOAD ;text PT_LOAD; rodata PT_LOAD; data PT_LOAD;}


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
    *(.srodata*)
    rodata_end = .;
    . = ALIGN(4);
  } >PSRAM AT>FLASH :rodata

  rodata_size = rodata_end - rodata_start ;

  rodata_load_start = LOADADDR(.rodata);

  .data : {
    data_start = .;
    *(.data)
    *(.data*)
    *(.sdata)
    *(.sdata*)
    data_end = .;
    . = ALIGN(4);
  } >PSRAM AT>FLASH :data

  data_size = data_end - data_start ;

  data_load_start = LOADADDR(.data);

  .bss : {
	  _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
  } >PSRAM

  _heap_start = . ;
}
