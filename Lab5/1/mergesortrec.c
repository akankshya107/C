#include "interface1.h"
#include <string.h>
void mergeSort(Element *list, int st, int en){
	if(en-st<1) return;
	int mid=(st+en)/2;
	mergeSort(list, st, mid);
	mergeSort(list, mid+1, en);
	Element *temp = newList(en-st+1);
	Element *temp1 = newList(mid-st+1);
	int j=0;
	for(int i=st; i<=mid; i++){
		addEle(temp1,list->arr[i]->Name,list->arr[i]->CGPA);
	}
	Element *temp2 = newList(en-mid);
	j=0;
	for(int i=mid+1; i<=en; i++){
		addEle(temp2,list->arr[i]->Name,list->arr[i]->CGPA);
	}
	merge(temp1, mid-st+1 , temp2 , (en-mid), temp);
	j=0;
	for(int i=st; i<=en; i++){
		list->arr[i]->Name=temp->arr[j]->Name;
		list->arr[i]->CGPA=temp->arr[j]->CGPA;
		j++;
	}
	//memcpy(list->arr[st], temp->arr, st-en+1);
}
