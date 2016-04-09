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

/* String Functions */
char* create_string(char* value);
void free_string(char* value);
int StringEquals(void* ls, void* rs);
int isStringAnInteger(char *string);

/* User Input Functions */
int get_integer(char *message);
char getYesNo(char *message);


