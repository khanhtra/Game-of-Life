#include <stdio.h>
#include "ca.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char* argv[]){

int OneOrTwo = atoi (argv[1]);
char* path = argv[2];
int rows;
int cols;
unsigned char temp;
struct ca_data* test;
char ch;


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

	
	
	if (caData->cadata[x][y] == 0 && count == 3){
	value = 1;
	}
	if (caData->cadata[x][y] == 1 && (count == 2 || count == 3)){
	value = 1;
	}
	else{
	value = 0;
	}
	
	return value;
	
}
/*
struct ca_data* testt;
testt = create2DCA(5,5,2);
step2DCA(testt, ruleCA);
displayCA(testt);
*/

FILE *ptr = fopen(path, "r");

/*Error Checking*/
if (ptr == NULL){

	printf("Error!\n");
	exit(1);
}
if (OneOrTwo == 2){

/*Read file contents*/

fscanf(ptr, "%d %d" , &rows, &cols);


printf("Rows: %d\n", rows);
printf("Cols: %d\n\n", cols);
printf("\n");

/*Transfer contents into CA*/

test->height = rows;
test->width = cols;

test = create2DCA(test->width, test->height, 0);
test->wrap = 1;

for (unsigned int i = 0; i < test->height; i++){
	for (unsigned int j = 0; j < test->width; j++){
		fscanf(ptr, "%u", &temp);
		set2DCACell(test,j, i, temp);
	}

}
displayCA(test);

/*While user input is not a char, step through CA every time enter is pressed*/

do {

	scanf("%c", &ch);
	
	if (isalpha(ch)){
		break;
}
	//step2DCA(test, ruleCA);
	displayCA(test);
}
while (ch != 'c');	


/*
/*Close file after reading*/
fclose(ptr);
return 0;
}
}



