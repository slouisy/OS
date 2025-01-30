#ifndef VGA_H
#define VGA_H

class VGA {
public:
    static int width;
    static int height;
    static unsigned short *mem_adress;
    // Function to initialize VGA text mode (80x25)
    static void clear(int color = 0);
    static void place_char(short row, short coloumn, char c, char color);
};

#endif