#include "h1.h"
int hash(char *str){
	long unsigned int sum=0;
	long unsigned int a =23;
	for (int i=0; i<strlen(str); i++){
		sum=sum*a+str[i];
	}
	return (sum%1143)%500000;
}

int collisionCount(Array *a, int baseNumber, int tableSize){
	int *check = (int*)malloc(sizeof(int)*tableSize);
	int *count = (int*)malloc(sizeof(int)*tableSize);
	for(int i=0; i<tableSize; i++) {
		check[i]=0;
		count[i]=0;
	}
	int temp;
	int sum_count=0;
	for(int i=0; i<a->no_of_rec; i++){
		temp = hash(a->arr[i]);
		//printf("%d\t",temp);
		if (check[temp]==0) {check[temp]=1;}
		else {count[temp]++;}
	}
	for(int i=0; i<tableSize; i++){
		if(count[i]>0) count[i]--;
		sum_count+=count[i];
	}
	return sum_count;
}

Array* parse(FILE *ptr){
	char *str = (char*)malloc(sizeof(char)*20);
	Array *a = (Array*)malloc(sizeof(Array)+sizeof(char*)*50);
	a->currsize=50;
	a->no_of_rec=0;
	for(int i=0; i<a->currsize; i++){
		a->arr[i]=(char*)malloc(sizeof(char)*20);
	}
	while(fscanf(ptr, "%s", str)==1){
		if(filter(str)){
			if(a->no_of_rec==a->currsize){
				a=resize(a,a->currsize);
			}
			strcpy(a->arr[a->no_of_rec++],str);
		}
	}
	a=realloc(a, sizeof(Array)+sizeof(char*)*a->no_of_rec);
	a->currsize=a->no_of_rec;
	printf("%d\n", a->no_of_rec);
	return a;
}

int filter(char *str){
	for(int i=0; i<strlen(str); i++){
		if(!isalpha(str[i])) return 0;
	}
	return 1;
}

Array* resize(Array *a, int size){
	a=realloc(a, sizeof(Array)+sizeof(char*)*2*size);
	a->currsize=2*size;
	for(int i=size; i<2*size; i++){
			a->arr[i]=(char*)malloc(sizeof(char)*20);
	}
	return a;
}
