output: main.o CellularAutomaton.o GraphicsClient.o
	g++ main.o CellularAutomaton.o GraphicsClient.o -o gol
main.o: main.c
	g++ -c main.cpp
CellularAutomaton.o: CellularAutomaton.cpp CellularAutomaton.h 
	g++ -c CellularAutomaton.cpp
GraphicsClient.o: GraphicsClient.h GraphicsClient.cpp
	g++ -c GraphicsClient.cpp
clean:
	rm *.o gol
