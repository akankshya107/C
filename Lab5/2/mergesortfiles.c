#include "interface1.h"
#include <stdlib.h>
void mergesortfiles(FILE *f){
	int k = divideSortedFiles(f);
	char *filenameo=(char*)malloc(sizeof(char)*15);
	char *filename1=(char*)malloc(sizeof(char)*15);
	char *filename2=(char*)malloc(sizeof(char)*15);
	
	for(int i=1; i<k; i++){
		sprintf(filenameo, "output%04d.txt", i);
		FILE *out=fopen(filenameo,"w+");
		
		if (i==1)sprintf(filename1, "output%03d.txt", i);
		else sprintf(filename1, "output%04d.txt", i-1);
		FILE *p1=fopen(filename1,"r");
		
		sprintf(filename2, "output%03d.txt", i+1);
		FILE *p2=fopen(filename2,"r");

		mergeFiles(p1,p2,out);

		remove(filename2);
		remove(filename1);
		fclose(out);
	}
}
