#include "hash.h"
int main(void){
	FILE *ptr = fopen("aliceinwonderland.txt", "r");
	Array *a = parse(ptr);
	HashTable *h = createHT();
	profile(a);
	int cost=insertAll(h, a);
	printf("%d\n",cost);
	return 0;
}
