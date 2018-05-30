#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

SeqList* newList(){
  SeqList *sl = (SeqList*)malloc(sizeof(SeqList));
  sl->size=0;
  sl->head=NULL;
  sl->tail=NULL;
  return sl;
}

SeqList* insertInOrder(SeqList *sl, Element *e){
  if(sl->size==0){
    sl->head=e;
    sl->tail=e;
    e->next=NULL;
  }
  else{
    Element *ptr = sl->head;
		if (e->key<ptr->key){
			e->next=sl->head;
			sl->head=e;
			sl->size++;
			return sl;
		}
    while((ptr->next!=NULL) && ((e->key)>((ptr->next)->key))){
      ptr=ptr->next;
    }
    e->next=ptr->next;
    ptr->next=e;
    if (ptr->next==NULL) sl->tail=e;
  }
  sl->size++;
  return sl;
}

SeqList* insertAtFront(SeqList *sl, Element *e){
  if(sl->size==0){
    sl->head=e;
    sl->tail=e;
    e->next=NULL;
  }
  else{
    e->next=sl->head;
    sl->head=e;
  }
  sl->size++;
  return sl;
}

SeqList* insertAtEnd(SeqList *sl, Element *e){
  if(sl->size==0){
    sl->head=e;
    sl->tail=e;
    e->next=NULL;
  }
  else{
    Element *ptr = sl->tail;
    ptr->next=e;
    sl->tail=e;
  }
  sl->size++;
  return sl;
}

SeqList* delete(SeqList *sl, Element *e){
  Element *ptr=sl->head;
  while(ptr->next->key!=e->key){
    ptr=ptr->next;
  }
  ptr->next=ptr->next->next;
  sl->size--;
  free(e);
  return sl;
}

SeqList* deleteAtFront(SeqList *sl){
  if(sl->size<=1){
    sl->head=NULL;
    sl->tail=NULL;
  }
  else{
    Element *ptr=sl->head;
    sl->head=sl->head->next;
  }
  sl->size--;
  return sl;
}

Element* find(SeqList *sl, Key k){
  Element *ptr=sl->head;
  while(ptr->key!=k){
    ptr=ptr->next;
  }
  return ptr;
}

Element* createElem(Key k){
  Element *el = (Element*)malloc(sizeof(Element));
  el->key=k;
  el->next=NULL;
  return el;
}
