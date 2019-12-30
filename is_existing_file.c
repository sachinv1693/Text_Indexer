/***************************************************************************************************************************************************
 *Author      :Sachin Vaze
 *Date        :Sat 14 Dec 2019 15:55:05 IST
 *File        :is_existing_file.c
 *Title       :Searches for the filename in existing file list
 *Description :Checks if the given filename exists in the current database
 ****************************************************************************************************************************************************/
#include "text_indexer.h"

Status is_existing_file(Existing_Files_t* head, const char* filename)
{
		while(head)
		{
				if (!strcmp(head -> filename, filename))
						return SUCCESS;
				head = head -> link;
		}
		return FAILURE;
}

