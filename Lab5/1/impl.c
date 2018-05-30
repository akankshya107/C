#include "interface1.h"
#include <stdlib.h>

Element* newList(int size){
	Element *l = (Element*)malloc(sizeof(Element)+sizeof(Record*)*size);
	for (int i=0; i<size; i++){
		l->arr[i]=newRec();
	}
	l->size=size;
	l->no_of_rec=0;
	return l;
}

Record* newRec(){
	Record *r=(Record*)malloc(sizeof(Record));
	r->Name=NULL;
	r->CGPA=0;
	return r;
}

Element* addEle(Element* l, char* name, float cg){
	if (l->size!=l->no_of_rec){
		l->arr[l->no_of_rec]->Name=name;
		l->arr[l->no_of_rec]->CGPA=cg;
	}
	else{
		l=resizeList(l,l->size);
		l->arr[l->no_of_rec]->Name=name;
		l->arr[l->no_of_rec]->CGPA=cg;
	}
	(l->no_of_rec)++;
	return l;
}

Element* resizeList(Element *l, int size){
	l=realloc(l, sizeof(Element)+(sizeof(Record*))*size*2);
	l->size=size*2;
	for(int i=size; i<size*2; i++){
		l->arr[i]=newRec();
	}
	return l;
}


