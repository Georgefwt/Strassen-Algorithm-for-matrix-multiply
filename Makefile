stm : main.o matrix.o regular.o /
	strassen.o strassenB.o strassenA.o
	cc -o stm main.o matrix.o regular.o strassen.o strassenB.o strassenA.o

main.o : main.c matrix.h
	cc -c main.c

matrix.o : matrix.c matrix.h
	cc -c matrix.c

regular.o : regular.c matrix.h
	cc -c regular.c

strassen.o : strassen.c matrix.h
	cc -c strassen.c

strassen.o : strassenA.c matrix.h
	cc -c strassenA.c

strassen.o : strassenB.c matrix.h
	cc -c strassenB.c

clean : 
	-rm *.o