#include <stdlib.h>
#include <stdio.h>
#ifdef REP_TYPE_MATRIX
typedef int Element;
typedef struct{
	Element value;
	int number;
}Vertex;
typedef struct{
	int numV;
	Vertex** vertices;
	int* adjMatrix[];
}Graph;
typedef struct{
	Vertex** list;
	int size;
}Enumeration;
Graph* createGraph(int numV);
Enumeration* getAdjacent(Graph *g, Vertex *v);
Graph* addEdge(Graph *g, Vertex *v, Vertex *vAdj);
int degree(Graph *g, Vertex *v);
void BFS(Graph *g, Element val);
Vertex* createVertex(Element value, int number);
#endif

#ifdef REP_TYPE_LIST
typedef int Element;
typedef struct vertex{
	Element value;
	int number;
	struct vertex *next;
}Vertex;
typedef struct{
	int numV;
	Vertex* adjList[];
}Graph;
typedef struct{
	Vertex** list;
	int size;
}Enumeration;
Graph* createGraph(int numV);
Enumeration* getAdjacent(Graph *g, Vertex *v);
Graph* addEdge(Graph *g, Vertex *v, Vertex *vAdj);
int degree(Graph *g, Vertex *v);
void BFS(Graph *g, Element val);
Vertex* createVertex(Element value, int number);
#endif
