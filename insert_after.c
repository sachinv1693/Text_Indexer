/***************************************************************************************************************************************************
*Author      :Sachin Vaze
*Date        :Sat 14 Dec 2019 15:38:05 IST
*File        :insert_after.c
*Title       :A function to insert a node after the given value
*Description :This function takes head address of the list, the word after which we have to insert new word, the new word and the corresponding filename. As the given word is found in the list, the new word is attached to its next node by creating a new node.
****************************************************************************************************************************************************/

#include "text_indexer.h"

void insert_after(Database_t** head, const char* word, const char* new_word, const char* filename)
{
		Database_t* current = *head;
		while (current)
		{
				if(!strcasecmp(current -> word, word))
				{
						//Create a new node
						Database_t* new = malloc(sizeof(Database_t));
						//Check whether memory is allocated
						if (new == NULL)
						{
								printf("Error: Unable to allocate dynamic memory!\n\n");
								exit(SUCCESS);
						}
						//Update new node data
						new -> file_count = 1;
						strcpy(new -> word, new_word);
						insert_LT(&(new -> link_table), &(new -> file_count), filename);
						//Establish link between new node and next node
						new -> link = current -> link;
						//Update current node's link
						current -> link = new;
						return;
				}
				current = current -> link;
		}
		printf("Data not found in the list!\n");
		return;
}

