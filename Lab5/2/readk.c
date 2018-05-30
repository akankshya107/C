#include "interface1.h"
#include <stdlib.h>
int divideSortedFiles(FILE *pr){
	FILE *pw;
	int k=1024;
	int i=0;
	while(!feof(pr)){
		i++;
		Element *l=readFromFile(pr, k);
		mergeSort(l, 0, k-1);
		if(l->arr[0]->Name==NULL){
			i--;
			break;
		}
		char *filename=(char*)malloc(sizeof(char)*15);
		sprintf(filename, "output%03d.txt", i);
		pw=fopen(filename,"w");
		for(int j=0; j<k; j++){
			fprintf(pw, "%s %f\n", l->arr[j]->Name, l->arr[j]->CGPA);
		}
		fclose(pw);
	}
	return i;
}
