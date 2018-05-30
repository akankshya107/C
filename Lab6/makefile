run : compile
	./prog
compile : exstack.o qs.o qsort.o isort.o driver1.o head1 head2
	gcc -g exstack.o qs.o qsort.o isort.o driver1.o -o prog
exstack.o : exstack.c
	gcc -c -g exstack.c
qs.o : qs.c
	gcc -c -g qs.c
isort.o : isort.c
	gcc -c -g isort.c
qsort.o : qsort.c
	gcc -c -g qsort.c
driver1.o : driver1.c
	gcc -c -g driver1.c
head1 : 
	gcc exstack.h
head2 : 
	gcc qs.h
