run: compile
	./prog
compile: tree.o treeuses.o test.o head
	gcc tree.o treeuses.o test.o -o prog
tree.o: tree.c 
	gcc -c -g tree.c
treeuses.o: treeuses.c
	gcc -c -g treeuses.c
test.o: test.c
	gcc -c -g test.c
head: 
	gcc tree.h
