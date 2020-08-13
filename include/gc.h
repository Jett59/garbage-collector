#ifndef include_gc_header
#define include_gc_header "garbage collector"
#include <stdlib.h>
void gcInit();
void* alloc(size_t size);
void release(void* ptr);
void* ralloc(void* ptr, size_t newSize);
void gc();
#endif