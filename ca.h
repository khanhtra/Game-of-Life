#ifndef CA_H
#define CA_H


struct ca_data
{
int cells;
unsigned char initialState;
unsigned char** cadata;
int width;
int height;
unsigned char arrayTest[3]; //delete later
int stateAmount;
unsigned char wrap;
unsigned char dimension;

};
void displayCA(struct ca_data*);
int set1DCACell(struct ca_data*, unsigned int, unsigned char);
int set2DCACell(struct ca_data*, unsigned int, unsigned int, unsigned char);
void initCA(struct ca_data*, int);

struct ca_data* create1DCA(int, unsigned char);
struct ca_data* create2DCA(int, int, unsigned char);

void step1DCA (struct ca_data*, unsigned char(*) (struct ca_data*, int));
void step2DCA (struct ca_data*, unsigned char(*) (struct ca_data*, int, int));

#endif
