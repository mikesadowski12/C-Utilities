/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include "avl_tree.h"

int main()
{
	AVL *tree = NULL;

	tree = insert_to_tree(tree, "1");	
	tree = insert_to_tree(tree, "2");	
	tree = insert_to_tree(tree, "3");		
	tree = insert_to_tree(tree, "4");
	
	print_tree(tree);
	
	free_tree(tree);
	return 1;
	
}

/* 
 * Name: insert_to_tree()
 * Description: 
 * Parameters:
 * Return:
*/
AVL* insert_to_tree(AVL *head, char *key)
{
	if(head == NULL)
	{
		head = (AVL*)malloc(sizeof(AVL));
		if (head == NULL) { printf("\nMEMORY ERROR\n"); return NULL; }
		
		head->key = (char*)malloc(1000*sizeof(char));
		if (head->key == NULL) { printf("\nMEMORY ERROR\n"); return NULL; }
		
		head->str_val = (char*)malloc(1000*sizeof(char));
		if (head->str_val == NULL) { printf("\nMEMORY ERROR\n"); return NULL; }

		strcpy(head->key,key);
		head->height = 0;	
		head->frequency = 1;
		
		head->int_val = 0;
		head->real_val = 0.0;
		head->bool_val = false;
		strcpy(head->str_val, " ");;
			
		head->left = NULL;		
		head->right = NULL;		
	}	
	/*data is less than key, insert left*/
	else if(strcmp(key,head->key) < 0) 
	{
		head->left = insert_to_tree(head->left,key);
		
		/* height is > 1, perform rotate */
		if (height(head->left) - height(head->right) == 2) 
		{
			/* data is less than key, rotate left */
			if(strcmp(key,head->left->key) < 0) 
			{
				head = single_rotate_left(head);
			}
			else
			{
				head = double_rotate_left(head);
			}
			
		}		
	}	
	/*data is greater than key, insert right*/
	else if(strcmp(key,head->key) > 0) 
	{
		head->right = insert_to_tree(head->right,key);
		
		/* height is < -1, perform rotate right */
		if (height(head->right) - height(head->left) == 2) 
		{
			/* data is greater than key, rotate right */
			if(strcmp(key,head->right->key) > 0)
			{
				head = single_rotate_right(head);
			}
			else
			{
				head = double_rotate_right(head);
			}
		}	
	}	
	/* key exists, increment the frequency */
	else
	{
		head->frequency++;
	} 

	head->height = ( find_max( height(head->left), height(head->right) )) + 1;

	
	return head;
}

/* 
 * Name: single_rotate_left()
 * Description: 
 * Parameters:
 * Return:
*/
AVL* single_rotate_left(AVL *head)
{
	AVL *temp = NULL;

	temp = head->left;
	head->left = temp->right;
	temp->right = head;

	head->height = ( find_max( height(head->left), height(head->right) )) + 1;
	temp->height = ( find_max( height(temp->left), height(temp->right) )) + 1;

	return temp;
}

/* 
 * Name: double_rotate_left()
 * Description: 
 * Parameters:
 * Return:
*/
AVL* double_rotate_left(AVL *head)
{
	head->left = single_rotate_right(head->left);
	return single_rotate_left(head);
}

/* 
 * Name: single_rotate_right()
 * Description: 
 * Parameters:
 * Return:
*/
AVL* single_rotate_right(AVL *head)
{
	AVL *temp = NULL;

	temp = head->right;
	head->right = temp->left;
	temp->left = head;

	head->height = ( find_max( height(head->left), height(head->right) )) + 1;
	temp->height = ( find_max( height(temp->left), height(temp->right) )) + 1;

	return temp;	
}

/* 
 * Name: double_rotate_right()
 * Description: 
 * Parameters:
 * Return:
*/
AVL* double_rotate_right(AVL *head)
{
	head->right = single_rotate_left(head->right);
	return single_rotate_right(head);
}

/* 
 * Name: find()
 * Description: 
 * Parameters:
 * Return:
*/
AVL* find(AVL* head, char *key)
{
	if(head == NULL){ return NULL; }
	
	if(strcmp(key, head->key) < 0)
	{
		return find( head->left, key );
	}
	else if(strcmp( key,head->key ) > 0)
	{
		return find( head->right, key );
	}
	else
	{
		return head;
	}
	
	return NULL;
}

/* 
 * Name: height()
 * Description: 
 * Parameters:
 * Return:
*/
int height(AVL *head)
{
	if( head == NULL) { return -1; }
	
	else { return head->height; }
}

/* 
 * Name: find_max()
 * Description: 
 * Parameters:
 * Return:
*/
int find_max(int num1, int num2)
{
	return num1 > num2 ? num1: num2;
}

/* 
 * Name: find_min()
 * Description: 
 * Parameters:
 * Return:
*/
AVL* find_min(AVL* head)
{
    if( head == NULL )
        return NULL;
    else if( head->left == NULL )
        return head;
    else
        return find_min( head->left );
}

/* 
 * Name: print_tree()
 * Description: 
 * Parameters:
 * Return:
*/
void print_tree(AVL* head)
{
	if(head == NULL) { return; }
	
	printf("Key: %s   ", head->key);

	if(head->left != NULL){ printf("(L: %s)", head->left->key); }
	if(head->right != NULL){ printf(" (R: %s)", head->right->key); }
	printf("\n");
	
	print_tree(head->left);
	print_tree(head->right);
}

/* 
 * Name: free_tree()
 * Description: 
 * Parameters:
 * Return:
*/
void free_tree(AVL *head)
{
    if( head != NULL )
    {
        free_tree( head->left );
        free_tree( head->right );
        free( head->key );
        free( head->str_val );
        free( head );
    }
}


