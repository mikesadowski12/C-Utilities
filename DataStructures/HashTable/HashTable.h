/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include "../LinkedList/LinkedList.h"

typedef struct HT 
{
    int size;       
    
    LL **table;
} HT;

HT *create_hash_table(int size);
unsigned int hash(HT *hashtable, char *str);

int add_element(HT *table, char *str_val);
LL *lookup_element(HT *table, char *str_val);

void free_table(HT *table);
