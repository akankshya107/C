#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int key;
	long int val;
}Element;

typedef struct{
	int size;
	Element *arr[];
}HashTable;

typedef struct{
	int nestedsize;
	HashTable *arr[];
}NestedHT;

int hash1(int key);
int hashm(int key);
void insert(HashTable *t, Element *rec);
int find(HashTable *t, Element *rec);
void deletefromHashTable(HashTable *t, Element *rec);
