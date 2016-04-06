/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <signal.h>

/*typedef enum {false=0, true=1} bool;*/
typedef enum { TYPE_ONE, TYPE_TWO } myenum;

union union_value
{
	int int_val;
	float real_val;
	bool bool_val;
	char* str_val;
};

typedef struct MyStruct
{
	int int_val;
	float real_val;
	bool bool_val;
	char* str_val;
}MyStruct;

