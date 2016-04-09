#include "./DataStructures/AVLTree/avl_tree.h"

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

/* 
 * String Functions 
char* create_string(char* value);
void free_string(char* value);
int StringEquals(void* ls, void* rs);
int isStringAnInteger(char *string);
*/

/* 
 * User Input Functions 
int get_integer(char *message);
char getYesNo(char *message);
*/


/* 
 * Linked List 
LL *create_node(int int_val, float real_val, bool bool_val, char* str_val);
LL *search_list(LL *head, char *str_val);
LL *add_to_front(LL *head, int int_val, float real_val, bool bool_val, char* str_val);
void add_to_back(LL *head, int int_val, float real_val, bool bool_val, char* str_val);
void print_list(LL *head);
void free_list(LL *head);
*/ 

/*
 *  Hash Table 
HT *create_hash_table(int size);
unsigned int hash(HT *hashtable, char *str);
int add_element(HT *table, char *str_val);
LL *lookup_element(HT *table, char *str_val);
void free_table(HT *table);
*/

/* 
 * AVL Tree 
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
*/ 
