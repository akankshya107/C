dothis : runIterMS runRecMS
runIterMS: compIterMS
	./progiter
runRecMS: compRecMS
	./progrec
compIterMS : impl.o readEle.o merge.o mergesortiter.o driv1.o
	gcc -g impl.o readEle.o merge.o mergesortiter.o driv1.o -o progiter
compRecMS : impl.o readEle.o merge.o mergesortrec.o driv1.o
	gcc -g impl.o readEle.o merge.o mergesortrec.o driv1.o -o progrec
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

