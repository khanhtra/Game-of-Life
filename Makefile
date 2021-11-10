output: main.o ca.o
	gcc main.o ca.o -o gol
main.o: main.c
	gcc -c main.c
ca.o: ca.c ca.h
	gcc -c ca.c
clean:
	rm *.o gol
