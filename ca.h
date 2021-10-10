#ifndef CA_H
#define CA_H


struct ca_data
{
int cells;
unsigned char initialState;
unsigned char* arrayP;
unsigned char arrayTest[3];
int stateAmount;
int wrapState;

};
void display1DCA(struct ca_data*);
int set1DCA(struct ca_data*, unsigned int, unsigned char);
void init1DCA(struct ca_data*, int);
struct ca_data* create1DCA(int, unsigned char);
void stepCA (struct ca_data*, unsigned char(*) (struct ca_data*, int), int);

#endif
