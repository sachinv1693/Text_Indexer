/***************************************************************************************************************************************************
*Author      :Sachin Vaze
*Date        :Sat 14 Dec 2019 15:23:05 IST
*File        :insert_at_first.c
*Title       :Function to insert the given value at the head node of the list
*Description :It takes head address of the list, the word to be inserted and its filename. It creates a new node and updates its contents. Also a link table node will be created.
****************************************************************************************************************************************************/

#include "text_indexer.h"

void insert_at_first(Database_t** head, const char* word, const char* filename)
{
		//Create a new node
		Database_t* new = malloc(sizeof(Database_t));
		//Check if node is created or not
		if (new == NULL)
		{
				printf("Error: Unable to allocate dynamic memory!\n\n");
				return;
		}
		//Update the data
		new -> file_count = 1;
		strcpy(new -> word, word);
		insert_LT(&(new -> link_table), &(new -> file_count), filename);
		//Establish a link between first and next node + update head pointer
		new -> link = *head;
		*head = new;
		return;
}

