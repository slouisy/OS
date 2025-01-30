#include "vga.h"

int VGA::width = 80;
int VGA::height = 25;

unsigned short * VGA::mem_adress = (unsigned short *)0xB8000;

void VGA::clear(int color) {
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned short *position = mem_adress + (i * width) + j;
            char blank = ' ';
            *position = (color << 8) | blank;
        }
    }
} 

void VGA::place_char(short row, short column, char c, char color) {
    if((column < width) && (row <  height)) {
        unsigned short *position = mem_adress + (row * width) + column;
        *position = (color << 8) | c;
    }
}