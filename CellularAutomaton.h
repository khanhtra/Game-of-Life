#ifndef CA_H
#define CA_H


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include "GraphicsClient.h"
#include <vector>



using namespace std;

class CellularAutomaton {

public:
	CellularAutomaton();
	CellularAutomaton(std::string, int);
	CellularAutomaton(const CellularAutomaton& objCopy);
	~CellularAutomaton();
	CellularAutomaton& operator= (const CellularAutomaton& objCopy);
	void step(CellularAutomaton*, unsigned char(*) (CellularAutomaton*, int, int));
	void display(GraphicsClient& GC);
	int getWidth(){return width;}
	int getHeight(){return height;}
	unsigned char getcadata(int,int);
	//unsigned char ** cadata;
	
	
private:

	int width;
	int height;
	unsigned char ** cadata;
	int Qstate;
 
	
	
	

};

#endif
