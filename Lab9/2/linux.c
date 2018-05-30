#include "stack.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
void treeTraverse(char *name){
	DIR *d=opendir(name);
	perror("Cannot open .");
	//if(d==NULL) return;
	struct dirent *temp=readdir(d);
	//if(temp==NULL) return;
	Stack *currentSet=newStack();
	while((temp)!=NULL){
		currentSet=push(currentSet, returnEle(temp));
		temp=readdir(d);
	}
	do{
		temp=top(currentSet); pop(currentSet);
		printf("%s\n", temp->d_name);
		d=opendir(temp->d_name);
		if(!(d==NULL)){
			temp=readdir(d);
			while(temp!=NULL){
				currentSet=push(currentSet, returnEle(temp));
				temp=readdir(d);
			}
		}
	}while(!isEmpty(currentSet));
}

int main(void){
	char *s="/home/user";
	treeTraverse(s);
	return 0;
}
