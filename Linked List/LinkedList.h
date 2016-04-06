/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include "../header.h"

typedef struct LL
{
	int int_val;
	float real_val;
	bool bool_val;
	char* str_val;
	
	struct LL *next;
}LL;
