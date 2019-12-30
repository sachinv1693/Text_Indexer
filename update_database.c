/***************************************************************************************************************************************************
 *Author      :Sachin Vaze
 *Date        :Sat 14 Dec 2019 15:32:05 IST
 *File        :update_database.c
 *Title       :This function updates the database by storing data from another 
 file
 *Description :It takes an extra filename and updates the database with contents              of this file.
 ****************************************************************************************************************************************************/
#include "text_indexer.h"

void update_database(Hash_albha_t head_index[], data_t argc, char* argv[], Existing_Files_t** head)
{
		//A new file pointer array of 1 element associated with this file. We are using array because our verify_and_open() function accepts array of file pointers
        FILE* fptr_new[1] = {NULL};
		//Store new_filename as 1st argument
		printf("\nEnter the filename: ");
		scanf("%s", argv[1]);
		//Let's verify and open this file
		printf("\nVerifying the file & updating...\n");
		if (verify_and_open_input_files(fptr_new, argv, 1))
		{
		//Check if this is the existing file
				if (is_existing_file(*head, argv[1]))
				{
						//Let's delete this file's data from database before updating
						delete_from_database(argv[1], head_index);
#if DEBUG_ON
						printf("\nSuccessfully deleted the data of existing file %s from the database\n", argv[1]);
#endif
				}
				else
						//This is new file. Insert its name into existing database
						insert_into(head, argv[1]);
				//Call create database function so that database gets updated.
				create_database(fptr_new, head_index, argv, 1);
				printf("Successfully verified the file and updated the database!\n\n");
		}
		else
				fprintf(stderr, "ERROR: Please use another valid filename and try again...\n\n");
		//Close the extra file if opened
        if (fptr_new[0])
                fclose(fptr_new[0]);
}

