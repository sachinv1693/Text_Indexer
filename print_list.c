/***************************************************************************************************************************************************
*Author      :Sachin Vaze
*Date        :Sat 14 Dec 2019 15:14:05 IST
*File        :print_list.c
*Title       :A function to print database. This is used only for debugging
*Description :This function gets called only when DEBUG_ON macro is set to 1. It is used for printing every head_index and its corresponding linked lists.
****************************************************************************************************************************************************/

#include "text_indexer.h"

void print_list(Database_t* head)
{
		//Check if head is empty
		if (head == NULL)
		{
				printf("\nList is empty\n\n");
				return;
		}
		printf("\n---------Printing Database---------\n");
		//Iterate through the linked list
		while (head)
		{
				//Print filecount and the stored word
				printf("file_count = %d : word = %s\n", head -> file_count, head -> word);
				//Print Link Table
				Link_table* hd = head -> link_table;
				//Check if link_table is empty
				if (hd == NULL)
				{
						printf("\nList is empty\n\n");
						return;
				}
				while (hd)
				{
						//Print word count and the stored filename
						printf("word_count = %d : filename = %s\n", hd -> word_count, hd -> filename);
						hd = hd -> link_table;
				}
				printf("\n");
				head = head -> link;
		}
		printf("\n");
}

