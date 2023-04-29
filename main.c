/*
 ============================================================================
 Name        : Nti Project.c
 Author      : esmail mahmoud esmail
 Description : library management system by using SinglyLinked list 
 Date        : 27/08/2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

s32 main(void)
{   
    s32 User_Input;
	list_t *List1=NULL;
    Create_List(&List1);
	bookData_t Book_Added={"anyname.........","anyauthor..........",100};
	bookData_t *AddedBOOK =&Book_Added;
	bookData_t Book_Deleted={"anyReturnedname.........","anyReturnedauthor..........",100}; //we can use it if we wanna print the deleted book
	bookData_t *DeletedBOOK =&Book_Deleted;
    
    for(;;)
    {
		/**********************************************************************************/
		printf("----------------------------------------------------\n");
		printf("1. To view all books                     Enter'1'\n");
		printf("2. To add new book                       Enter'2'\n");
		printf("3. To delete a book                      Enter'3'\n");
		printf("4. To view number of avaiable books      Enter'4'\n");
		printf("5. Quit the system                       Enter'5'\n");
		printf("----------------------------------------------------\n");
		/***********************************************************************************/
		/* Get input from user  */
		printf("your choice is ------>");
		scanf("%d",&User_Input);
		printf("\n");
		/********************************************************************************/
		for(;;)
		{
		
			if(User_Input == 5)
			{
				printf("Quit The System Goodbye :) \n\n");
				exit(0);
			}
			/***********************************************************************************/

			/***********************************************************************************/
			else if(User_Input == 1)
			{

				
					displayList(List1);
				    fflush(stdin);
				break;
			}
			/***********************************************************************************/
			
			/**********************************************************************************/
			else if(User_Input == 2)
			{
				printf("enter the name of book: ");
				fflush(stdin);
				gets(AddedBOOK->bookName);
				fflush(stdin);
				printf("enter the author of book: ");
				gets(AddedBOOK->author);
				printf("enter the price of book: ");
				scanf("%d",&AddedBOOK->price);
				fflush(stdin);
				
				AddBook(List1,AddedBOOK );
			
				break;
			}
			/***********************************************************************************/
			
			/**********************************************************************************/
			else if(User_Input == 3)
			{
				s32 NumOfBook =0;
				printf("please enter the number of book from (1 to %d) :",List1->Size);
				scanf("%d",&NumOfBook);
				DeleteBook(List1,DeletedBOOK,NumOfBook);
				break;
			}
			/***********************************************************************************/
			
			/**********************************************************************************/
			else if(User_Input == 4)
			{
				NumberOfListBooks(List1);
				break;
			}
			/***********************************************************************************/
			
			/**********************************************************************************/
			else
			{
				printf("Error please enter valid input  \n\n");
				break;
			}
		}
		
	} /* outer for loop */

    return 0;
}