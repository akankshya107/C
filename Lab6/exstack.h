typedef struct{
	int top;
	int s[];
}Stack;
Stack* newStack(int size); //returns stack of size "size"
int pop(Stack *stack);
void push(Stack *stack, int x);
