/***************************************************************************************************************************************************
 *Author      :Sachin Vaze
 *Date        :Sat 14 Dec 2019 15:35:05 IST
 *File        :verify_and_open_input_files.c
 *Title       :Validate filename provided by user from command line
 *Description :Checks if the given filename exists in the current working directory.
 ****************************************************************************************************************************************************/
#include "text_indexer.h"

Status verify_and_open_input_files(FILE* fptr[], char* argv[], data_t no_of_files)
{
		//An error flag to know if there is any error
		data_t error_flag = 0;
		char filename[MAX_FILENAME_SIZE];
		for (data_t i = 0; i < no_of_files; i++)
		{
			   //Extract only filename from given path if any
			   strcpy(*(argv + i + 1), basename(*(argv + i + 1)));
if ((fptr[i] = fopen((const char*)*(argv + i + 1), "r")) == NULL)
		{
				perror("fopen");
				fprintf(stderr, "ERROR: Unable to open file: %s. This file may not be present in the current project directory.\n", *(argv + i + 1));
				error_flag = 1;
		}
		}
		return (error_flag) ? FAILURE: SUCCESS;
}

