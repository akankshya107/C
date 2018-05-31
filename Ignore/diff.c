#include <stdio.h>
void dothestuff(int size, int arr[], int key);
int main(void){
	int size;
	scanf("%d", &size);
	int arr[size];
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	int key;
	scanf("%d", &key);
	dothestuff(size, arr, key);
	return 0;
}

int diff(int x , int y){
	if(x>y) return x-y;
	else return y-x;
}

void dothestuff(int size, int arr[], int key){
	int min=diff(arr[0],key);
	int k=1;
	int temp, pos;
	do{
		temp = diff(arr[k],key);
		if(temp<min){
			min = temp;
			pos = k+1;
		}
		k++;
	}while(k<size);
	printf("Closest is = %d at min difference of %d\n", pos, min);
};
