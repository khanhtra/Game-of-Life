#include <stdio.h>
#include "ca.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Initialize array method*/

void initCA(struct ca_data* caData, int changeNums){

for (int i = 0; i < caData->height; i++){
	for (int j = 0; j < caData->width; j++){
		if (changeNums == -1){
			caData -> cadata[0][i] = rand() % (caData->stateAmount - 1 + 1 - 0 ) + 0; 
			caData->initialState = 0;
		}
		else {
			caData -> cadata[i][j] = changeNums; 
		}
}
}
}
/*set Array method */
int set1DCACell(struct ca_data* caData, unsigned int index, unsigned char state){

caData -> cadata[0][index] = state;
return 0;

}

/*Set 2d cell at (x,y) location)*/
int set2DCACell(struct ca_data* caData, unsigned int x, unsigned int y, unsigned char state){

caData -> cadata[y][x] = state;
return 0;

}

/*Method to output current state of CA*/
void displayCA (struct ca_data* caData){
/*Display all states until "cells" target*/
for (int i = 0; i < caData->height; i++){
	for (int j = 0; j < caData->width; j++){
		printf("%u ", caData-> cadata[i][j]);
	}
printf("\n");
}
}

struct ca_data* create1DCA(int cellAmount, unsigned char initialNumbers){

struct ca_data* cData = (struct ca_data*) malloc (sizeof (struct ca_data)); 
cData -> cadata = malloc (sizeof (unsigned char) * cellAmount);
cData -> cadata[0] = malloc (sizeof (unsigned char*));

for (int i = 0; i < cellAmount; i++){
	cData->cadata[0][i] = initialNumbers;
}

cData ->cells = cellAmount;
cData ->height = 1;
cData ->width = cellAmount;
cData ->initialState = initialNumbers;

return cData;
}

/*Create a 2DCA according to width and height*/
struct ca_data* create2DCA(int w, int h, unsigned char qstate){

struct ca_data* cData = (struct ca_data*) malloc (sizeof (struct ca_data) * w * h);

cData-> cadata = malloc (sizeof (unsigned char *) * h);
for (int i = 0; i < h; i++){
	cData->cadata[i] = malloc (sizeof (unsigned char) * w);
}
for (int i = 0; i < h; i++){
	for (int j = 0; j < w; j++){
		cData->cadata[i][j] = qstate;
	}

}
cData ->width = w;
cData ->height = h;
cData ->initialState = qstate;
//cData ->wrap = 1;
return cData;

}


void step1DCA (struct ca_data* caData, unsigned char(*rule) (struct ca_data* caMod, int index)){

struct ca_data* tempCA = (struct ca_data*) malloc (sizeof (struct ca_data));
tempCA -> cadata = malloc (sizeof (unsigned char) * caData->cells);
tempCA -> cadata[0] = malloc (sizeof (unsigned char*));


/*Copy array with padding and hold an array to copy over*/

for (int i = 1; i < caData->cells+1; i++){ 
	tempCA->cadata[0][i] = caData->cadata[0][i-1];
	}
/*Wrap Conditions*/	
if (tempCA->wrap == 1){
	tempCA->cadata[0][0] = caData->cadata[0][caData->cells - 1]; 
	tempCA->cadata[0][caData->cells+1] = caData->cadata[0][0];		
}	
if (tempCA->wrap == 0){
	tempCA->cadata[0][0] = caData->initialState;
	tempCA->cadata[0][caData->cells+1] = caData->initialState;	
	
	}
/*Change CA according to rule function*/	
for (int i = 0; i < tempCA->height; i++){ 
	for (int j = 0; j < tempCA->width; j++){
	caData->cadata[j][i] = rule(tempCA, j+1); 
}
}
}

void step2DCA(struct ca_data* ca, unsigned char(*rule) (struct ca_data*, int x, int y)){

//j = "x", i = "y"
unsigned char copyArray[ca->height][ca->width];

/*Copy array so it isn't cadata is not modified during rule*/
for (int i = 0; i < ca->width; i++){
	for (int j = 0; j < ca->height; j++){
	copyArray[j][i] = ca->cadata[j][i];
}
}
/*Change copy array according to cadata*/
for (int i = 0; i < ca->width; i++){
	for (int j = 0; j < ca->height; j++){
	copyArray[j][i] = rule(ca, i,j);
}
}
//copyArray[0][0] = rule(ca, 0, 0);
/*Copy modifed array back to cadata*/
for (int i = 0; i < ca->width; i++){
	for (int j = 0; j < ca->height; j++){
	ca->cadata[j][i] = copyArray[j][i];
}
}
}
/*
unsigned char ruleCA(struct ca_data* caData, int x, int y){

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
	
	return value;
	
}

/*
int main (){
struct ca_data* test;
test = create2DCA(7,10, 0);

/*
set2DCACell(test,1, 3, 1);
set2DCACell(test,1, 4, 1);
set2DCACell(test,1, 5, 1);



//Hole Test
set2DCACell(test,1, 2, 1);
set2DCACell(test,2, 2, 1);
set2DCACell(test,1, 3, 1);

set2DCACell(test,4, 4, 1);
set2DCACell(test,4, 5, 1);
set2DCACell(test,3, 5, 1);





displayCA(test);
printf("\n");

for (int i = 0; i < 5; i++){
step2DCA(test, ruleCA);
displayCA(test);
printf("\n");


}
}
*/




