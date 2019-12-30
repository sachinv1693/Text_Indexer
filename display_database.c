/***************************************************************************************************************************************************
 *Author      :Sachin Vaze
 *Date        :Sat 14 Dec 2019 15:30:05 IST
 *File        :display_database.c
 *Title       :Function to display the database
 *Description :Accepts base address of hash array. It iterates over all the stored values and displays the contents.
 ****************************************************************************************************************************************************/
#include "text_indexer.h"

void display_database(Hash_albha_t head_index[])
{
		//A flag to check if database is empty
		data_t db_empty = 1;
		for (data_t i = 0; i < NO_OF_ALPHABETS; i++)
		{
				if (head_index[i].value != '#')
				{
						db_empty = 0;
						printf("\n----------------------------------------\n");
						//Print the alphabet
						printf("[%c]: ", head_index[i].value);
						Database_t* head = head_index[i].head;
						while (head)
						{
								if (head != head_index[i].head)
										printf("   : ");
								printf("%s : Appeared in %d file(s)\n", head -> word, head -> file_count);
								Link_table* hd = head -> link_table;
								while (hd)
								{
										printf("        : %s : %d time(s)\n", hd -> filename, hd -> word_count);
										hd = hd -> link_table;
								}
								head = head -> link;
						}
				}
		}
		if (db_empty)
				printf("\nDatabase is empty\n\n");
		else
				printf("----------------------------------------\n\n");
}
