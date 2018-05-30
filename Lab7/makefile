run :	compile
	./testprog
compile :hash.o  h1.o driver1.o head
	gcc h1.o hash.o driver1.o -o testprog
h1.o : h1.c
	gcc -c -g h1.c
hash.o : hash.c
	gcc -c hash.c
	gcc hash.h
profile.o : profile.c
	gcc -c -g profile.c
driver1.o : driver1.c
	gcc -c -g driver1.c
head :
	gcc h1.h
