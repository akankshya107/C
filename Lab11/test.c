#define EDGE_LIST
#include "top.h"
#include <sys/time.h>
int main(int argc, char **argv){
	struct timeval t1, t2;
	double elapsedTime;
	FILE *fr = fopen("new.txt", "r");
	FILE *fw = fopen("output.txt", "w");
	char *str=(char*)malloc(sizeof(char)*100);
	Graph *g = createGraph(fr);
	gettimeofday(&t1, NULL);
	List l = topoSort(g);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time is %f ms.\n", elapsedTime);
	for(long unsigned int i=0; i<g->no_of_vertices; i++){
		fprintf(fw, "%lu\n", l[i]);
	}
	return 0;
}

/*
Vertex *temp;
	for(int i=0; i<e->no; i++){
		printf("%d\t%d\n", e->vertices[i]->index, e->vertices[i]->val);
	}
	for(int i=0; i<e->no; i++){
		temp=e->vertices[i];
		printf("%d\n", e->vertices[i]->val);
		while(temp->next!=NULL){
			printf("%d\n", temp->next->index);
			temp=temp->next;
		}
	}
	List l = topoSort(e);
	for(int i=0; i<e->no; i++){
		printf("%d\n", l[i]->val);
	}*/
