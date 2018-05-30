#include "qs.h"
void insertionSort(List *l, int lo, int hi){
	for (int i=lo+1; i<=hi; i++){
		Record *r=l->arr[i];
		long unsigned int key = r->empID;
		int j=i-1;
		while(j>=0 && l->arr[j]->empID>key){
			l->arr[j+1]=l->arr[j];
			j--;
		}
		l->arr[j+1]=r;
	}
}
