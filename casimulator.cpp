#include <iostream>
#include "GraphicsClient.h"
#include "CellularAutomaton.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/ioctl.h>

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

int main (){

/*Time to pause between each step iteration*/
struct timespec tim;
tim.tv_sec = 0;
tim.tv_nsec = 100000000; //.1 second 


/*Create UI Layout*/
GraphicsClient* a = new GraphicsClient ("10.0.2.15", 7777);
CellularAutomaton* ca = new CellularAutomaton ("default", 1);
CellularAutomaton* caLoad;

int i = 0;
int runFlag = 0;
int sizeFlag = 0;
int count;
char message[300];
char fileName[500];
char fileNames[200];
int filePayload;
int first = 6;
int second = 7;
char x;
	
	a->setDrawingColor(77, 72, 108);
	/*Border for UI*/
	
	a->fillRectangle(600, 0, 200, 600); 
	a->setDrawingColor(223,251,250);
	/*Step*/
	a->fillRectangle(610, 60, 180, 40);

	/*
	for (int i = 605, i < 785; i++){
		for (int j = 60, j < 100; j++){
			if (){
			}
			*/
	/*BUTTON LOCATION*/
	/*Run*/
	a->fillRectangle(610, 110, 180, 40);
	
	/*Pause*/
	a->fillRectangle(610, 160, 180, 40);
	
	/*Reset*/
	a->fillRectangle(610, 210, 180, 40);
	
	/*Random*/
	a->fillRectangle(610, 260, 180, 40);
	
	/*Load*/
	a->fillRectangle(610, 310, 180, 40);
	
	/*Clear*/
	a->fillRectangle(610, 360, 180, 40);
	
	/*Quit*/
	a->fillRectangle(610, 410, 180, 40);
	
	/*Size*/
	
	a->fillRectangle(620, 522, 50, 50);	
			
	a->fillRectangle(675, 522, 50, 50);	
			
	a->fillRectangle(730, 522, 50, 50);	
		
	a->repaint();
	
	/*BUTTON TEXT*/
	
	a->setDrawingColor(44,166,144);
	a->drawString(635, 25, "CELLULAR AUTOMATON");
	a->drawString(670, 50, "SIMULATOR");
	
	a->drawString(620, 82, "STEP");
	a->drawString(620, 132, "RUN");
	a->drawString(620, 182, "PAUSE");
	a->drawString(620, 232, "RESET");
	a->drawString(620, 282, "RANDOM");
	a->drawString(620, 332, "LOAD");
	a->drawString(620, 382, "CLEAR");
	a->drawString(620, 432, "QUIT");
	
	a->drawString(660, 500, "SELECT SIZE"); 
	a->drawString(640, 554, "1");
	a->drawString(695, 554, "2");
	a->drawString(750, 554, "3");
	
	
	a->setBackgroundColor(29, 17, 53);
	a->clearRectangle(0,0, 600,600);
	ca->display(*a);
	//a->repaint();

while (i==0){

ioctl(a->getsockfd(), FIONREAD, &count);
read(a->getsockfd(), message, count);

int xC = (message[7] << 12)  | (message[8] << 8) | (message[9] << 4) | (message[10]);
int yC = (message[11] << 12)  | (message[12] << 8) | (message[13] << 4) | (message[14]);

a->setX(xC);
a->setY(yC);

int mouseType = message[5];	

		/*BUTTON LOGIC*/	

		
		//Quit
		/*
		if (a->inRectangle(610,410,790,460) == true && a->getMouseType() == 1){
		break;
		*/
		
		if (runFlag == 1){
			a->setDrawingColor(28,243,127);
			a->fillRectangle(610, 110, 180, 40);
			a->setDrawingColor(44,166,144);
			a->drawString(620, 132, "RUN");
			//a->repaint();
			
			ca->step(ca, ruleCA);
			a->clearRectangle(0,0,600,600);
			ca->display(*a);
			}
			nanosleep(&tim, NULL);
			//Step
	if (count > 0){
	int pX = xC / (ca->getCellSize() + ca->getCellGap());
	int pY = yC / (ca->getCellSize() + ca->getCellGap());
	cout << "X:" << xC << endl;
	cout << "Y:" << yC << endl;
	cout << sizeFlag << endl;
	cout << fileName << endl;
	
	cout << "width: " << ca->getWidth() << endl;
	cout << "height: " << ca->getHeight() << endl;
	
 		if (a->inRectangle(610,60,790,100) == true && mouseType == 1){
				/*Indicates Button is pressed by color*/			
					a->setDrawingColor(28,243,127);
					a->fillRectangle(610, 60, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 82, "STEP");
					a->repaint();
						
				/*Logic for stepping through CA*/
					ca->step(ca, ruleCA);
					a->clearRectangle(0,0, 600,600);
					ca->display(*a);
				}
			//Run
		if (a->inRectangle(610,110,790,150) == true && mouseType == 1){
						/*Indicates Button is pressed and in "run mode"*/
						runFlag = 1;		
							}
				
			//Pause
		if (a->inRectangle(610, 160, 790, 210) == true && mouseType == 1){
						/*Stops run from executing*/
						runFlag = 2;	
			
					a->setDrawingColor(255,51,51);
					a->fillRectangle(610, 160, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 182, "PAUSE");
					a->repaint();
																			
							
					}
				
			//Reset
		if (a->inRectangle(610,210,790,250) == true && mouseType == 1){
					/*Indicates Button is pressed by color*/
					a->setDrawingColor(28,243,127);
					a->fillRectangle(610, 210, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 232, "RESET");
					a->repaint();
					ca = new CellularAutomaton (fileName, 1);
					//Stops random cells from populating every cell
					a->clearRectangle(0,0, 600,600);
					ca->display(*a);
					
				}	
			//Random
		if (a->inRectangle(610,260,790,300) == true && mouseType == 1){
		
					/*Indicates Button is pressed by color*/			
					a->setDrawingColor(28,243,127);
					a->fillRectangle(610, 260, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 282, "RANDOM");
					a->repaint();
							
					//Randomize current CA
					//CellularAutomaton* caR = new CellularAutomaton();
					ca->randomize();
					//Stops random cells from populating every cell
					a->clearRectangle(0,0, 600,600);
					ca->display(*a);
					
				}
			//Load
		if (a->inRectangle(610,310,790,350) == true && mouseType == 1){ 
			delete ca;
					a->setDrawingColor(28,243,127);
					a->fillRectangle(610, 310, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 332, "LOAD");
					a->repaint();
					a->fileMessage();	
					/*Wait for file selection, if successful*/
					while (ioctl(a->getsockfd(), FIONREAD, &count) == 0){
						read(a->getsockfd(), message, count);
						filePayload = (message[1] << 12)  | (message[2] << 8) | (message[3] << 4) | (message[4]);
						if (message[5] == 0x0A){
						break;
						}
					}
						for (int i = 0; i < filePayload ; i++){
						fileName[i] = message[first++] << 4 | message[second++];
						first++;
						second++;
					
					}
					//CellularAutomaton* caLoad = new CellularAutomaton(fileName, 1); //change to test for it to work
					ca = new CellularAutomaton(fileName, 1);
					a->clearRectangle(0,0, 600,600);
					ca->display(*a);	
					
					}	
					
			//Clear 
		if (a->inRectangle(610,360,790,400) == true && mouseType == 1){
		
					/*Indicates Button is pressed by color*/			
					a->setDrawingColor(28,243,127);
					a->fillRectangle(610, 360, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 382, "CLEAR");
					a->repaint();
					
					ca->setZero();
					a->clearRectangle(0,0,600,600);
					ca->display(*a);
					
				}	
			//Quit
		if (a->inRectangle(610,410,790,450) == true && mouseType == 1){ 
					/*Indicates Button is pressed by color*/			
					a->setDrawingColor(28,243,127);
					a->fillRectangle(610, 410, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 432, "QUIT");
					a->repaint();
		break;	
		}
			//Refresh Buttons to original
		if (mouseType == 2){
					//Step cb = "change back"
					a->setDrawingColor(223,251,250);
					a->fillRectangle(610, 60, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 82, "STEP");
					
					//Run cb
					a->setDrawingColor(223,251,250);
					a->fillRectangle(610, 110, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 132, "RUN");
					
					//Pause cb
					a->setDrawingColor(223,251,250);
					a->fillRectangle(610, 160, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 182, "PAUSE");
					
					//Reset cb
					a->setDrawingColor(223,251,250);
					a->fillRectangle(610, 210, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 232, "RESET");
					
					//Random cb
					a->setDrawingColor(223,251,250);
					a->fillRectangle(610, 260, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 282, "RANDOM");
					
					//Load cb
					a->setDrawingColor(223,251,250);
					a->fillRectangle(610, 310, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 332, "LOAD");
					
					//Clear cb
					a->setDrawingColor(223,251,250);
					a->fillRectangle(610, 360, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 382, "CLEAR");
					
					//Quit cb
					a->setDrawingColor(223,251,250);
					a->fillRectangle(610, 410, 180, 40);
					a->setDrawingColor(44,166,144);
					a->drawString(620, 432, "QUIT");
					
					
					
					
					a->repaint();
			}
			//Select Size 
		if (a->inRectangle(620,522,670,577) == true && mouseType == 1){ //1
	
			/*Creates blank CA's with pre-determined sizes supplied by a text file*/
			delete ca;
			ca = new CellularAutomaton("40by40", 1);
			a->clearRectangle(0,0,600,600);
			/*Keeps track of selected size for toggle*/
			sizeFlag = 1;
				}
		if (a->inRectangle(675,522,725, 577) == true && mouseType == 1){ //2
			delete ca;
			ca = new CellularAutomaton("150by150", 1);
			a->clearRectangle(0,0,600,600);
			sizeFlag = 2;
				}
		if (a->inRectangle(735,522,785,577) == true && mouseType == 1){ //3
			delete ca;
			ca = new CellularAutomaton("600by600", 1);
			a->clearRectangle(0,0,600,600);
			sizeFlag = 3;
				}
				
			//Toggle cells logic
			
				/*Default Size Toggle*/
		if (a->inRectangle(0,0,480,480) == true && mouseType == 1 && sizeFlag == 0){
			/*Get (x,y) of CA relative to the "click" position on server*/
			int pX = xC / (ca->getCellSize() + ca->getCellGap());
			int pY = yC / (ca->getCellSize() + ca->getCellGap());
			
			/*Toggle cells from 0 to 1 or 1 to 0 then update to server*/
			if (ca->getcadata(pY,pX) == 0){
			ca->setCell(pX,pY, 1);
			ca->display(*a);
			}
			else if (ca->getcadata(pY,pX) == 1){
			ca->setCell(pX,pY, 0);
			a->clearRectangle(0,0,600,600);
			ca->display(*a);
			}
			}
				/*Size 1 Toggle*/
		if (a->inRectangle(0,0,480,480) == true && mouseType == 1 && sizeFlag == 1){
			/*Get (x,y) of CA relative to the "click" position on server*/
			int pX = xC / (ca->getCellSize() + ca->getCellGap());
			int pY = yC / (ca->getCellSize() + ca->getCellGap());
			
			/*Toggle cells from 0 to 1 or 1 to 0 then update to server*/
			if (ca->getcadata(pY,pX) == 0){
			ca->setCell(pX,pY, 1);
			ca->display(*a);
			}
			else if (ca->getcadata(pY,pX) == 1){
			ca->setCell(pX,pY, 0);
			a->clearRectangle(0,0,600,600);
			ca->display(*a);
			}
			}
			
				/*Size 2 Toggle*/			
		if (a->inRectangle(0,0,450,450) == true && mouseType == 1 && sizeFlag == 2){
			/*Get (x,y) of CA relative to the "click" position on server*/
			int pX = xC / (ca->getCellSize() + ca->getCellGap());
			int pY = yC / (ca->getCellSize() + ca->getCellGap());
			
			/*Toggle cells from 0 to 1 or 1 to 0 then update to server*/
			if (ca->getcadata(pY,pX) == 0){
			ca->setCell(pX,pY, 1);
			ca->display(*a);
			}
			else if (ca->getcadata(pY,pX) == 1){
			ca->setCell(pX,pY, 0);
			a->clearRectangle(0,0,600,600);
			ca->display(*a);
			}
			
			
		}		/*Size 3 Toggle*/
		if (a->inRectangle(0,0,600,600) == true && mouseType == 1 && sizeFlag == 3){
			/*Get (x,y) of CA relative to the "click" position on server*/
			int pX = xC / (ca->getCellSize() + ca->getCellGap());
			int pY = yC / (ca->getCellSize() + ca->getCellGap());
	
			/*Toggle cells from 0 to 1 or 1 to 0 then update to server*/
			if (ca->getcadata(pY,pX) == 0){
			ca->setCell(pX,pY, 1);
			ca->display(*a);
			}
			else if (ca->getcadata(pY,pX) == 1){
			ca->setCell(pX,pY, 0);
			a->clearRectangle(0,0,600,600);
			ca->display(*a);
			}
			
			
		}
			}
	
}
}


