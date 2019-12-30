/***************************************************************************************************************************************************
 *Author	  :Sachin Vaze
 *Date		  :Sat 14 Dec 2019 15:00:05 IST
 *File		  :main.c
 *Title		  :Driver function
 *Description :This function acts like the driver function for the project inverted search
 ****************************************************************************************************************************************************/
#include "text_indexer.h"

int main(int argc, char* argv[])
{
		/* Define the main function here */
		//If no filenames are provided, display an error message and return
		if (argc == 1)
		{
				printf("ERROR: No filename provided from command line. Please pass one or more filename/s to perform text indexing operations.\n\n");
				exit(SUCCESS);
		}
		//Trace the no. of input files provided from command line
		data_t no_of_input_files = argc - 1;
		//Creating an array of file pointers
		FILE* file_pointer[no_of_input_files];
		//Validate filenames
		printf("\nVerifying & opening the input files...\n");
		if (!verify_and_open_input_files(file_pointer, argv, no_of_input_files))
		{
				printf("\nPlease try again...\n\n");
				exit(SUCCESS);
		}
		printf("Input files verified and opened successfully!\n");
		//Create database of existing filenames
		Existing_Files_t* head = NULL;
		for (data_t i = 1; i < argc; i++)
		{
				insert_into(&head, argv[i]);
		}
		//Let's create a Hash table which maintains alphabetical order
		Hash_albha_t head_index[NO_OF_ALPHABETS];
		//Initializing Hash table with indices 0 to 25
		for (data_t i = 0; i < NO_OF_ALPHABETS; i++)
		{
				head_index[i].key = i;//Key i.e. index
				head_index[i].value = '#';//Initialize all values to '#'
				head_index[i].head = NULL;//Initialize each node's link to NULL
		}
		//User's choice to continue the operations
		char choice;
		//User would select an option from given menu & a flag to check if Database is already created
		data_t opt, db_created = 0;
		//Word to be searched
		char word[MAX_WORD_SIZE];
		do
		{
				printf("\n-----------Operations choice------------\
								\n1. Create database\
								\n2. Display database\
								\n3. Search a word\
								\n4. Update database\
								\n5. Save database\
								\nPlease select an option: ");
				scanf("%d", &opt);
				switch (opt)
				{
						case 1://Create database
								if (db_created)
										printf("\nDatabase has been already created!!\n\n");
								else
								{
										create_database(file_pointer, head_index, argv, no_of_input_files);
										printf("\nSuccessfully created the database!\n\n");
										db_created = 1;
								}
								break;
						case 2://Display the database
								if (db_created)
										display_database(head_index);
								else
										printf("\nDatabase has not been created yet! Please choose option 1 to create a database and try again!\n\n");
								break;
						case 3://Search a word
								if (db_created)
								{
										printf("\nEnter the word you want to search: ");
										scanf("%s", word);
										search_word(head_index, word);
								}
								else
										printf("\nDatabase has not been created yet! Please choose option 1 to create a database and try again!\n\n");
								break;
						case 4://Update database
								if (db_created)
										update_database(head_index, argc, argv, &head);
								else
										printf("\nDatabase has not been created yet! Please choose option 1 to create a database and try again!\n\n");
								break;
						case 5://Save database
								if (db_created)
										save_database(head_index, head);
								else
										printf("\nDatabase has not been created yet! Please choose option 1 to create a database and try again!\n\n");
								break;
						default://Invalid option
								printf("ERROR: Invalid option selected!\n\n");
				}
				printf("Do you want to perform more operations? (y-Y/n-N): ");
				scanf("\n%c", &choice);
		} while (choice == 'y' || choice == 'Y');
		//Close all the files and exit from the program
		printf("\nClosing all the files...\n");
		for (data_t i = 0; i < no_of_input_files; i++)
		{
				fclose(file_pointer[i]);
		}
		//Close the extra file if opened
		//if (fptr_new[0])
		//		fclose(fptr_new[0]);
		printf("All the files successfully closed!\nThank you! See you again\n\n");
		return 0;
}

