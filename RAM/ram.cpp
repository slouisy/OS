#include"ram.h"

int RAM::size = 0;

void RAM::init(multiboot_info_t *mb_info) {
   int mem_lower = mb_info->mem_lower;  // Low memory (below 1MB)
   int mem_upper = mb_info->mem_upper;  // High memory (above 1MB)

   int total_mem_kb = mem_lower + (mem_upper * 1024);
   size = total_mem_kb;
}