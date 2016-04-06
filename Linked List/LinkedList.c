/*
#NAME: Mike Sadowski
#DATE: January 18th, 2015
#STUDENT ID: 0864810
#ASSIGNEMNT: CIS2750 A1
*/

#include "LinkedList.h"

/* 
 * Name: createNode()
 * Description: Creates/initializes a new node for the linked list
 * Parameters:
 * Return:
*/
LL *createNode(int int_val, float real_val, bool bool_val, char* str_val)
{
	LL *node = (LL*) malloc(sizeof(LL));
	node->str_val = (char*) malloc(sizeof(char) * 999);
	
	node->int_val = int_val;
	node->real_val = real_val;
	node->bool_val = bool_val;
	
	node->next = NULL;
		    
	return node;
}

/* 
 * Name: addToList()
 * Description: Add a new node to the end of the linked list
 * Parameters:
 * Return: return head of the linked list
*/
LL *addToList(LL *head, LL *node)
{
	LL *current = head;
		
    if(head == NULL)
    {
        return NULL;
    }

    while(current->next != NULL)
    {
		current = current->next;
	}
    current->next = node;
  
    return head;
}

/* 
 * Name: searchList()
 * Description: Search the linked list for a specific node
 * Parameters:
 * Return: pointer to the node
*/
LL *searchList(LL *head)
{

}

/* 
 * Name: freeList()
 * Description: Free the entire linked list
 * Parameters:
 * Return: NULL
*/
LL *freeList(LL *head)
{
	LL *current = head;	
	LL *prev = head;
	
    do
    {
		prev = current;			
		free(prev);
		current = current->next;	
	}while(current != NULL);
}

void print_list(LL *head)
{

}
