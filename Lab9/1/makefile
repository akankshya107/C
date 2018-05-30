run : compile1 compile2
	./test1
	./test2
compile1 : iterateLL.o tree.o testtree.o stack.o DFT.o head1 head2 head3
	gcc iterateLL.o tree.o testtree.o stack.o DFT.o -o test1
compile2 : iterateLL.o tree.o testtree.o que.o BFT.o head1 head2 head3
	gcc iterateLL.o tree.o testtree.o que.o BFT.o -o test2
iterateLL.o : iterateLL.c
	gcc -c -g iterateLL.c
tree.o : tree.c
	gcc -c -g tree.c
testtree.o : testtree.c 
	gcc -c -g testtree.c
stack.o : stack.c
	gcc -c -g stack.c
DFT.o: DFT.c
	gcc -c -g DFT.c
BFT.o : BFT.c
	gcc -c -g BFT.c
head1: 
	gcc iterate.h
head2: 
	gcc tree.h
head3: 
	gcc stack.h
