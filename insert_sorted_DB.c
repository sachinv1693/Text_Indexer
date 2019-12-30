/***************************************************************************************************************************************************
 *Author         :Sachin Vaze
 *Date           :Sat 14 Dec 2019 15:09:05 IST
 *File           :insert_sorted_DB.c
 *Title          :To create the database list
 *Description    :This function accepts the word to be inserted in the Database linked list. Depending on the occurrence of the word in the present linked list, the database of words is generated.
 ****************************************************************************************************************************************************/
#include "text_indexer.h"

void insert_sorted_DB(const char* word, Database_t** head, const char* filename)
{
		//Create a new node
		Database_t* new = malloc(sizeof(Database_t));
		//Check if new node is created
		if (new == NULL)
		{
				printf("ERROR: Unable to allocate dynamic memory!\n\n");
				exit(SUCCESS);
		}
		//Check if head is NULL
		if (*head == NULL)
		{
				//Update new node data
				new -> file_count = 1;
				strcpy(new -> word, word);
				insert_LT(&(new -> link_table), &(new -> file_count), filename);
				new -> link = NULL;
				*head = new;
				return;
		}
		//Compare with the words in the list till the appropriate position for the new word is obtained
		//A temp pointer to iterate over the list, initialize with head address
		Database_t* temp = *head;
		while (temp -> link)
		{
				//If new word is equal to current node's word create the link table
				if (!strcasecmp(word, temp -> word))
				{
						//If the same word is found in another file, increment file_count
						//Update Link Table
						insert_LT(&(temp -> link_table), &(temp -> file_count), filename);
						return;
				}
				//If new word is bigger than current word but smaller than next node's word, insert it after current word
				else if ((strcasecmp(word, (temp -> word)) > 0) && (strcasecmp(word, (temp -> link -> word)) < 0))
				{
						insert_after(head, (temp -> word), word, filename);
						return;
				}
				//Otherwise iterate to next link
				temp = temp -> link;
		}
		//Reaching to NULL address, check again if the word the smallest or the largest or equal
		if (strcasecmp(word, (temp -> word)) < 0)
		{
				//Insert at first since the word is the smallest
				insert_at_first(head, word, filename);
				return;
		}
		else if (strcasecmp(word, (temp -> word)) > 0)
		{
				//Insert after the last node since the word is largest
				insert_after(head, temp -> word, word, filename);
				return;
		}
		else
				//Update Link Table
				insert_LT(&(temp -> link_table), &(temp -> file_count), filename);
		//Implicit return
}

