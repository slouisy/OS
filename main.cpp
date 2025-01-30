#include "Console/console.h"
#include "Drivers/VGA/vga.h"

#include "RAM/ram.h"

extern "C" void main(multiboot_info_t *mb_info) {
    //asm volatile("sti");
    RAM::init(mb_info);

    VGA::clear();
    Console::print("Hello World", 6);
    Console::newLine();
    String tester("Colombia");
    Console::print(tester.getData(), 15);

    String test(RAM::size);
    Console::print(test.getData(), 9);
        
    while (1) {
        
    }
}
