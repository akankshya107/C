#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *contents;
	int last;
}Heap;

int findMin(Heap *h);
void deleteMin(Heap *h);
void insert(Heap *h, int val);
Heap* buildHeap(int *arr);
void minHeapify(Heap *h, int index);
