/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include "../../Utilities/utilities.h"

typedef struct AVL
{
	int height;
	char* key;
	int frequency;/*the number of times that string was inserted*/
	
	int int_val;
	float real_val;
	bool bool_val;
	char* str_val;
	
	struct AVL *left;
	struct AVL *right;
}AVL;

AVL* insert_to_tree(AVL *head, char *key);
void print_tree(AVL* head);
void free_tree(AVL *head);

int height(AVL *head);
AVL* find(AVL* head, char *key);
int find_max(int num1, int num2);
AVL* find_min(AVL* head);

AVL* single_rotate_left(AVL *head);
AVL* double_rotate_left(AVL *head);

AVL* single_rotate_right(AVL *head);
AVL* double_rotate_right(AVL *head);
