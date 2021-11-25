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

top = (caData->getHeight() + y - 1) % caData->getHeight();
bottom = (caData->getHeight() + y + 1) % caData->getHeight();
left = (caData->getWidth() + x - 1) % caData->getWidth();
right = (caData->getWidth() + x + 1) % caData->getWidth();


	count = caData->getcadata(top,left) + caData->getcadata(top,x) + caData->getcadata(top,right) +
		caData->getcadata(y,left) +  caData->getcadata(y,right) +
		caData->getcadata(bottom,left) + caData->getcadata(bottom,x) + caData->getcadata(bottom,right);

	
	
	if (caData->getcadata(y,x) == 0 && count == 3){
	value = 1;
	}
	else if (caData->getcadata(y,x) == 1 && (count == 2 || count == 3)){
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
char ch;

GraphicsClient* a = new GraphicsClient ("10.0.2.15", 7777);
CellularAutomaton* b = new CellularAutomaton(path, 1);
//printf("%u", b->getcadata(0,0));
//CellularAutomaton c (path, 1);
//CellularAutomaton b;
//b = c; Assignment Operator
//CellularAutomaton b = c; Copy Constructor
//GraphicsClient* c = a;
//a->setBackgroundColor (126,82,238);
//a->clear();

/*Test for "new" create object*/

b->display(*a);

	do {

		scanf("%c", &ch);
		if (isalpha(ch)){
		delete a;
		delete b;
		break;
	}
		//a->setBackgroundColor(126,82,238);
		a->clear();
		b->step(b, &ruleCA);
		b->display(*a);
		
	}
	while (ch != 'c');
	}
	
	/* Test for copy constructor and assignment operator 
b.display(*a);

	do {

		scanf("%c", &ch);
		if (isalpha(ch)){
		//delete a;
		//delete b;
		break;
	}
		//a->setBackgroundColor(126,82,238);
		a->clear();
		b.step(&b, &ruleCA);
		b.display(*a);
		
	}
	while (ch != 'c');
	}
	*/


