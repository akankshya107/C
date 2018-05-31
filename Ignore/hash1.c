#include <stdio.h>
#include <math.h>
int h(int key);
int main(void){
	int x;
	while(1){
		scanf("%d",&x);
		printf("%d\n",h(x));
	}
}

int h(char* key){
	int a=7;
	int sum=0;
	for(int i=0; i<sizeof(key)/sizeof(key[0]);i++){
		sum+=sum*a+i;
	}
	return sum%57;
}
