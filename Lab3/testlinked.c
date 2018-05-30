#include <stdio.h>
#include <sys/time.h>
#include "cycle.h"
int main(void){
	struct timeval t1,t2;
	double elapsedTime;
	unsigned int N=10;
	//while(N<10000){
		LinkedList *l=createList(N);
		printf("Total heap space=%u\n", spaceAllocated);
		l=createCycle(l);
		//gettimeofday(&t1, NULL);
		printf("%s\n",testCyclic(l));
		/*gettimeofday(&t2, NULL);
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
		printf("Total time is %f ms.\n for %u", elapsedTime,N);*/
		l=makeCircularList(l);
		printf("%s\n",testCyclic(l));
		myfree(l);
		N*=10;
	//}
}
