#include "interface1.h"
#include <stdlib.h>
#include <stdio.h>

Element* readFromFile(FILE *f, int k){
	Element *list = newList(k);
	int x=0;
	while(x<k){
		Record *rec = readRec(f);
		list = addEle(list, rec->Name, rec->CGPA);
		x++;
	}
	return list;
}

Record* readRec(FILE *f){
	Record *r=newRec();
	if(!feof(f)){
		char *n=(char*)malloc(20*sizeof(char));
		float cg;
		fscanf(f,"%s", n);
		fscanf(f, "%f",&cg);
		r->Name=n;
		r->CGPA=cg;
	}
	return r;
}
