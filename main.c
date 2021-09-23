#include <stdio.h>
#include "dca1d.h"
int main ()
{
unsigned char array[25];

int a;
init1DCA(25, array);
for (int i = 0; i < 25; i++){
if (i % 2 == 0){
a = i;
set1DCACell(array, a, 2);
}
else {
a = i;
set1DCACell(array, a, 1);
}
}
display1DCA(array, 25);
/*set method only works if I initialize an int variable first, Question: Is it supposed to work like this?*/
set1DCACell(array, a, 7);
return 0;
}
