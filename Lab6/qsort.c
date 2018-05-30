#include "qs.h"
void quickSort(List *l, int s){
	Stack *stack=newStack(l->no_of_rec);
	int lo,hi;
	push(stack, 0);
	push(stack,(l->no_of_rec)-1);
	while(stack->top>=0){
		hi=pop(stack);
		lo=pop(stack);
		printf("%d\n", hi-lo+1);
		if (hi-lo+1<s) return insertionSort(l, lo, hi);
		//int p=rand()%(l->no_of_rec);
		int p=partition(l, lo, hi);
		if (p==lo || p==hi){
			continue;
		}
		if(p-lo>lo){
			push(stack,lo);
			push(stack,p-lo);
		}
		if(p+lo<hi){
			push(stack,p+lo);
			push(stack,hi);
		}
	}
}

int partition(List *l, int lo, int hi){
	long unsigned int p=l->arr[hi]->empID;
	int i=lo;
	for(int j=lo; j<hi; j++){
		if(l->arr[j]->empID<=p){
			Record *rec=l->arr[i];
			l->arr[i]=l->arr[j];
			l->arr[j]=rec;
			i++;
		}
	}
	Record *rec=l->arr[i];
	l->arr[i]=l->arr[hi];
	l->arr[hi]=rec;
	return i;
}

