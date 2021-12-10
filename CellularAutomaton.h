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
	void setWidth(int w){width = w;}
	int getHeight(){return height;}
	void setHeight(int h){height = h;}
	unsigned char getcadata(int,int);
	void randomize();
	int getCellGap(){return cellG;}
	int getCellSize(){return cellS;}
	void setCell(int x, int y, int value){cadata[y][x] = value;};
	void setCellGap(int cg){cellG = cg;}
	void setCellSize(int cs){cellS = cs;}
	void setZero();

	
	
private:

	int width;
	int height;
	unsigned char ** cadata;
	int Qstate;
	int cellG;
	int cellS;
 
	
	
	

};

#endif
