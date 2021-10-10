#include <stdio.h>
#include "ca.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned char ruleCA(struct ca_data* caData, int index){

	unsigned char newValue;

/*Rule for white*/
	if (caData->arrayP[index - 1] == 1 && caData->arrayP[index + 1] == 1 && caData->arrayP[index] == 0){
	newValue = 1;
 	}
 	if (caData->arrayP[index - 1] == 1 && caData->arrayP[index + 1] == 0 && caData->arrayP[index] == 0){
 	newValue = 0;
 	}
 	if (caData->arrayP[index - 1] == 0 && caData->arrayP[index + 1] == 1 && caData->arrayP[index] == 0){
 	newValue = 1;
 	}
 	if (caData->arrayP[index - 1] == 0 && caData->arrayP[index + 1] == 0 && caData->arrayP[index] == 0){
 	newValue = 0; 
 	}
 	
/*Rule for black*/ 	
	if (caData->arrayP[index - 1] == 1 && caData->arrayP[index + 1] == 1 && caData->arrayP[index] == 1){
	newValue = 0; 
 	}
 	if (caData->arrayP[index - 1] == 1 && caData->arrayP[index + 1] == 0 && caData->arrayP[index] == 1){
 	newValue = 1;
 	}
 	if (caData->arrayP[index - 1] == 0 && caData->arrayP[index + 1] == 1 && caData->arrayP[index] == 1){
 	newValue = 1;
 	}
 	if (caData->arrayP[index - 1] == 0 && caData->arrayP[index + 1] == 0 && caData->arrayP[index] == 1){
 	newValue = 1;
 	}	

/*
	if(caData->arrayP[index] != 0 && caData->arrayP[index] != 1){
	printf("Can't calculate rule if not 0 or 1!");
	}*/
	return newValue;
	
}

int main (int argc, char* argv[]){

int cells = atoi(argv[1]);
int states = atoi(argv[2]);
char* flag = (argv[3]);
int initialState = atoi(argv[4]);
int steps = atoi(argv[5]);
int tempFlag; 

struct ca_data* test;

/*Error Checking-Cells*/
if (cells > 100 || cells < 10){
	printf("Please enter a number (10-100) for cells and re-run the program! \n\n");
	return 0;
	}
/*Error Checking-States*/	
if(states <= 0){
	printf("Please enter a valid number of states (a NUMBER greater or equal to 1), when re-running the program!\n");
	return 0;
	}
/*Error Checking-Wrapping*/	
if (strcmp(flag, "wrap") == 0){
	tempFlag = 1;
}

if (strcmp(flag, "nowrap") == 0){
	tempFlag = 0;
	//test->wrapState = 0; I get seg-faulted if I do this can you explain why? That's why I used a tempFlag to assign it later.
}
if(strcmp(flag, "nowrap") != 0 && strcmp(flag, "wrap") != 0){
	printf("Please enter wrap or nowrap!\n");
	return 0;
	}

	
/*Error Checking-Initial State*/ //Change later
if(initialState >= states){
	printf("Please enter a valid initial state: (0 to %d) or input: -1 for random, when re-running the program!\n", states - 1);
	return 0;
}
/*Error Checking-Steps*/
if(steps <= 0){
	printf("Please enter a valid number of steps (a NUMBER greater or equal to 1), when re-running the program!\n");
	return 0;
	}
	
printf("Cells: %d\n", cells);
printf("Number of states: %d\n", states);
printf("Wrap or No wrap: %s\n", flag);
if (initialState == -1){
	printf("Initial State: random\n");
	}
else {
	printf("Initial State: %d\n", initialState);
}
printf("Steps: %d\n\n", steps);

/*Create 1DCA and change according to prompts*/

test = create1DCA(cells, 0);
test->stateAmount = states;
test->wrapState = tempFlag;
test->initialState = initialState;
init1DCA(test, initialState); 
display1DCA(test);

for (int i = 0; i < steps; i++){ 
	stepCA(test, ruleCA, test->wrapState);
	display1DCA(test); 
	}

return 0;
}
