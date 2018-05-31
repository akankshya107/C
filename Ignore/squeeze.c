#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int l;
void squeeze(char *s) {
	int i=0;
	while (s[i] != '\0') {
		if (s[i]==' ' || s[i]=='\t' || s[i]=='\n') {
			i=i+1;
			while (s[i]==' ' || s[i]=='\t' || s[i]=='\n') {
				s[i] = s[i+1];
				i=i+1;
				}
		} 
		i = i+1;
	}
}

int fibb(long int n){
	if(n>2) return fibb(n-1)*fibb(n-2)*fibb(n-3);
	return 1;
}

long unsigned int* readFromFile(FILE *ptr){
	//char* str = (char*)malloc(sizeof(char)*6000);
	int i=0;
	long unsigned int input;
	long unsigned int* arr = (long unsigned int*)malloc(sizeof(long unsigned int)*10);
	while(fscanf(ptr, "%lu", &input)==1){
		arr[i]=input;
		i++;
	}
	l=i;
	return arr;
}

int main(void){
	struct timeval t1, t2;
	double time;
	FILE *ptr = fopen("input.txt","r");
	FILE *ptw = fopen("force.dat","w");
	long unsigned int *arr = readFromFile(ptr);
	printf("%d\n", l);
	for(int i=0; i<l;i++){
		gettimeofday(&t1, NULL);
		fibb(arr[i]);
		gettimeofday(&t2, NULL);
		time=((t2.tv_sec-t1.tv_sec)*1000.0);
		time+=((t2.tv_usec-t1.tv_usec)/1000.0);
		fprintf(ptw , "%lu \t\t\t\t\t\t\t\t %f \n", arr[i], time);
	}
}
