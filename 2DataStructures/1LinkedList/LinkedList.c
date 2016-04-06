/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include "LinkedList.h"

/* 
 * Name: create_node()
 * Description: Creates and initializes a new node for the linked list
 * Parameters:
 * Return:
*/
LL *create_node(int int_val, float real_val, bool bool_val, char* str_val)
{
	LL *node = (LL*) malloc(sizeof(LL));
	node->str_val = (char*) malloc(sizeof(char) * 999);
	
	node->int_val = int_val;
	node->real_val = real_val;
	node->bool_val = bool_val;
	strcpy(node->str_val, str_val); 
	node->next = NULL;
		    
	return node;
}

/* 
 * Name: add_to_front()
 * Description: Add a new node to the end of the linked list
 * Parameters:
 * Return: return head of the linked list
*/
LL *add_to_front(LL *head, int int_val, float real_val, bool bool_val, char* str_val)
{
	LL *node = NULL;
		
    if(head == NULL) { return NULL; }

	node = create_node( int_val, real_val, bool_val, str_val );
	
	node->next = head;
	head = node;

	return head;
}

/* 
 * Name: add_to_back()
 * Description: Add a new node to the end of the linked list
 * Parameters:
 * Return: none
*/
void add_to_back(LL *head, int int_val, float real_val, bool bool_val, char* str_val)
{
	LL *current = head;
	LL *node = NULL;
		
    if(head == NULL) { return; }

	node = create_node( int_val, real_val, bool_val, str_val );

    while(current->next != NULL) { current = current->next; }	
    current->next = node;
    
    return;
}

/* 
 * Name: search_list()
 * Description: Search the linked list for a specific node
 * Parameters:
 * Return: pointer to the node
*/
LL *search_list(LL *head, char *str_val)
{
    LL *temp = head;

    while(temp != NULL)
    {
        if( strcmp(str_val, temp->str_val) == 0 )
        {
            return temp;
        }
        
        temp = temp->next;
    }
    
    return NULL;
}

/* 
 * Name: free_list()
 * Description: Free the entire linked list
 * Parameters:
 * Return: NULL
*/
void free_list(LL *head)
{
	LL *current = head;	
	LL *prev = head;
	
	if(head == NULL) { return; }
	
    do
    {
		prev = current;
		
		free(prev->str_val);		
		free(prev);
		
		current = current->next;	
	}while(current != NULL);
}

/* 
 * Name: print_list()
 * Description: Print the entire linked list
 * Parameters:
 * Return: NULL
*/
void print_list(LL *head)
{
	LL *current = head;
	
	if(head == NULL) { return; }
	
	do
    {
		printf("\nNode: %s", current->str_val);
		printf("\n  int: %d", current->int_val);
		printf("\n  float: %f", current->real_val);
		printf("\n  bool: %s\n", current->bool_val ? "true" : "false");
		
		current = current->next;
	} while(current != NULL);
	
	printf("\n");
}
