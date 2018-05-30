#include "ex2.h"
#include <stdio.h>
#include <stdlib.h>
int main(void){
	init();
	//extern Allocated *spaceAllocated;
	int x=1;
	while(x<10){
		int M = (rand()%150)+100;
		int *arr = (int*)myalloc(M*sizeof(int));
		printf("%u\n", spaceAllocated->tsize);
		if (arr==NULL) break;
		printf("start=%u\n", &arr[0]);
		printf("end=%u\n", &arr[M-1]);
		//myfree(arr);
		//printf("%d\n", spaceAllocated);
		printf("%d\n", x);
		x++;
	}
	return 0;
}
