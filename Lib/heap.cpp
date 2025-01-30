#include "heap.h"

char* Heap::start = (char*)HEAP_START;
char* Heap::position = Heap::start;
char* Heap::end = (char*)HEAP_END;