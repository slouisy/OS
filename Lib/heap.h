#ifndef HEAP_H
#define HEAP_H

#define HEAP_START 0x00500000
#define HEAP_END 0x067FFFFF

class Heap {
public:
    static int size;
    static char *start;
    static char *position;
    static char* end;
};

#endif