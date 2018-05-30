run : comp
	./prog 10240.txt
comp : impl.o readEle.o merge.o mergesortrec.o driv1.o mergesortfiles.o mergefiles.o readk.o
	gcc -g impl.o readEle.o merge.o mergesortrec.o driv1.o mergesortfiles.o mergefiles.o readk.o -o prog
readk.o : readk.c interface1.h
	gcc -c -g readk.c
impl.o : impl.c interface1.h
	gcc -c -g impl.c
readEle.o : readEle.c interface1.h
	gcc -c -g readEle.c
merge.o : merge.c interface1.h
	gcc -c -g merge.c
mergesortiter.o : mergesortiter.c interface1.h
	gcc -c -g mergesortiter.c
mergesortrec.o : mergesortrec.c interface1.h
	gcc -c -g mergesortrec.c
driv1.o : driv1.c interface1.h
	gcc -c -g driv1.c
mergefiles.o : mergefiles.c interface1.h
	gcc -c -g mergefiles.c
mergesortfiles.o : mergesortfiles.c interface1.h
	gcc -c -g mergesortfiles.c
