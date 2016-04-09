/*
#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:
*/

#include "HashTable.h"

/* 
 * Name: create_hash_table()
 * Description: Creates and initializes a new node for the linked list
 * Parameters:
 * Return:
*/
HT *create_hash_table(int size)
{
    HT *table = NULL;
    int i = 0;
    
    if ( size < 1 ) { return NULL; } 

    if ((table = malloc(sizeof(table))) == NULL ) 
    {
        return NULL;
    }

    if ((table->table = malloc(sizeof(LL *) * size)) == NULL) 
    {
        return NULL;
    }

    for(i = 0; i < size; i++) 
    {
		table->table[i] = NULL;
	}

    table->size = size;

    return table;
}

unsigned int hash(HT *hashtable, char *str_val)
{
    unsigned int hashval = 0;
    
    /* for each character, we multiply the old hash by 31 and add the current
     * character.  Remember that shifting a number left is equivalent to 
     * multiplying it by 2 raised to the number of places shifted.  So we 
     * are in effect multiplying hashval by 32 and then subtracting hashval.  
     * Why do we do this?  Because shifting and subtraction are much more 
     * efficient operations than multiplication.
     */
    for(; *str_val != '\0'; str_val++) hashval = *str_val + (hashval << 5) - hashval;

    /* we then return the hash value mod the hashtable size so that it will
     * fit into the necessary range
     */
    return hashval % hashtable->size;
}

int add_element(HT *table, char *str_val)
{
    LL *new_list = NULL;
    LL *current_list = NULL;
    unsigned int hashval = hash(table, str_val);

    /* Attempt to allocate memory for list */
    if ((new_list = malloc(sizeof(LL))) == NULL) return 1;

    /* Does item already exist? */
    current_list = lookup_element(table, str_val);
    
    /* item already exists, don't insert it again. */
    if (current_list != NULL) return 2;
    
    /* Insert into list */
    new_list->str_val = strdup(str_val);
    new_list->next = table->table[hashval];
    table->table[hashval] = new_list;

    return 0;
}

LL *lookup_element(HT *table, char *str_val)
{
    LL *list = NULL;
    unsigned int hashval = hash(table, str_val);

    for(list = table->table[hashval]; list != NULL; list = list->next) 
    {
        if (strcmp(str_val, list->str_val) == 0) return list;
    }
    
    return NULL;
}

void free_table(HT *table)
{
    int i = 0;
    LL *list = NULL;
    LL *temp = NULL;
    
    if (table == NULL) { return; }

    /* Free the memory for every item in the table, including the 
     * strings themselves.
     */
    for(i = 0; i < table->size; i++) 
    {
        list = table->table[i];
        while(list!=NULL) 
        {
            temp = list;
            list = list->next;
            free(temp->str_val);
            free(temp);
        }
    }

    /* Free the table itself */
    free(table->table);
    free(table);
}


