#define ADJ_LIST
#include "top.h"
Graph* createGraph(FILE *ptr){
	Graph *a = (Graph*)malloc(sizeof(Graph)+ sizeof(Vertex*)*20);
	a->no=20;
	for(int i=0; i<a->no; i++){
		a->vertices[i]=(Vertex*)malloc(sizeof(Vertex));
	}
	int x, y, count=0;
	while(fscanf(ptr, "%d", &x)==1){
		fscanf(ptr, "%d", &y);
		getc(ptr);
		if(count==a->no){
			a=realloc(a, sizeof(Graph)+ sizeof(Vertex*)*2*a->no);
			for(int i=a->no; i<2*a->no; i++){
				a->vertices[i]=(Vertex*)malloc(sizeof(Vertex));
			}
			a->no=2*a->no;
		}
		Vertex *insert1, *insert2;
		Vertex *v1 = returnVertex(x);
		Vertex *v2 = returnVertex(y);
		if(!contains(a->vertices, v1, count) && !contains(a->vertices, v2, count)) {
			insert1=returnVertex(v1->val);
			insert1->index=count;
			a->vertices[count++]=insert1;
			insert2=returnVertex(v2->val);
			insert2->index=count;
			a->vertices[count++]=insert2;
		}
		else if(!contains(a->vertices, v1, count)) {
			insert1=returnVertex(v1->val);
			insert1->index=count;
			a->vertices[count++]=insert1;
		}
		else if(!contains(a->vertices, v2, count)) {
			insert2=returnVertex(v2->val);
			insert2->index=count;
			a->vertices[count++]=insert2;
		}
		int x=0;
		while(x<count){
			if(a->vertices[x]->val==v1->val){ break; }
			x++;
		}
		Vertex *temp=a->vertices[x];
		while(temp->next!=NULL){ temp=temp->next; }
		temp->next=v2;
	}
	a->no=count;
	a=realloc(a, sizeof(Graph) + sizeof(Vertex*)*a->no);
	return a;
}


bool contains(Vertex **v, Vertex *x, int count){
	for(int i=0; i<count; i++){
		if(v[i]->val==x->val) return true;
	}
	return false;
}

Vertex* returnVertex(int val){
	Vertex *x = (Vertex*)malloc(sizeof(Vertex));
	x->val=val;
	x->index=0;
	x->next=NULL;
	return x;
}

List topoSort(Graph *g){
	List l =(List)malloc(sizeof(Vertex*)*g->no);
	for(int i=0; i<g->no; i++){
		l[i]=(Vertex*)malloc(sizeof(Vertex));
	}
	Vertex *temp;
	int i=0, j=0, check=0, count=0;
	while(i<g->no){
		while(j<g->no){
			temp=g->vertices[j];
			while(temp->next!=NULL){
				if(temp->next->val==g->vertices[i]->val) check=1;
				temp=temp->next;
			}
			j++;
		}
		if(check==0){
			if(!contains(l, g->vertices[i], count)) l[count++]=g->vertices[i];
			temp=g->vertices[i];
			while(temp->next!=NULL){
				if(!contains(l, temp->next, count)) l[count++]=temp->next;
				temp=temp->next;
			}
		}
		if (count==g->no) break;
		j=0;
		check=0;
		i++;
	}
	if(count!=g->no){
		while(j<g->no){
			if(!contains(l, g->vertices[j], count)){
				l[count++]=g->vertices[j];
			}
			j++;
		}
	}
	return l;
}
