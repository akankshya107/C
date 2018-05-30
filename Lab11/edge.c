#define EDGE_LIST
#include "top.h"
Graph* createGraph(FILE *ptr){
	Graph* e = (Graph*)malloc(sizeof(Graph));
	e->vertices = (long unsigned int*)malloc(sizeof(long unsigned int)*20);
	e->edges = (long unsigned int**)malloc(sizeof(long unsigned int*)*20);
	for(int i=0; i<20; i++){
		e->edges[i]=(long unsigned int*)malloc(sizeof(long unsigned int)*2);
	}
	e->no_of_vertices=20;
	e->no_of_edges=20;
	long unsigned int countv=0, counte=0;
	long unsigned int x, y;
	while(fscanf(ptr, "%lu", &x)==1){
		fscanf(ptr, "%lu", &y);
		getc(ptr);
		if(counte==e->no_of_edges){
			e->edges=realloc(e->edges, sizeof(long unsigned int*)*2*e->no_of_edges);
			for(long unsigned int i=e->no_of_edges; i<2*e->no_of_edges; i++){
				e->edges[i]=(long unsigned int*)malloc(sizeof(long unsigned int)*2);
			}
			e->no_of_edges=2*e->no_of_edges;
		}
		if(countv==e->no_of_vertices){
			e->vertices=realloc(e->vertices, sizeof(long unsigned int)*2*e->no_of_vertices);
			e->no_of_vertices=2*e->no_of_vertices;
		}
		if(!contains(e->vertices, x, countv) && !contains(e->vertices, y, countv)) {
			e->vertices[countv++]=x;
			e->vertices[countv++]=y;
		}
		else if(!contains(e->vertices, x, countv)) e->vertices[countv++]=x;
		else if(!contains(e->vertices, y, countv)) e->vertices[countv++]=y;
		e->edges[counte][0]=x;
		e->edges[counte][1]=y;
		counte++;
	}
	e->no_of_edges=counte;
	e->no_of_vertices=countv;
	e->edges=realloc(e->edges, sizeof(long unsigned int*)*e->no_of_edges);
	e->vertices=realloc(e->vertices, sizeof(long unsigned int)*e->no_of_vertices);
	return e;
}

bool contains(long unsigned int arr[], long unsigned int x, long unsigned int count){
	for(long unsigned int i=0; i<count; i++){
		if(arr[i]==x) return true;
	}
	return false;
}

List topoSort(Graph *g){
	long unsigned int i=0, j=0, count=0;
	List l =(List)malloc(sizeof(*l)*g->no_of_vertices);
	while(i<g->no_of_vertices){
		while(j<g->no_of_edges){
			if(g->edges[j]!=NULL){
				if(g->vertices[i]==g->edges[j][1]) break;
			}
			j++;
		}
		if(j==g->no_of_edges){
			if(!contains(l, g->vertices[i], count)) l[count++]=g->vertices[i];
			j=0;
			while(j<g->no_of_edges){
				if(g->edges[j]!=NULL){
					if(g->vertices[i]==g->edges[j][0]){
						if(!contains(l, g->edges[j][1], count)) l[count++]=g->edges[j][1];
						g->edges[j]=NULL;
					}
				}
				j++;
			}
		}
		if (count==g->no_of_vertices) break;
		j=0;
		i++;
	}
	if(count!=g->no_of_vertices){
		while(j<g->no_of_vertices){
			if(!contains(l, g->vertices[j], count)){
				l[count++]=g->vertices[j];
			}
			j++;
		}
	}
	return l;
}
