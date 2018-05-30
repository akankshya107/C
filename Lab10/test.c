#define REP_TYPE_LIST
#include "graph.h"
int main(void){
	Graph *g = createGraph(5);
	g=addEdge(g,createVertex(0,0),createVertex(1,1));
	g=addEdge(g,createVertex(0,0),createVertex(2,2));
	g=addEdge(g,createVertex(3,3),createVertex(1,1));
	g=addEdge(g,createVertex(4,4),createVertex(1,1));
	g=addEdge(g,createVertex(3,3),createVertex(2,2));
	g=addEdge(g,createVertex(0,0),createVertex(3,3));
	printf("%d\n", degree(g,createVertex(0,0)));
	BFS(g,4);
	return 0;
}
