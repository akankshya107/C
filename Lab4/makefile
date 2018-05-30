run : compile
	./prog 1000 duplicate
compile : fread.o implArray.o insert.o test.o frtest.o
	gcc -g fread.o implArray.o insert.o test.o frtest.o -o prog
frtest.o : frtest.c fread.h
	gcc -c -g frtest.c
test.o : test.c fread.h
	gcc -c -g test.c
implArray.o : implArray.c fread.h
	gcc -c -g implArray.c
fread.o : fread.c fread.h
	gcc -c -g fread.c
insert.o : insert.c fread.h
	gcc -c -g insert.c

