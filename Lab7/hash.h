#include "h1.h"
typedef struct ll{
	long unsigned int index;
	int count;
	struct ll *next;
}LinkedList;

typedef struct {
	long unsigned int elementcount;
	int insertioncost;
	int queryingcost;
	LinkedList *arr[];
}HashTable;

HashTable* createHT();
LinkedList* createLL();
void insertHT(HashTable *ht, char** a, int j);
int insertAll(HashTable *ht, Array *book);
LinkedList* lookup(HashTable *ht, char* a);
