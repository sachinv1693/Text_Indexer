/***************************************************************************************************************************************************
 *Author      :Sachin Vaze
 *Date        :Sat 14 Dec 2019 15:12:05 IST
 *File        :search_word.c
 *Title       :Function to search a given word from the database
 *Description :This function takes a word and Hash array as input and finds it in the database. So, if initial letter of the word is found in the hash table, then search for it in database linked list. If it is found, display its details thereby consequently looking into its link table.
 ****************************************************************************************************************************************************/

#include "text_indexer.h"

void search_word(Hash_albha_t head_index[], const char* word)
{
		//Get the hash key from initial letter of the word
		data_t key = HASH_FUNCTION(tolower(word[0]), 'a');
		if (key >= 0 && key <= 25)
		{
				if (head_index[key].value != '#')
				{
						//Store head address of the database linked list in a pointer
						Database_t* head = head_index[key].head;
						while (head)
						{
								//Compare the given word with irrespective of its case
								if (!strcasecmp(word, head -> word))
								{
										printf("\nThis word is found in %d file(s):\n", head -> file_count);
										//Store address of head of the link table
										Link_table* hd = head -> link_table;
										//Iterate over the list
										while (hd)
										{
												//Print word count and filename in each link table
												printf("In file: %s : %d time(s)\n", hd -> filename, hd -> word_count);
												hd = hd -> link_table;
										}
										//Print a new line and return from the function
										printf("\n");
										return;
								}
								//Move to the next link to look for the word
								head = head -> link;
						}
				}
		}
		//Hash value is '#' means the word is not present in the database
		printf("This word is not found in the database.\n\n");
}

