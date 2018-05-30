#include "interface1.h"
#include <sys/time.h>
int main(int argc, const char* argv[]){
	struct timeval t1,t2;
	double elapsedTime;
	FILE *ptr;
	ptr=fopen("10240.txt","r");
	//Element *l=readFromFile(ptr, 1024);
	gettimeofday(&t1,NULL);
	//mergeSort(l, 0, l->size-1);
	mergesortfiles(ptr);
	//divideSortedFiles(ptr);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time is %f ms.\n", elapsedTime);
	/*FILE *o = fopen("output.txt","w");
	for(int i=0; i<l->no_of_rec;i++){
		fprintf(o, "%s %f\n", l->arr[i]->Name, l->arr[i]->CGPA);
	}
	fclose(o);
	for(int i=0; i<l->size;i++) printf("%f\n", l->arr[i]->CGPA);*/
	printf("lollll");
	fclose(ptr);
	return 0;
}
