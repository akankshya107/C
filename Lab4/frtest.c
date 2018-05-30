#include "fread.h"
#include <stdio.h>
#include <sys/time.h>
int main(int argc, char* argv[]){
	struct timeval t1, t2;
	double elapsedTime;
	FILE *p;
	p=fopen(argv[1] ,"r");
	FILE *ptr=inputDistri(p, argv[2]);
	if(ptr!=NULL) {
		Array *a = readFromFile(ptr);
		gettimeofday(&t1, NULL);
		a=insertionSort(a,a->no_of_rec);
		gettimeofday(&t2, NULL);
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
		printf("Total time is %f ms.\n", elapsedTime);
	}
	return 0;
}
