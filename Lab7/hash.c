#include "hash.h"
HashTable* createHT(){
	HashTable *ht = (HashTable*)malloc(sizeof(HashTable)+sizeof(LinkedList)*500000);
	ht->elementcount=0;
	ht->insertioncost=0;
	ht->queryingcost=0;
	for(unsigned int i=0; i<500000; i++){
		ht->arr[i]=createLL();
	}
	return ht;
}

LinkedList* createLL(){
	LinkedList *l = (LinkedList*)malloc(sizeof(LinkedList));
	l->index=0;
	l->count=0;
	l->next=NULL;
	return l;
}

void insertHT(HashTable *ht, char** a, int j){
	int check = hash(a[j]);
	if(ht->arr[check]->next==NULL){
		LinkedList *l = createLL();
		ht->arr[check]->next=l;
		l->index=j;
		l->count++;
		return;
	}
	LinkedList *ptr=ht->arr[check]->next;
	while(ptr->next!=NULL){
		if(a[ptr->index]==a[j]){
			ptr->count++;
			return;
		}else ptr=ptr->next;
	}
	LinkedList *l = createLL();
	l->index=j;
	l->count++;
	ptr->next=l;
	ht->insertioncost++;
	return;
}

int insertAll(HashTable *ht, Array *book){
	for(int i=0; i<book->no_of_rec; i++){
		insertHT(ht, book->arr, i);
	}
	return ht->insertioncost;
}

LinkedList* lookup(HashTable *ht, char* a){
	int check = hash(a);
	return ht->arr[check];
}

