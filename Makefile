output: casimulator.o CellularAutomaton.o GraphicsClient.o
	g++ casimulator.o CellularAutomaton.o GraphicsClient.o -o CASimulator
casimulator.o: casimulator.cpp
	g++ -c casimulator.cpp
CellularAutomaton.o: CellularAutomaton.cpp CellularAutomaton.h 
	g++ -c CellularAutomaton.cpp
GraphicsClient.o: GraphicsClient.h GraphicsClient.cpp
	g++ -c GraphicsClient.cpp
clean:
	rm *.o CASimulator
