#include "interface1.h"
void mergeSort(Element *list, int st, int en){
	for(int curr_size=1; curr_size<(en-st); curr_size=2*curr_size){
		for(int curr_st=0; curr_st<(en-st); curr_st+=2*curr_size){
			int curr_en;
			if(curr_st+2*curr_size-1<en-st) curr_en=curr_st+2*curr_size-1;
			else curr_en=en-st;
			int curr_mid;
			if(curr_st+(curr_size-1)<curr_en) curr_mid=curr_st+(curr_size-1);
			else curr_mid=(curr_st+curr_en)/2;
			Element *temp = newList(curr_en-curr_st+1);
			Element *temp1 = newList(curr_mid-curr_st+1);
			int k=0;
			for(int l=curr_st; l<=curr_mid; l++){
				addEle(temp1,list->arr[l]->Name,list->arr[l]->CGPA);
			}
			Element *temp2 = newList(curr_en-curr_mid);
			k=0;
			for(int l=curr_mid+1; l<=curr_en; l++){
				addEle(temp2,list->arr[l]->Name,list->arr[l]->CGPA);
			}
			merge(temp1, (curr_mid-curr_st+1) , temp2 , (curr_en-curr_mid), temp);
			k=0;
			for(int l=curr_st; l<=curr_en; l++){
				list->arr[l]->Name=temp->arr[k]->Name;
				list->arr[l]->CGPA=temp->arr[k]->CGPA;
				k++;
			}
		}
	}
}
