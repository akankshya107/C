#include "phone.h"
List* createNewList(){
	List *l = (List*)malloc(sizeof(List) + sizeof(OrderByNameRec)*100 +sizeof(OrderByNumberRec)*100);
	l->nameo->size=100;
	l->numbero->size=100;
	for(int i=0; i<100; i++){
		l->nameo->arr[i]=nameRec();
		l->numbero->arr[i]=numberRec();
	}
}
