run : compile
	./prog
compile: stack.o main.o
	gcc stack.o main.o -o prog
stack.o : stack.c stack.h
	gcc -c -g stack.c
main.o : main.c stack.c 
	gcc -c -g main.c
