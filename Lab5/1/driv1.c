#include "interface1.h"
#include <sys/time.h>
int main(){
	struct timeval t1,t2;
	double elapsedTime;
	FILE *ptr;
	ptr=fopen("1638400.txt","r");
	Element *l=readFromFile(ptr);
	gettimeofday(&t1,NULL);
	mergeSort(l, 0, l->size-1);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time is %f ms.\n", elapsedTime);
	//for(int i=0; i<l->size;i++) printf("%f\n", l->arr[i]->CGPA);
	fclose(ptr);
	return 0;
}
