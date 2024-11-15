ENTRY(_start)
PHDRS { entry PT_LOAD ;text PT_LOAD; rodata PT_LOAD; data PT_LOAD; bss PT_LOAD; boot_loader PT_LOAD; fsbl PT_LOAD;}

MEMORY {
  FLASH (rx): ORIGIN = 0x30000000 , LENGTH = 16M
  RAM   (rwx): ORIGIN = 0x0f000000 , LENGTH = 8K
  PSRAM (rwx): ORIGIN = 0x80000000 , LENGTH = 4M
  SDRAM (rwx): ORIGIN = 0xa0000000 , LENGTH = 32M
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

  .fsbl : {
    *(.fsbl*)
  } >FLASH :fsbl

  .bootloader : {
    _bootloader_start = .;
    *(.bootloader*)
    _bootloader_end = .;
  } >RAM AT >FLASH :boot_loader

  _bootloader_size = _bootloader_end - _bootloader_start ;

  _bootloader_load_start = LOADADDR(.bootloader);
  
  .text : {
    _text_start = .;
    *(.text*)
    _text_end = .;
    . = ALIGN(4);
  } >PSRAM AT>FLASH :text

  _text_size = _text_end - _text_start ;

  _text_load_start = LOADADDR(.text);

  .rodata : {
    _rodata_start = . ;
    *(.rodata*)
    *(.srodata*)
    _rodata_end = .;
    . = ALIGN(4);
  } >PSRAM AT>FLASH :rodata

  _rodata_size = _rodata_end - _rodata_start ;

  _rodata_load_start = LOADADDR(.rodata);

  .data : {
    _data_start = .;
    *(.data)
    *(.data*)
    *(.sdata)
    *(.sdata*)
    _data_end = .;
    . = ALIGN(4);
  } >PSRAM AT>FLASH :data

  _data_size = _data_end - _data_start ;

  _data_load_start = LOADADDR(.data);

  .bss : {
	  _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
  } >PSRAM 
  /* AT>PSRAM need this or not ? TODO!!!!! */

  _heap_start = . ;
}
