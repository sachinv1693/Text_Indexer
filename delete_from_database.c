/***************************************************************************************************************************************************
 *Author      :Sachin Vaze
 *Date        :Sat 14 Dec 2019 15:42:05 IST
 *File        :delete_from_database.c
 *Title       :This function deletes the data of an existing file from database
 *Description :It takes existing filename and deletes its data from current database
 ****************************************************************************************************************************************************/
#include "text_indexer.h"

void delete_from_database(const char* filename, Hash_albha_t head_index[])
{
		//A flag to check if database is empty
		data_t db_empty = SUCCESS;
		//Iterate through entire hash table
		for (data_t i = 0; i < NO_OF_ALPHABETS; i++)
		{
				if (head_index[i].value != '#')
				{
						//Turn the db_empty flag OFF
						db_empty = FAILURE;
						//Use a double pointer to hold address of hash head in order to reflect further changes made into it
						Database_t** head = &(head_index[i].head);
						//Use another pointer to iterate over database list
						Database_t* head1 = *head;
						//A parent pointer to keep track of parent node address
						Database_t* db_parent = *head;
						//Iterate till the end of the list
						while (head1)
						{
#if DEBUG_ON
								//Print the found word
								printf("%s\n", head1 -> word);
#endif
								//Check if there is file count is 1. If filename is also the same, remove that link table node from the list
								if ((head1 -> file_count == 1) && (!strcmp(head1 -> link_table -> filename, filename)))
								{
#if DEBUG_ON
										printf("count1_same_file\n");
#endif
										//free link_table node
										free(head1 -> link_table);
										//Assign it the NULL address
										head1 -> link_table = NULL;
										//Check if it is the only node
										if (head1 == *head && head1 -> link == NULL)
										{
												//This was the only node. So assign NULL address at hash table's head and also assign '#' value to it
												head_index[i].head = NULL;
												head_index[i].value = '#';
										}
										//Next word exists
										else
										{
												//Check if this is the 1st node
												if (head1 == *head)
														//Assign next node's address to beginning of the list
														*head = head1 -> link;
												else
														//Assign parent node's next link as next link of this node
														db_parent -> link = head1 -> link;
										}
										//Free this node from database list
                                                                                Database_t* to_free = head1;
										free(to_free);
								}
								else//Filecount is more than 1
								{
										//Store link table head address
										Link_table* hd = head1 -> link_table;
										//Compare the filename at very 1st node
										if (!strcmp(hd -> filename, filename))
										{
#if DEBUG_ON
												printf("count_more_1st_file\n");
#endif
												//Node to be deleted
												Link_table* del = hd;
												//Establish link between head node and the next link table address
												head1 -> link_table = hd -> link_table;
												//Decrement filecount
												--(head1 -> file_count);
												//Free the node
												free(del);
												goto SKIP_LOOP;
										}
										//Iterate over the link table to find the filename
										while (hd && (hd -> link_table))
										{
												//Check if any of the remaining link_table nodes has the same filename
												if (!strcmp((hd -> link_table -> filename), filename))
												{
#if DEBUG_ON
														printf("count_more_next_file\n");
#endif
														//Node to be deleted
														Link_table* temp = hd -> link_table;
														//Establish link to next's next link table address
														hd -> link_table = hd -> link_table -> link_table;
														//Decrement filecount
														--(head1 -> file_count);
														//Free the node
														free(temp);
														break;
												}
												//Move the pointer to next link table
												hd = hd -> link_table;
										}
								db_parent = head1;
								}
SKIP_LOOP:
								//Move the pointer to next link
								head1 = head1 -> link;
						}
				}
		}
		//Check if db_empty flag is ON
		if (db_empty)
				printf("\nDatabase is empty\n\n");
		//Implicit return
}

