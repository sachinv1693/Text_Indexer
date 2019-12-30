/***************************************************************************************************************************************************
 *Author         :Sachin Vaze
 *Date           :Sat 14 Dec 2019 15:04:05 IST
 *File           :create_database.c
 *Title          :To create the database
 *Description    :File pointers to all the input files to be documented are provided to this function. Corresponding Hash index is initialized. This function reads the file names and starts indexing.
****************************************************************************************************************************************************/
#include "text_indexer.h"

void create_database(FILE* fptr[], Hash_albha_t head_index[], char* argv[], data_t no_of_files)
{
		/* Definition here */
		//A string to store every word from the files
		char getword[MAX_WORD_SIZE];
		//Iterate from each file
		for (data_t i = 0; i < no_of_files; i++)
		{
				//Let's fetch every character from the file
				char ch;
				//Define a flag to know if the alphabet is found in the file
				//'j' works as the index of 'getword' string
				//key to get the alphabetical index of the word
				data_t alphabet_found = FAILURE, j = 0, key;
#if DEBUG_ON
				//Give gap of extra line for printing words from next file
				printf("\n----Printing words from file: %s-----\n", *(argv + i + 1));
#endif
				//Iterate from the file till EOF
				while ((ch = fgetc(fptr[i])) != EOF)
				{
						//If an alphabet is found
						if (isalpha(ch))
						{
								//Put the character in the getword string and increment its index
								getword[j++] = ch;
								//If the alphabet is found the 1st time or if it is found after a non-alphabet character, assign SUCCESS value to flag
								if (!alphabet_found)
										alphabet_found = SUCCESS;
						}
						//Check if non-alphabet character is found after alphabet character/s
						else if (!isalpha(ch) && alphabet_found)
						{
								//Assign the previously post incremented index as NUL character to terminate the string
								getword[j] = '\0';
#if DEBUG_ON
								//Print every fetched word
								printf("%s\n", getword);
#endif
								//Update Hash index based on 1st character in the word
								//Keep this character as small letter. If it's a capital letter, convert it to small letter using tolower() function
								key = HASH_FUNCTION(tolower(getword[0]), 'a');
								head_index[key].key = key;
								//Update letter in the hash table
								head_index[key].value = tolower(getword[0]);
#if DEBUG_ON
								//Print the first letter and the hash index
								printf("First letter = %c, Hash index = %d\n", head_index[key].value, key);
#endif
								//Update Database Linked list
								insert_sorted_DB(getword, &(head_index[key].head), *(argv + i + 1));
#if DEBUG_ON
								//Print the Database list
		print_list(head_index[key].head);
#endif
								//Assign FAILURE value to flag
								alphabet_found = FAILURE;
								//Assign index j as 0 to begin with next word
								j = 0;
						}
				}
		}
}

