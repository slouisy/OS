#ifndef CONSOLE_H
#define CONSOLE_C

#include "../Lib/string.h"

class Console {
private:
    static short x, y;
    static bool cursor_bottom();
    static bool cursor_end();
public:
    static void print(String text);   
    static void print(const char* text, short color);
    static void newLine();
};
#endif