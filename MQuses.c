#include "multiq.h"
MultiQ* loadData(FILE *f, MultiQ *mq){
	TaskId tid;
	Priority p;
	while(!feof(f)){
		char c;
		TaskId tid;
		Priority p;
		fscanf(f,"%ld", &tid);
		fscanf(f, "%c", &c);
		fscanf(f, "%d", &p);
		Task *t = returnTask(tid, p);
		mq = addMQ(mq, t);
	}
	return mq;
}

MultiQ* testDel(int num, MultiQ *mq){
	for(int i=0; i<num; i++){
		printf("Task done=%ld\n", nextMQ(mq)->tid);
		mq=delNextMQ(mq);
	}
	return mq;
}
