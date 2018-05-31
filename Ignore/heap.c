#include "heap.h"
int findMin(Heap *h){
	return h->contents[0];
}

Heap* buildHeap(int *arr){
	Heap *h=(Heap*)malloc(sizeof(Heap));
	h->contents=(int*)malloc(sizeof(int)*(sizeof(arr)/sizeof(arr[0])));
	for(int j=sizeof(arr)/(sizeof(arr[0])*2); j>=0; j--){
		minHeapify(h,h->last,j);
	}
}

void HeapSort(int *arr){
	Heap *h=buildHeap(arr);
	int size=h->last;
	for(int j=h->last; j>=0; j--){
		swapArr(h->contents, 0, j);
		size=size-1;
		minHeapify(h, size-1 , 0);
	}
}
