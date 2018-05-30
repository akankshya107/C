#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef EDGE_LIST
typedef long unsigned int *List;
typedef struct{
	long unsigned int no_of_vertices;
	long unsigned int no_of_edges;
	long unsigned int *vertices;
	long unsigned int **edges;
}Graph;

Graph* createGraph(FILE *ptr);
bool contains(long unsigned int arr[], long unsigned int x, long unsigned int count);
List topoSort(Graph *g);
#endif
#ifdef ADJ_LIST
typedef struct vertex{
	int val;
	int index;
	struct vertex *next;
}Vertex;
typedef Vertex **List;
typedef struct{
	int no;
	Vertex *vertices[];
}Graph;

Graph* createGraph(FILE *ptr);
bool contains(Vertex **v, Vertex *x, int count);
Vertex* returnVertex(int val);
List topoSort(Graph *g);
#endif
