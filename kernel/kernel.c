#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>
#include <arch/i386/tty.h>
#include <asm.h>
#include <devices/kb.h>
#include <devices/timer.h>
#include <external/multiboot.h>
#include <libk/heap.h>
#include <libk/phys_mem.h>
#include <libk/virt_mem.h>
#include <test/hashmap_test.h>
#include <test/heap_test.h>
#include <test/macros_test.h>
#include <test/phys_mem_test.h>
#include <test/vector_test.h>

void kernel_early(struct multiboot_info* mb) {
  terminal_initialize();
  gdt_install();
  idt_install();

  phys_memory_init(mb);
  virt_memory_init();
  kernel_heap_init();

  timer_install();
  keyboard_install();
  enable_interrupts();
}



void kernel_main(void) {

  printf("Menu \n\n1. Calculadora \n2.Hacer sonido \n3. Apagar equipo\n");

  for(;;){
    asm("hlt");
  }  


	
	
  
}
