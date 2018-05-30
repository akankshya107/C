#include "fread.h"
#include <stdlib.h>
Array* newArray(){
	Array *a = (Array*)malloc(sizeof(Array)+sizeof(Record*)*10);
	a->size=10;
	a->no_of_rec=0;
	for(int i=0; i<10; i++){
		a->arr[i]=newRecord();
	}
	return a;
}

Record* newRecord(){
	Record *rec=(Record*)malloc(sizeof(Record));
	rec->cd=NULL;
	rec->bc=NULL;
	rec->ed=NULL;
	rec->fn=NULL;
	rec->ln=NULL;
	return rec;
}

Array* insertIntoArray(Array *a, Record *rec){
	if (a->size!=a->no_of_rec){
		Record* r=newRecord();
		*r=*rec;
		a->arr[a->no_of_rec]=r;
		//printf("%s%s%s%s%s",a->arr[a->no_of_rec]->cd,rec->bc,rec->ed,rec->fn,rec->ln);
	}
	else{
		a=resizeArray(a, a->size);
		Record* r=newRecord();
		*r=*rec;
		a->arr[a->no_of_rec]=r;
	}
	(a->no_of_rec)++;
	return a;
}

Array* resizeArray(Array *a, int size){
	a=realloc(a, sizeof(Array)+(sizeof(Record*))*size*2);
	a->size=size*2;
	for(int i=size; i<size*2; i++){
		a->arr[i]=newRecord();
	}
	return a;
}
