stm : main.o matrix.o regular.o \
	strassen.o strassenB.o strassenA.o
	cc -o stm main.o matrix.o regular.o strassen.o strassenB.o strassenA.o

strassen.o : strassen.c matrix.h
	cc -c strassen.c

strassenA.o : strassenA.c matrix.h
	cc -c strassenA.c

strassenB.o : strassenB.c matrix.h
	cc -c strassenB.c

main.o : main.c matrix.h
	cc -c main.c

matrix.o : matrix.c matrix.h
	cc -c matrix.c

regular.o : regular.c matrix.h
	cc -c regular.c

clean : 
	-rm *.o