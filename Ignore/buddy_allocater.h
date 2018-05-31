#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int no_of_sections;
	int block_size;
	PTR *list;
}FreeList;

void* malloc(size_t size);
void free(void *ptr);
