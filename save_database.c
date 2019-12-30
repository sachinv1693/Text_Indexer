/***************************************************************************************************************************************************
 *Author      :Sachin Vaze
 *Date        :Sat 14 Dec 2019 18:42:05 IST
 *File        :save_database.c
 *Title       :This function saves the database into an another file
 *Description :It takes a filename & saves the existing database into this file.
 ****************************************************************************************************************************************************/
#include "text_indexer.h"

void save_database(Hash_albha_t head_index[], Existing_Files_t* head)
{
		//A string to store new filename
		char new_file[MAX_FILENAME_SIZE];
		//A file pointer for this file
		FILE* fptr;
		printf("\nEnter the filename in which you want to save the database: ");
		scanf("%s", new_file);
		//Let's verify and open this file
		printf("\nVerifying the file...\n");
		if ((fptr = fopen((const char*)new_file, "w")) != NULL)
		{
				//Check if this is the existing file
				if (is_existing_file(head, new_file))
				{
						//Not allowed to save the database into an existing file
						printf("Cannot store the database in the file: %s\nThis is an existing file in the database\n\n", new_file);
						return;
				}
				printf("Creating this file and saving the database...\n");
				for (data_t i = 0; i < NO_OF_ALPHABETS; i++)
				{
						//We will use fprintf() to write into the file
						if (head_index[i].value != '#')
						{
								fprintf(fptr, "------------------------------------------\n");
								//Write the alphabet into the file
								fprintf(fptr, "[%c]: ", head_index[i].value);
								Database_t* head = head_index[i].head;
								while (head)
								{
										if (head != head_index[i].head)
												fprintf(fptr, "   : ");
										fprintf(fptr, "%s : Appeared in %d file(s)\n", head -> word, head -> file_count);
										Link_table* hd = head -> link_table;
										while (hd)
										{
												fprintf(fptr, "        : %s : %d time(s)\n", hd -> filename, hd -> word_count);
												hd = hd -> link_table;
										}
										head = head -> link;
								}
						}
				}
				fprintf(fptr, "------------------------------------------\n");
				printf("Successfully saved the database in file: %s\n\n", new_file);
		}
		else
				//Error in opening the file
				fprintf(stderr, "ERROR: Unable to open file: %s\n\n", new_file);
		//Close the extra file if opened
		if (fptr)
				fclose(fptr);
}

