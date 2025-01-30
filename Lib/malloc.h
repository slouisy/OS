#ifndef MALLOC_H
#define MALLOC_H

struct Block;

struct Block {
    int size;
    bool free;
    Block* next;
};

static Block* Heap_List = nullptr;
void* malloc(int size);
void free(void* ptr);

#endif