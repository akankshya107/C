run: compile
	./test
compile : graphM.o bfs.o test.o que.o
	gcc graphM.o bfs.o test.o que.o -o test
graphM.o : graphM.c
	gcc -c -g graphM.c
graphL.o : graphL.c 
	gcc -c -g graphL.c
test.o: test.c
	gcc -c -g test.c
bfs.o: bfs.c
	gcc -c -g bfs.c
que.o: que.c
	gcc -c -g que.c
