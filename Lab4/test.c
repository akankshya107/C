#include "fread.h"
#include <string.h>
#include <stdlib.h>
FILE* inputDistri(FILE *f, char *x){
	if(strcmp(x, "duplicate")==0)	return duplicates(f);
	else if(strcmp(x, "single")==0) return single(f);
	else if(strcmp(x,"sorted")==0) return sorted(f);
	else if(strcmp(x,"reverse")==0) return reverse(f);
	else return NULL;
}

FILE* duplicates(FILE *f){
	FILE *ptr=fopen("new","w+");
	while(!feof(f)){
		int x = rand()%6;
		char *line=(char*)malloc(sizeof(char)*30);
		fscanf(f, "%s", line);
		while(x){
			fprintf(ptr, "%s\n", line);
			x--;
		}
	}
	fseek(ptr,0, SEEK_SET);
	return ptr;
}

FILE* single(FILE *f){
	FILE *ptr=fopen("new","w+");
	char *line=(char*)malloc(sizeof(char)*30);
	fscanf(f, "%s", line);
	int x=100;
	while(x){
		fprintf(ptr,"%s\n", line);
		x--;
	}
	fseek(ptr,0, SEEK_SET);
	return ptr;
}

FILE* sorted(FILE *f){
	FILE *ptr=fopen("new","w+");
	Array *a=readFromFile(f);
	a=insertionSort(a, a->no_of_rec);
	for(int i=0; i<a->no_of_rec; i++){
		fprintf(ptr,"%s,%s,%s,%s,%s\n",a->arr[i]->cd,a->arr[i]->bc,a->arr[i]->ed,a->arr[i]->fn,a->arr[i]->ln);
	}
	fseek(ptr,0, SEEK_SET);
	return ptr;
}

FILE* reverse(FILE *f){
	FILE *ptr=fopen("new","w+");
	Array *a=readFromFile(f);
	a=insertionSort(a, a->no_of_rec);
	for(int i=a->no_of_rec-1; i>0; i--){
		fprintf(ptr,"%s,%s,%s,%s,%s",a->arr[i]->cd,a->arr[i]->bc,a->arr[i]->ed,a->arr[i]->fn,a->arr[i]->ln);
	}
	fseek(ptr,0, SEEK_SET);
	return ptr;
}

