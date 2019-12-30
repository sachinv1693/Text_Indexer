/***************************************************************************************************************************************************
*Author      :Sachin Vaze
*Date        :Sat 14 Dec 2019 15:23:05 IST
*File        :insert_into.c
*Title       :Function to insert the given filename into a link list
*Description :It takes head address of the list and the filename to be inserted into the link list. This link list keeps track of all the existing files of the database
****************************************************************************************************************************************************/

#include "text_indexer.h"

void insert_into(Existing_Files_t** head, const char* filename)
{
		//Create a new node
		Existing_Files_t* new = malloc(sizeof(Existing_Files_t));
		//Check if node is created or not
		if (new == NULL)
		{
				printf("Error: Unable to allocate dynamic memory!\n\n");
				return;
		}
		//Update the data
		strcpy(new -> filename, filename);
		//Establish a link between first and next node + update head pointer
		new -> link = *head;
		*head = new;
		return;
}

