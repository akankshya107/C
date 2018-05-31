#include "nested.h"
int hash1(int key){
	return (key*13 + 19)%23;
}

int hash2(int key){
	return (key*23 + 17)%41;
}

void insert(NestedHT *t, Element *rec){
	int index = hash1(rec->key);
	if(isFull(t->arr[index])) return;
	int mindex = hashm(rec->key);
	t->arr[index]->arr[mindex]=rec;
}
