#include <stdio.h>
#include <sys/time.h>
int left(long unsigned int n){
	while(n>=10) {
		n=n/10;
	}
	int x;
	printf("end = %p\n",&x);
	return n;
}

int main(void){
	struct timeval t1, t2;
	double time;
	int x;
	for(long unsigned int i=1; i<=1000000 ; i*=16){
		printf("start = %p\n",&i);
		gettimeofday(&t1, NULL);
		x = left(i);
		gettimeofday(&t2, NULL);
		time=((t2.tv_sec-t1.tv_sec)*1000.0);
		time+=((t2.tv_usec-t1.tv_usec)/1000.0);
		printf("%lu \t\t%d\t\t %f \n",i,x,time);
	}
}
