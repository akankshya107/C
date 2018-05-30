#include "qs.h"
int main(void){
	FILE *ptr=fopen("data.txt","r");
	List *l=readFromFile(ptr);
	quickSort(l,1);
	FILE *pw=fopen("out.txt", "w");
	for(int i=0; i<l->no_of_rec; i++){
		fprintf(pw, "%s %lu\n", l->arr[i]->Name, l->arr[i]->empID);
	}
	return 0;
}
