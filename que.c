#include <stdio.h>
#include <stdlib.h>
#include "que.h"
Queue* newQ(){
  Queue *q = (Queue*)malloc(sizeof(Queue));
  q->size=0;
  q->head=NULL;
  q->tail=NULL;
  return q;
}

bool isEmptyQ(Queue *q){
  if (q->head==NULL) return true;
  return false;
}

Queue* delQ(Queue *q){
  if (q->size>1){
    Element *ptr = q->head;
    q->head=ptr->next;
  }
  else{
    q->head=NULL;
    q->tail=NULL;
  }
  q->size--;
  return q;
}

Element* front(Queue *q){
  Element *ptr = q->head;
  return ptr;
}

Queue* addQ(Queue *q , Element *e){
  if (!isEmptyQ(q)){
    e->next=NULL;
    q->tail->next=e;
    q->tail=e;
  }
  else{
    q->head=e;
    q->tail=e;
    e->next=NULL;
  }
  q->size++;
  return q;
}

int lengthQ(Queue *q){
  Element *ptr = q->head;
  int length=0;
  while(ptr!=NULL){
    ptr=ptr->next;
    length++;
  }
  length++;
  return length;
}

Element* returnEle(int data){
  Element *e = (Element*)malloc(sizeof(Element));
  e->data=data;
  e->next=NULL;
  return e;
}
