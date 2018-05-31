#include <string.h>
#include <stdlib.h>
#include <stdio.h>
inline char* reverse(char* s){
	if(strlen(s)==1) return s;
	char *x=(char*)malloc(sizeof(char)*(strlen(s)-1));
	strncpy(x,s,strlen(s)-1);
	return strcat((s+(strlen(s)-1)),reverse(x));
}

int main(void){
	char s[10];
	scanf("%s",s);
	printf("\n%s",reverse(s));
	return 0;
}
