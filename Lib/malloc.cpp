#include "malloc.h"
#include "heap.h"

void* malloc(int size) {
    Block* current = Heap_List;
    Block* prev = nullptr;
   
    while(current) {
        if (current->free && (current->size >= size)) {
            current->free = false;
            int requested_block_size = size + sizeof(Block);
            int remaining_size = current->size - requested_block_size;
            if (remaining_size > sizeof(Block)) {
                Block* newFreeBlock = (Block*)((char*)current + requested_block_size);
                newFreeBlock->size = remaining_size;
                newFreeBlock->free = true;
                newFreeBlock->next = current->next;
                current->size = size;
                current->next = newFreeBlock;
            }
            return (void*)((char*)current + sizeof(Block));
        }
        prev = current;
        current = current->next;
    }

    /*check for heap overflow*/
    if ((Heap::position + sizeof(Block) + size) > (char*)HEAP_END) {
        return nullptr;  // Prevent heap overflow
    }


    Block* newBlock = (Block*)(Heap::position);
    newBlock->size = size;
    newBlock->free = false;
    newBlock->next = nullptr;

    if(prev) {
        prev->next = newBlock;
    }
    Heap::position += sizeof(Block) + size;
    return (void*)((char*)newBlock + sizeof(Block));

}

void free(void* ptr) {
    if(!ptr) {return;}

    Block* block = (Block*)((char*)ptr - sizeof(Block));
    if(block->free = true) {return;}
    block->free = true;

    Block* current = Heap_List;
    while (current) {
        if ((current->free) && (current->next) && (current->next->free)) {
            current->size += sizeof(Block) + current->next->size;
            current->next = current->next->next;
        }
        current = current->next;
    }
}