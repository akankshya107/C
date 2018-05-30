#define REP_TYPE_MATRIX
#include "graph.h"
Graph* createGraph(int numV){
	Graph *g=(Graph*)malloc(sizeof(Graph)+sizeof(int*)*numV);
	g->vertices=(Vertex**)malloc(sizeof(Vertex*)*numV);
	for(int i=0; i<numV; i++){
		g->vertices[i]=(Vertex*)malloc(sizeof(Vertex));
		g->vertices[i]->value=i;
		g->vertices[i]->number=i;
	}
	for(int i=0; i<numV; i++){
		g->adjMatrix[i]=(int*)malloc(sizeof(int)*numV);
		for(int j=0; j<numV; j++){
			g->adjMatrix[i][j]=0;
		}
	}
	g->numV=numV;
	return g;
}

Enumeration* getAdjacent(Graph *g, Vertex *v){
	Enumeration *e=(Enumeration*)malloc(sizeof(Enumeration));
	e->list=(Vertex**)malloc(sizeof(Vertex*)*(g->numV));
	int count=0;
	for(int i=0; i<g->numV; i++){
		if(g->adjMatrix[v->number][i]==1){
			e->list[count++]=g->vertices[i];
		}
	}
	e->list=realloc(e->list, count);
	e->size=count;
	return e;
}

Graph* addEdge(Graph *g, Vertex *v, Vertex *vAdj){
	g->adjMatrix[v->number][vAdj->number]=1;
	g->adjMatrix[vAdj->number][v->number]=1;
	return g;
}

int degree(Graph *g, Vertex *v){
	int count=0;
	for(int i=0; i<g->numV; i++){
		if(g->adjMatrix[v->number][i]==1) count++;
	}
	return count;
}

Vertex* createVertex(Element value, int number){
	Vertex* v=(Vertex*)malloc(sizeof(Vertex));
	v->value=value;
	v->number=number;
	return v;
}
