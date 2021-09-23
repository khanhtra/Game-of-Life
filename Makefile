output: main.o dca1d.o
	g++ main.o dca1d.o -o odca
main.o: main.c
	g++ -c main.c
dca1d.o: dca1d.c dca1d.h
	g++ -c dca1d.c
clean:
	rm *.o odca
