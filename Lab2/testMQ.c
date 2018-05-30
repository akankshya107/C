#include "multiq.h"
#include <sys/time.h>
int main(){
	//struct timeval t1, t2;
	//double elapsedTime;
	FILE *ptr;
	ptr = fopen("input10000.txt", "r");
	MultiQ *mq = createMQ(10);
	/*Task *t1=returnTask(1000021, 1);
	Task *t4=returnTask(1000024, 5);
	Task *t2=returnTask(1000022, 2);
	Task *t3=returnTask(1000023, 7);
	mq=addMQ(mq, t1);
	mq=addMQ(mq, t2);
	mq=addMQ(mq, t3);
	mq=addMQ(mq, t4);
	*/
	mq=loadData(ptr,mq);
	//gettimeofday(&t1, NULL);
	mq=testDel(100, mq);
	//gettimeofday(&t2, NULL);
	//elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	//elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	//printf("Total time is %f ms.\n", elapsedTime);
	//printf("Av=%f ms.\n", elapsedTime/100);
	/*printf("%ld\n", nextMQ(mq)->tid);
	mq=delNextMQ(mq);
	printf("%ld\n", nextMQ(mq)->tid);
	mq=delNextMQ(mq);
	printf("%ld\n", nextMQ(mq)->tid);*/
	fclose(ptr);
	return 0;
}


