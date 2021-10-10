#include <stdio.h>
#include "ca.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Initialize array method*/

void init1DCA(struct ca_data* caData, int changeNums){

for (int i = 0; i < caData->cells; i++){
	if (changeNums == -1){
		caData -> arrayP[i] = rand() % (caData->stateAmount - 1 + 1 - 0 ) + 0; 
		caData->initialState = 0;
	}
	else {
		caData -> arrayP[i] = changeNums; 
	}
}
}
/*set Array method */
int set1DCACell(struct ca_data* caData, unsigned int index, unsigned char state){

caData -> arrayP[index] = state;
return 0;

}

/*Method to output current state of 1DCA*/
void display1DCA (struct ca_data* caData){
/*Display all states until "cells" target*/
for (int i = 0; i < caData->cells; i++){
	printf("%u ", caData-> arrayP[i]);
	}
printf("\n");
}

struct ca_data* create1DCA(int cellAmount, unsigned char initialNumbers){

struct ca_data* cData = (struct ca_data*) malloc (sizeof (struct ca_data)); 
cData -> arrayP = malloc (sizeof (unsigned char) * cellAmount);

for (int i = 0; i < cellAmount; i++){
	cData->arrayP[i] = initialNumbers;
}

cData ->cells = cellAmount;
cData ->initialState = initialNumbers;
return cData;
}
void stepCA (struct ca_data* caData, unsigned char(*rule) (struct ca_data* caMod, int index), int flag){

unsigned char tempArray[caData->cells + 2]; 
struct ca_data* tempCA = (struct ca_data*) malloc (sizeof (struct ca_data));
tempCA -> arrayP = malloc (sizeof (unsigned char) * caData->cells);
unsigned char end;
unsigned char start;

/*Copy array with padding and hold an array to copy over*/

for (int i = 1; i < caData->cells+1; i++){ 
	tempCA->arrayP[i] = caData->arrayP[i-1];
	}
/*Wrap Conditions*/	
if (flag == 1){
	tempCA->arrayP[0] = caData->arrayP[caData->cells - 1]; 
	tempCA->arrayP[caData->cells+1] = caData->arrayP[0];		
}	
if (flag == 0){
	tempCA->arrayP[0] = caData->initialState;
	tempCA->arrayP[caData->cells+1] = caData->initialState;	
	
	}
/*Change CA according to rule function*/	
for (int i = 0; i < caData->cells; i++){ 
	caData->arrayP[i] = rule(tempCA, i+1); 
}
}
			






