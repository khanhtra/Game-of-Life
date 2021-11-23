
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "CellularAutomaton.h"
#include "GraphicsClient.h"
#include <fstream>


 
using namespace std;

/*Default values for a CA object*/
CellularAutomaton::CellularAutomaton(){
//width = 0;
//height = 0;
Qstate = 0;

}

/*Creates an CA object specified by a file*/
CellularAutomaton::CellularAutomaton(std::string fileName, int qState){
	
	int rows, cols;
	char* temp = &(fileName[0]);
	int tempCell;
	FILE *ptr = fopen(temp, "r");

	/*Error Checking*/
	if (ptr == NULL){

		printf("Error! File could not be found!\n");
		exit(1);
	}
	

	/*Read file contents*/

	fscanf(ptr, "%d %d" , &rows, &cols);


	//printf("Rows: %d\n", rows);
	//printf("Cols: %d\n\n", cols);


	/*Creates a dynamic 2d array, depending on height and width*/

	height = rows;
	width = cols;
	//cout << width << height;
	this->cadata = new unsigned char * [height];
	for (int i = 0; i < height; i++){
		this->cadata[i] = new unsigned char [width];
	}
	
	/*Sets the quint. state for CA*/
	Qstate = qState;
	//cout << Qstate;

	for (unsigned int i = 0; i < height; i++){
		for (unsigned int j = 0; j < width; j++){
			fscanf(ptr, "%d", &tempCell);
			this->cadata[i][j] = tempCell;
			//cout << this->cadata[i][j] << "s";
			//printf("%u", this->cadata[i][j]);
		}

	}
	/*Close file after reading*/
	fclose(ptr);
	




}

CellularAutomaton::CellularAutomaton(const CellularAutomaton& copyObj){


}

CellularAutomaton::~CellularAutomaton(){
delete this;
}

CellularAutomaton& CellularAutomaton::operator=(const CellularAutomaton& copyObj){
	if (this != &copyObj){
		
	}

return *this;
}

/*Simulates one step of a CA using a specified rule*/
void CellularAutomaton::step(CellularAutomaton* ca, unsigned char(*rule) (CellularAutomaton *, int x, int y)){

unsigned char copyArray[this->height][this->width];

/*Copy array so it isn't cadata is not modified during rule*/
for (int i = 0; i < this->width; i++){
	for (int j = 0; j < this->height; j++){
	copyArray[j][i] = this->cadata[j][i];
}
}
/*Change copy array according to cadata*/
for (int i = 0; i < this->width; i++){
	for (int j = 0; j < this->height; j++){
	copyArray[j][i] = rule(this, i,j);
	//printf("%d %d \n", i, j); 
}
}
//copyArray[0][0] = rule(ca, 0, 0);
/*Copy modifed array back to cadata*/
for (int i = 0; i < this->width; i++){
	for (int j = 0; j < this->height; j++){
	this->cadata[j][i] = copyArray[j][i];
}
}
}

/*Displays the current state of an CA object on the graphics server*/
void CellularAutomaton::display(GraphicsClient& graphicsClient){

int cellSize;
int cellGap;
int maxSize = max(this->width, this->height);
//cout << maxSize;
/*Obtain cell sizes and cell gaps depending on CA width and height*/
if (maxSize > 200 && maxSize <= 600){
	cellSize = 1;
	cellGap = 0;
}
else if (maxSize > 100 && maxSize <= 200){
	cellSize = 2;
	cellGap = 1;
}
else if (maxSize > 50 && maxSize <= 100){
	cellSize = 4;
	cellGap = 1;
}
else if (maxSize > 1 && maxSize <= 50){
	cellSize = 10;
	cellGap = 2;
}


	/*Draw Rectangles for each CA state, solid = alive, non-solid = dead*/
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
		//int a = i * 20;
		//int b = j * 20;
		//printf("%d", this->cadata[j][i]);
			if (this->cadata[j][i] == 1){
			graphicsClient.fillRectangle(i * (cellSize + cellGap), j * (cellSize + cellGap), cellSize, cellSize);
			//graphicsClient.drawString(i * 40 + (i * 5) + 10,j * 40 + (j * 5) + 10, "alive");
			//graphicsClient.repaint();
			}
			else if (this->cadata[j][i] == 0){
			graphicsClient.drawRectangle(i * (cellSize + cellGap), j * (cellSize + cellGap), cellSize, cellSize);
			//graphicsClient.drawString(i * 40 + (i * 5) + 10,j * 40 + (j * 5) + 10, "dead");
			//graphicsClient.repaint();
			}
			}
	}
	graphicsClient.repaint();
	
}



