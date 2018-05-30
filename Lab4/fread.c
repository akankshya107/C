#include "fread.h"
#include <stdlib.h>
#include <string.h>
Array* readFromFile(FILE *f){
	Array *a=newArray();
	while(1){
		Record *rec=newRecord();
		char *record=NULL;
		size_t len = 0;
		ssize_t read;
		read=getline(&record,&len,f);
		if (read==-1) break;
		rec->cd=strtok(record,",");
		rec->bc=strtok(NULL,",");
		rec->ed=strtok(NULL,",");
		rec->fn=strtok(NULL,",");
		rec->ln=strtok(NULL,",");
		a=insertIntoArray(a,rec);
		free(rec);
	}
	return a;
}


