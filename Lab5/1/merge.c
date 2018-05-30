#include "interface1.h"
void merge(Element *Ls1, int sz1, Element *Ls2, int sz2, Element *Ls){
	int j=0;
	int k=0;
	for (int i=0; i<sz1+sz2; i++){
		if(j>=sz1 && k<sz2){
			addEle(Ls, Ls2->arr[k]->Name,Ls2->arr[k]->CGPA);
			k++;
		}
		else if(j<sz1 && k>=sz2){
			addEle(Ls, Ls1->arr[j]->Name, Ls1->arr[j]->CGPA);
			j++;
		}
		else if(Ls1->arr[j]->CGPA==0.00 && Ls2->arr[k]->CGPA==0.00) break;
		else if(Ls1->arr[j]->CGPA<=Ls2->arr[k]->CGPA){
			addEle(Ls, Ls1->arr[j]->Name, Ls1->arr[j]->CGPA);
			j++;
		}
		else{
			addEle(Ls, Ls2->arr[k]->Name,Ls2->arr[k]->CGPA);
			k++;
		}
	}
}

