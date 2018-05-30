#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
typedef struct tree{
	int balance:1;
	int value;
	struct tree *left;
	struct tree *right;
}Tree;

typedef Tree *TNode;

void add(TNode tree, TNode tnode);
TNode find(TNode tree, int val);
void delete(TNode tree, int val);
TNode createNode(int val);
int height(TNode x);
int max(int x, int y);
TNode createTree();
TNode rotate(TNode x, TNode y, TNode z);
void balanceAdd(TNode tree, TNode temp); //balances up til node temp
void balanceDel(TNode tree, TNode temp);
int inOrder(TNode tree, int k);
