/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include "../../header.h"

typedef struct LL
{
	int int_val;
	float real_val;
	bool bool_val;
	char* str_val;
	
	struct LL *next;
}LL;

LL *create_node(int int_val, float real_val, bool bool_val, char* str_val);
LL *search_list(LL *head, char *str_val);

LL *add_to_front(LL *head, int int_val, float real_val, bool bool_val, char* str_val);
void add_to_back(LL *head, int int_val, float real_val, bool bool_val, char* str_val);

void print_list(LL *head);
void free_list(LL *head);
