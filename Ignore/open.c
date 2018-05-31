#include <stdio.h>
#include <stdlib.h>
struct HT{
	int size;
	int arr[];
}

int hash(int key){
	return (key*13 + 19)%23;
}

int getAddr(int computed, int key, int j){
	return (computed +j)mod 23;
}

void insert(HT,elem){
	int index = hash(elem->key);
	if(isFull(HT)) return;
	if(HT->arr
}
