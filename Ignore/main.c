#include "stack.h"
int main(void){
	Stack *s = newStack();
	printf("%d\n",isEmpty(s));
	s = push(s, 1);
	printf("%d\n",isEmpty(s));
	s = push(s, 1);
	s = push(s, 35);
	s = push(s, 45);
	s = push(s, 6);
	s = push(s, 755);
	s = push(s, 75);
	s = push(s, 353);
	s = push(s, 673);
	s = push(s, 635);
	s = push(s, 9);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", size(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	return 0;
}
