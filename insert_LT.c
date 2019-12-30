/***************************************************************************************************************************************************
*Author         :Sachin Vaze
*Date           :Sat 14 Dec 2019 15:29:05 IST
*File           :insert_LT.c
*Title          :To create the database list
*Description    :This function accepts the word to be inserted in the Link_table linked list. Filename is also updated in the link table. Also, an integer pointer ensures the trace of file count in the Database linked list. Depending on the occurrence of the word, a word_count in each file is maintained using this Link Table.
 ****************************************************************************************************************************************************/
#include "text_indexer.h"

void insert_LT(Link_table** head, data_t* file_count, const char* filename)
{
		//Create a new node
		Link_table* new = malloc(sizeof(Link_table));
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
				new -> word_count = 1;
				strcpy(new -> filename, filename);
				new -> link_table = NULL;
				*head = new;
				return;
		}
		//Head is not NULL since the code reaches here
		//A temp pointer to iterate over the list. Initialize with head address
		Link_table* temp = *head;
		while (temp -> link_table)
		{
				if (temp != *head)
				{
						//Check if the word is found in the same file. If so, increment word count. Otherwise create a new node
						if (!strcmp(filename, temp -> filename))
						{
								//Increment word count and return
								++(temp -> word_count);
								return;
						}
				}
				temp = temp -> link_table;
		}
	    //Check if the last node contains the same filename. Note that it could be head node as well.	
		if (!strcmp(filename, temp -> filename))
		{
				//Increment word count and return
				++(temp -> word_count);
				return;
		}
		//The word has been found in a new file
		//Increment the file_count in Database list's node
		++(*file_count);
		//Create a new node and update temp node's link
		Link_table* newNode = malloc(sizeof(Link_table));
		//Check if new node is created
		if (newNode == NULL)
		{
				printf("ERROR: Unable to allocate dynamic memory!\n\n");
				exit(SUCCESS);
		}
		//Update new node data
		newNode -> word_count = 1;
		strcpy(newNode -> filename, filename);
		newNode -> link_table = NULL;
		//Establish link between temp node and new node
		temp -> link_table = newNode;
}

