#include "h1.h"
void profile(Array *a){
	//int *baseArr=(int*)malloc(sizeof(int)*6);
	int baseArr[6];
	int tableSize=5000;
	int bestcount=INT_MAX;
	int bestBaseNo, bestTableSze;
	for(int i=0; i<3; i++){
		for(int i=0; i<3; i++){
			baseArr[i]=selectPrime(tableSize, 2*tableSize);
			baseArr[5-i]=selectPrime(1000*tableSize, INT_MAX);
		}
		for(int j=0; j<6; j++){
			int countcompare = collisionCount(a, baseArr[j], tableSize);
			if(bestcount>countcompare){
				bestcount = countcompare;
				bestBaseNo=baseArr[j];
				bestTableSze=tableSize;
			}
			printf("With basenumber = %d, and tablesize = %d, collisions=%d\n", baseArr[j], tableSize, countcompare);
		}
		tableSize*=10;
	}
	printf("With basenumber = %d, and tablesize = %d",bestBaseNo,bestTableSze);
}

int selectPrime(int lo, int hi){
	srand(time(NULL));
	int x;
	int i;
	while(1){
		x=(rand()%(hi-lo))+lo;
		i=2;
		while(i<=x/2){
			if(x%i==0) break;
			i++;
		}
		if(i==x/2+1) return x;
	}
}
