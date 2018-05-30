run: compile
	./test
compile: edge.o test.o head
	gcc edge.o test.o -o test
edge.o : edge.c
	gcc -c -g edge.c
test.o : test.c
	gcc -c -g test.c
head: 
	gcc top.h
