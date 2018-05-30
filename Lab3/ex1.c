#include <stdio.h>
int bits=34;
int p(int x){
	if (x==10) return;
	printf("x = %u\n",&x);
	p(x+1);
	return 0;
}
int g(){
	int goa=20;
	printf("goa = %u\n",&goa);
	return 0;
}
int h(){
	int hyd=30;
	printf("hyd = %u\n",&hyd);
	return 0;
}
int d(){
	int dub=40;
	printf("dub = %u\n",&dub);
	g();
	return 0;
}
int main(void){
	int *x=(int*)malloc(sizeof(int));
	p(1);
	g();
	h();
	d();
	printf("%u", x);
	printf("bits = %u\n", &bits);
	return 0;
}

