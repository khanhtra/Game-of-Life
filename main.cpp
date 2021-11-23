#include <iostream>
#include "GraphicsClient.h"
#include "CellularAutomaton.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

/*Game of Life rule*/
unsigned char ruleCA(CellularAutomaton* caData, int x, int y){


int count = 0; 
int value;
int bottom, top, left, right;
int temp = 0;

top = (caData->height + y - 1) % caData->height;
bottom = (caData->height + y + 1) % caData->height;
left = (caData->width + x - 1) % caData->width;
right = (caData->width + x + 1) % caData->width;


	count = caData->cadata[top][left] + caData->cadata[top][x] + caData->cadata[top][right] +
		caData->cadata[y][left] +  caData->cadata[y][right] +
		caData->cadata[bottom][left] + caData->cadata[bottom][x] + caData->cadata[bottom][right];

	
	
	if (caData->cadata[y][x] == 0 && count == 3){
	value = 1;
	}
	else if (caData->cadata[y][x] == 1 && (count == 2 || count == 3)){
	value = 1;
	}
	else{
	value = 0;
	}
	
	
	//top = caData->height;
	//cout << " " <<top;
	
	return value;
	
}

/*Takes one command line argument, which is the text file to simulate the Game of Life and displaying cell states in the graphic server*/

int main (int argc, char* argv[]){
char* path = argv[1];
//int port = atoi(argv[2]);
char ch;


GraphicsClient* a = new GraphicsClient ("10.0.2.15", 7777);
CellularAutomaton* b = new CellularAutomaton(path, 1);
//a->setBackgroundColor (126,82,238);
//a->clear();
b->display(*a);

do {

	scanf("%c", &ch);
	if (isalpha(ch)){
		break;
}
	//a->setBackgroundColor(126,82,238);
	a->clear();
	b->step(b, &ruleCA);
	b->display(*a);
}
while (ch != 'c');


}



