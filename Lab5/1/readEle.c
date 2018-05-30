#include "interface1.h"
#include <stdlib.h>
#include <stdio.h>

Element* readFromFile(FILE *f){
	Element *list = newList(33);
	while(!feof(f)){
		/*char *record=NULL;
		size_t len = 0;
		ssize_t read;
		read=getline(&record,&len,f);
		if (read==-1) break;
		char* name = strtok(record,",");
		float cg = strtof(strtok(NULL,","),NULL);*/
		char *n=(char*)malloc(20*sizeof(char));
		float cg;
		fscanf(f,"%s", n);
		fscanf(f, "%f",&cg);
		list = addEle(list, n, cg);
	}
	return list;
}

