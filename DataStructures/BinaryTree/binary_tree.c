/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include "binary_tree.h"

int main ()
{
	BST *head = NULL;
	BST *node = NULL;
	
	head = create_node_binary(0,0.0,true,"head");
	
	if(node != NULL) { printf("node: %d\n", node->int_val); }
	
	insert_binary(head, create_node_binary(0,0.0,true,"hello"));	
	insert_binary(head, create_node_binary(0,0.0,true,"hello2"));
	
	inorder(head);
	
	free_tree_binary(head);
	
	return 1;
}

/* 
 * Name: create_node_binary()
 * Description: 
 * Parameters:
 * Return:
*/
BST *create_node_binary(int int_val, float real_val, bool bool_val, char *str_val) 
{
	BST *head = NULL;
   
	head = (BST *) malloc(sizeof(BST));
	head->str_val = (char *) malloc (sizeof(char) * 999);

	head->int_val = 0;
	head->real_val = 0.0;
	head->bool_val = false;
	strcpy(head->str_val, " ");
	 
	head->left = NULL;
	head->right = NULL;
   
	return head;
}

/* 
 * Name: insert_binary()
 * Description: 
 * Parameters:
 * Return:
*/
void insert_binary(BST *head, BST *new_node) 
{
	if (new_node->int_val < head->int_val) 
	{
		if (head->left == NULL)
		{
			head->left = new_node;
		}
		else
		{
			insert_binary(head->left, new_node);
		}
	}
 
	if (new_node->int_val > head->int_val) 
	{
		if (head->right == NULL)
		{
			head->right = new_node;
		}
		else
		{
			insert_binary(head->right, new_node);
		}
	}
}

/* 
 * Name: find()
 * Description: 
 * Parameters:
 * Return:
*/
BST *find_binary(BST *head, int key, BST **parent) 
{
	BST *temp = NULL;
	temp = head;
   
	while (temp != NULL) 
	{
		if (temp->int_val == key) 
		{
			printf("\nFound %d", temp->int_val);
			return temp;
		}
		
		*parent = temp;
 
		if (temp->int_val > key) { temp = temp->left; }	
		else { temp = temp->right; }
	}
	
	return NULL;
}

/* 
 * Name: inorder()
 * Description: 
 * Parameters:
 * Return:
*/
void inorder(BST *head) 
{
	if (head != NULL) 
	{
		inorder(head->left);
		printf("%d", head->int_val);
		inorder(head->left);
	}
}

/* 
 * Name: preorder()
 * Description: 
 * Parameters:
 * Return:
*/
void preorder(BST *head) 
{
	if (head != NULL) 
	{
		printf("%d", head->int_val);
		preorder(head->left);
		preorder(head->right);
	}
}

/* 
 * Name: postorder()
 * Description: 
 * Parameters:
 * Return:
*/
void postorder(BST *head)
{
	if (head != NULL) 
	{
		postorder(head->left);
		postorder(head->right);
		printf("%d", head->int_val);
	}
}

void free_tree_binary(BST *head)
{
    if( head != NULL )
    {
        free_tree_binary( head->left );
        free_tree_binary( head->right );
        free( head->str_val );
        free( head );
    }	
}
