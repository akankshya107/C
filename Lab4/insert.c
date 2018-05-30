#include "fread.h"
#include <string.h>
#include <stdio.h>
Array* insertInOrder(Array *a, Record *r, int size){
	int pos=size;
	int i=0;
	while(i<size){
		if(strcmp(a->arr[i]->cd,r->cd)>0){
			pos=i;
			break;
		}
		else i++;
	}
	int j=size;
	while(j>pos && pos!=size){
		a->arr[j]=a->arr[j-1];
		j--;
	}
	a->arr[pos]=r;
	return a;
}

Array* insertionSort(Array *a, int size){
	if(size>1){
		a=insertionSort(a,size-1);
		a=insertInOrder(a, a->arr[size-1], size-1);
	}
	return a;
}
