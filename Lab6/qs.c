#include "qs.h"
#include <stdlib.h>
List* newList(int size){
	List *l = (List*)malloc(sizeof(List)+sizeof(Record*)*size);
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
	r->empID=0;
	return r;
}
List* addRec(List* l, Record *r){
	if (l->size!=l->no_of_rec){
		l->arr[l->no_of_rec]->Name=r->Name;
		l->arr[l->no_of_rec]->empID=r->empID;
	}
	else{
		l=resizeList(l,l->size);
		l->arr[l->no_of_rec]->Name=r->Name;
		l->arr[l->no_of_rec]->empID=r->empID;
	}
	(l->no_of_rec)++;
	return l;
}

List* resizeList(List *l, int size){
	l=realloc(l, sizeof(List)+(sizeof(Record*))*size*2);
	l->size=size*2;
	for(int i=size; i<size*2; i++){
		l->arr[i]=newRec();
	}
	return l;
}

Record* readRec(FILE *f){
	Record *r=newRec();
	if(!feof(f)){
		char *n=(char*)malloc(10*sizeof(char));
		long unsigned int id;
		fscanf(f,"%s", n);
		fscanf(f, "%lu",&id);
		r->Name=n;
		r->empID=id;
	}
	return r;
}

List* readFromFile(FILE *f){
	List *list = newList(500);
	while(!feof(f)){
		Record *rec = readRec(f);
		list = addRec(list, rec);
	}
	return list;
}
