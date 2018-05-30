#define REP_TYPE_MATRIX
#include "graph.h"
#include "que.h"
void BFS(Graph *g, Element val){
	char** adjMatrix = (char**)malloc(sizeof(char*)*(g->numV));
	for(int i=0; i<g->numV; i++){
		adjMatrix[i]=(char*)malloc(sizeof(char)*(g->numV));
		for(int j=0; j<g->numV; j++){
			adjMatrix[i][j]='U';
		}
	}
	int* temp=(int*)malloc(sizeof(int)*(g->numV));
	for(int i=0; i<g->numV; i++){
		temp[i]=0;
	}
	Queue *q = newQ();
	q=addQ(q, returnEle(0));
	temp[0]=1;
	while(!isEmptyQ(q)){
		Vertex *u = g->vertices[front(q)->data];
		q=delQ(q);
		Enumeration *e = getAdjacent(g,u);
		for(int j=0; j<e->size; j++){
			if(adjMatrix[u->number][e->list[j]->number]=='U'){
				if(!temp[e->list[j]->number]){
					if(e->list[j]->value==val){
						printf("Found at index=%d", e->list[j]->number);
						return;
					}
					temp[e->list[j]->number]=1;
					adjMatrix[u->number][e->list[j]->number]='T';
					q=addQ(q, returnEle(e->list[j]->number));
				}
				adjMatrix[u->number][e->list[j]->number]='C';
			}
		}
	}
}
