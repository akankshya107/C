#define REP_TYPE_LIST
#include "graph.h"

Graph* createGraph(int numV){
	Graph *g=(Graph*)malloc(sizeof(Graph)+sizeof(Vertex*)*numV);
	for(int i=0; i<numV; i++){
		g->adjList[i]=(Vertex*)malloc(sizeof(Vertex));
		g->adjList[i]->value=i;
		g->adjList[i]->number=i;
		g->adjList[i]->next=NULL;
	}
	g->numV=numV;
	return g;
}

Enumeration* getAdjacent(Graph *g, Vertex *v){
	Enumeration *e=(Enumeration*)malloc(sizeof(Enumeration));
	e->list=(Vertex**)malloc(sizeof(Vertex*)*(g->numV));
	int count=0;
	Vertex *ptr=g->adjList[v->number]->next;
	while(ptr!=NULL){
		e->list[count++]=ptr;
		ptr=ptr->next;
	}
	e->list=realloc(e->list, count);
	e->size=count;
	return e;
}

Graph* addEdge(Graph *g, Vertex *v, Vertex *vAdj){
	Vertex *ptr = g->adjList[v->number];
	while(ptr->next!=NULL){ ptr=ptr->next; }
	ptr->next=vAdj;
	ptr = g->adjList[vAdj->number];
	while(ptr->next!=NULL){ ptr=ptr->next; }
	ptr->next=v;
	return g;
}

int degree(Graph *g, Vertex *v){
	int count=0;
	Vertex *ptr = g->adjList[v->number]->next;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	return count;
}

Vertex* createVertex(Element value, int number){
	Vertex* v=(Vertex*)malloc(sizeof(Vertex));
	v->value=value;
	v->number=number;
	return v;
}
