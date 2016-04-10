/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include "../AVLTree/avl_tree.h"

typedef struct BST 
{
    int int_val;
	float real_val;
	bool bool_val;
	char* str_val;
   
	struct BST *left;
	struct BST *right;
} BST;

BST *create_node_binary(int int_val, float real_val, bool bool_val, char *str_val);
void insert_binary(BST *head, BST *new_node);
void free_tree_binary(BST *head);

BST *find_binary(BST *head, int key, BST **parent);

void inorder(BST *head);
void preorder(BST *head);
void postorder(BST *head);


