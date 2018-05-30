#include <stdlib.h>
#include "multiq.h"

MultiQ* createMQ(int num){
	MultiQ *mq = malloc(sizeof(MultiQ)+sizeof(ModifiedQueue*)*num);
	mq->num=num;
	for (int i=0; i<num; i++){
		mq->sche[i]=returnModifiedQ();
		mq->sche[i]->q=newQ();
		mq->sche[i]->p=num-i;
	}
	return mq;
}

MultiQ* addMQ(MultiQ *mq, Task *t){
	for(int i=0; i<mq->num; i++){
		if (t->p==mq->sche[i]->p){
			mq->sche[i]->q=addQ(mq->sche[i]->q, returnElement(t));
		}
	}
	return mq;
}

Task* nextMQ(MultiQ *mq){
	for (int i=0; i<mq->num; i++){
		if(!isEmptyQ(mq->sche[i]->q)){
			Element *e = front(mq->sche[i]->q);
			return e->t;
		}
	}
}

MultiQ* delNextMQ(MultiQ *mq){
	for (int i=0; i<mq->num; i++){
		if(!isEmptyQ(mq->sche[i]->q)){
			mq->sche[i]->q= delQ(mq->sche[i]->q);
			return mq;
		}
	}
}

bool isEmptyMQ(MultiQ *mq){
	for (int i=0; i<mq->num; i++){
		if (!isEmptyQ(mq->sche[i]->q)) return false;
	}
	return true;
}

int sizeMQ(MultiQ *mq){
	int length=0;
	for (int i=0; i<mq->num; i++){
		length+=lengthQ(mq->sche[i]->q);
	}
	return length;
}

int sizeMQbyPriority(MultiQ *mq, Priority p){
	for(int i=0; i<mq->num; i++){
		if (p==mq->sche[i]->p){
			return lengthQ(mq->sche[i]->q);
		}
	}
}

Queue* getQueueFromMQ(MultiQ *mq, Priority p){
	for(int i=0; i<mq->num; i++){
		if (p==mq->sche[i]->p){
			return mq->sche[i]->q;
		}
	}
}

Element* returnElement(Task *t){
	Element *e=(Element*)malloc(sizeof(Element));
	e->t=t;
	e->next=NULL;
	return e;
}


Task* returnTask(TaskId tid, Priority p){
	Task *t=(Task*)malloc(sizeof(Task));
	t->tid=tid;
	t->p=p;
	return t;
}

ModifiedQueue* returnModifiedQ(){
	ModifiedQueue *mq = (ModifiedQueue*)malloc(sizeof(ModifiedQueue));
	mq->q=NULL;
	mq->p=0;
	return mq;
}
