#ifndef RAM_H
#define RAM_H

typedef struct {
   int size;
   int base_addr_low;
   int base_addr_high;
   int length_low;
   int length_high;
   int type;
} __attribute__((packed)) multiboot_memory_map_t;

// Multiboot information structure (partial)
typedef struct {
   int flags;
   int mem_lower;
   int mem_upper;
   int mmap_length;
   int mmap_addr;
} __attribute__((packed)) multiboot_info_t;

class RAM {
public:
    static int size;
    static void init(multiboot_info_t *mb_info);
};
#endif