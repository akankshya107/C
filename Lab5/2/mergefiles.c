#include "interface1.h"
#include <stdlib.h>
void mergeFiles(FILE *f1, FILE *f2, FILE *out){
	Record *r1=readRec(f1);
	Record *r2=readRec(f2);
	while(1){
		if(!feof(f1) && !feof(f2)){
			if(r1->CGPA<=r2->CGPA){
				fprintf(out, "%s %f\n",r1->Name, r1->CGPA);
				r1=readRec(f1);
			}
			else{
				fprintf(out, "%s %f\n",r2->Name, r2->CGPA);
				r2=readRec(f2);
			}
		}
		else if(!feof(f1)){
				r1=readRec(f1);
				fprintf(out, "%s %f\n",r1->Name, r1->CGPA);
		}
		else if(!feof(f2)){
				r2=readRec(f2);
				fprintf(out, "%s %f\n",r2->Name, r2->CGPA);
		}
		else break;
	}
}
