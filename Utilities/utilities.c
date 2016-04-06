/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include "utilities.h"

/* Name: get_integer()
 * Description: Allows a user to enter an integer
 * Parameters: none
 * Return: the integer
*/ 
int get_integer(char *message) 
{	
	char input[256] = {0};
	int errorFlag = 1; /* assume input is wrong */
	
	/*loop until user enters a string that is an integer*/
	do
	{
		printf("%s", message);
		fgets(input, sizeof(input), stdin);
	
		if ( isStringAnInteger(input) ) { errorFlag = 0; }
	} while (errorFlag);

	return atoi(input);
}

char* create_string(char* value)
{
	char *s = (char *) malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(s, value);
	return s;
}

void free_string(char* value)
{
	free(value);
}

int StringEquals(void* ls, void* rs)
{
	return !strcmp(ls, rs);
}

/* Name: isStringAnInteger()
 * Description: Determines if string contains an integer or not
 * Parameters: string: the string to be checked
 * Return: NOTINTEGER=0 if it failed, ISINTEGER=1 if passed
*/ 
int isStringAnInteger(char *string)
{
	int i = 0;
		
	for (i = 0; i < strlen(string); i++) 
	{	
		if ( !isdigit(string[i]) )
		{
			if ( string[i] != '\n' ) /*checking new line since it is contained in the string*/
			{
				return 0; /* if it was not a number and not a new line, return it is incorrect*/
			}
		}	
	}
	
	return 1;
}

/* Name: getYesNo
 * Description: gets user to input yes or no
 * Parameters: message: a message to print
 * Return: y for yes, n for no
*/ 
char getYesNo(char *message)
{
	char userInput[256] = {""};
	int errorFlag = 1; /* assume input is wrong */
	int yes = 0;
	int no = 0;
	
	/* loop until user enters a a proper response */
	do
	{
		printf("%s", message);
		fgets(userInput, sizeof(userInput), stdin);
	
		if ( strcmp(userInput, "y\n") == 0 || strcmp(userInput, "Y\n") == 0 || strcmp(userInput, "yes\n") == 0 
			|| strcmp(userInput, "YES\n") == 0 )
		{
			yes = 1;
			errorFlag = 0;
		}	
		else if ( strcmp(userInput, "n\n") == 0 || strcmp(userInput, "n\n") == 0 
			|| strcmp(userInput, "no\n") == 0 || strcmp(userInput, "NO\n") == 0  ) 
		{ 
			no = 1;
			errorFlag = 0; 
		}
	} while (errorFlag);	
	
	if ( yes ) { return 'y'; }
	if ( no ) { return 'n'; }
	
	return 'e'; /* error */
}
