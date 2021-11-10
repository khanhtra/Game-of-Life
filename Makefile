output: main.o ca.o
	gcc main.o ca.o -o odca
main.o: main.c
	gcc -c main.c
ca.o: ca.c ca.h
	gcc -c ca.c
clean:
	rm *.o odca