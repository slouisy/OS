#include "console.h"
#include "../Drivers/VGA/vga.h"

short Console::x = 0;
short Console::y = 0;

bool Console::cursor_bottom() {
    if(y == (VGA::height - 1)) {
        return true;
    }
    return false;
}

bool Console::cursor_end() {
    if(x == (VGA::width - 1)) {
        return true;
    }
    return false; 
}

void Console::print(String text) {

}

void Console::print(const char* text, short color) {
    while(*text != '\0') {
        VGA::place_char(y, x, *(text), color);
        text++;
        if(cursor_end()){
            x = 0;
            if(cursor_bottom()) {
                y = 0;
            } else {
                y++;
            }
        } else {
            x++;
        }
    }
}

void Console::newLine() {
     y = (cursor_bottom()) ? 0 : y + 1;
     x = 0;
}