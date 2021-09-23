#include <stdio.h>

/*Initialize array method*/

void init1DCA(int cells, unsigned char *startArray){

unsigned char *temp;
temp = startArray;

/*Loops until "cells" target hit and makes everything 0*/
for (int i = 0; i < cells; i++){
temp[i] = 0;
}
}
/*set Array method */
void set1DCACell(unsigned char *start, int index, unsigned char state){
unsigned char *temp;
temp[index] = state;
temp = start;
}

/*Method to output current state of 1DCA*/
void display1DCA (unsigned char *start, int cells){
unsigned char *temp;
temp = start;
/*Display all states until "cells" target*/
for (int i = 0; i < cells; i++){
printf("%u ", start[i]);
}
printf("\n");
}


