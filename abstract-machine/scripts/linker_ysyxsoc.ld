ENTRY(_start)
PHDRS { entry PT_LOAD ;text PT_LOAD; rodata PT_LOAD; data PT_LOAD;}

MEMORY {
  FLASH (rx): ORIGIN = 0x30000000 , LENGTH = 16M
  RAM   (rwx): ORIGIN = 0x0f000000 , LENGTH = 8K
  PSRAM (rwx): ORIGIN = 0x80000000 , LENGTH = 4M
}


SECTIONS {
  . =  0xf002000 ;
  _stack_pointer = . ;
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;
  
  .entry : {
    *(entry)
    . = ALIGN(4);
  } >PSRAM AT>FLASH :entry
  
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
  } >PSRAM AT>FLASH :rodata

  rodata_size = rodata_end - rodata_start ;

  rodata_load_start = LOADADDR(.rodata);

  .data.extra : {
    data_start = .;
    /* section information for finsh shell */
    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(8);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(8);

    /* section information for initial. */
    . = ALIGN(8);
    __rt_init_start = .;
    KEEP(*(SORT(.rti_fn*)))
    __rt_init_end = .;
    . = ALIGN(8);

    __rt_utest_tc_tab_start = .;
    KEEP(*(UtestTcTab))
    __rt_utest_tc_tab_end = .;

    . = ALIGN(8);
    __am_apps_data_start = .;
    *(__am_apps.data*)
    *(__am_apps.sdata*)
    __am_apps_data_end = .;
    . = ALIGN(8);
  } >PSRAM AT>FLASH :data

  .data : {
    *(.data)
    *(.data*)
    *(.sdata)
    *(.sdata*)
    data_end = .;
    . = ALIGN(4);
  } >PSRAM AT>FLASH :data

  data_size = data_end - data_start ;

  data_load_start = LOADADDR(.data.extra);

  .bss.extra : {
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
  } >PSRAM

  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
  } >PSRAM

  _heap_start = . ;
}
