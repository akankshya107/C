#define ELE
#include "ex2.h"
#include <stdio.h>
#include <stdlib.h>
void* myalloc(unsigned int size){
	void *x = malloc(sizeof(int) + size);
	static int *s;
	s=(int*)x;
	*s=size;
	spaceAllocated+=sizeof(int) + size;
	return (x+sizeof(int));
}

void myfree(void *ptr){
	int *size = (((int*)ptr)-1);
	spaceAllocated-=(*size)+sizeof(int);
	free(size);
}

/*int main(void){
	int *p=(int*)myalloc(sizeof(int));
	printf("%d\n", spaceAllocated);
	*p=3;
	myfree(p);
	printf("%d\n", spaceAllocated);
	return 0;
}*/
