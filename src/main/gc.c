#include <stdio.h>
#include <stdlib.h>

void** gcMem;
void** gcMemScanner;
size_t availible;
size_t capacity;
size_t used;

void gcInit()
{
    capacity = 512;
    gcMem = malloc(capacity*sizeof(void*));
    if(gcMem == NULL)
    {
        fprintf(stderr, "gc error: unable to initialise garbage collector: allocation failed\n");
        exit(-1);
    }
    availible = capacity;
    gcMemScanner = gcMem;
}
void* alloc(size_t size)
{
    void* ptr = malloc(size);
    *gcMemScanner = ptr;
    used++;
    availible--;
    if(availible == 0)
    {
        capacity = capacity*2;
        availible = capacity-used;
        gcMem = realloc(gcMem, capacity);
        gcMemScanner = gcMem+used;
    }
    return ptr;
}
void release(void* ptr)
{
    void** gcMemReleaseScanner = gcMem;
    for(size_t pos = 0; pos < used; pos++)
    {
        if(*gcMemReleaseScanner == ptr)
        {
            *gcMemReleaseScanner = NULL;
        }
    }
    free(ptr);
}
void* ralloc(void* ptr, size_t newSize)
{
    void* newPtr = realloc(ptr, newSize);
    void** gcMemRallocScanner = gcMem;
    for(size_t pos = 0; pos < used; pos++)
    {
        if(*gcMemRallocScanner == ptr)
        {
            *gcMemRallocScanner = newPtr;
        }
    }
    return newPtr;
}
void gc()
{
    gcMemScanner = gcMem;
    for(size_t pos = 0; pos < used; pos++)
    {
        if(*gcMemScanner != NULL)
        {
            free(*gcMemScanner);
        }
        gcMemScanner++;
    }
    free(gcMem);
}