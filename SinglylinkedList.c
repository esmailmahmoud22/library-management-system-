#include "SinglylinkedList.h"


ErrorState_t Create_List(list_t **RetPtr)
{
	ErrorState_t FuncRetState = RET_OK;
	if(NULL != RetPtr)
	{
		list_t *ListPtr = (list_t *)malloc(sizeof(list_t));
		if(NULL != ListPtr)
		{
			ListPtr->Head = NULL;
			ListPtr->Size = 0;
			*RetPtr = ListPtr;
		}
		else{
			printf("Error: malloc failed to create the list :( .....\n");
			FuncRetState = RET_NULL_PTR;
		}
	}
	else{
		printf("Error: A NULL address was passed to the creat_list function ...\n");
		FuncRetState = RET_NULL_PTR;
	}
	return FuncRetState;
}


ErrorState_t List_Empty(list_t *List, ListState_t *StatePtr)
{
	ErrorState_t FuncRetState = RET_OK;
	if(NULL != List)
	{
		if(List->Size == 0)
		{
			*StatePtr = LIST_EMPTY;
		}
		else{
			*StatePtr = LIST_NEMPTY;
		}
	}
	else{
		printf("List pointer in List_Empty function  has NULL Address....\n");
		FuncRetState = RET_NULL_PTR;
	}
	return FuncRetState;
}


ErrorState_t AddBook(list_t *list, bookData_t *Data)
{
	ErrorState_t FuncRetState = RET_OK;
	node_t *Temp = NULL;
	if(list != NULL)
	{
		node_t *NodePtr = (node_t *)malloc(sizeof(node_t));
		if(NodePtr == NULL)
		{
			printf("Error: malloc failed to creat the node :( .....\n");
			FuncRetState = RET_NULL_PTR;
		}
		else{
			NodePtr ->Value= *Data;
			NodePtr->Next = NULL;
			printf("the book has been added successfull to the back of the list.\n");
			Temp = list->Head;
			if(Temp == NULL)
			{
				list->Head = NodePtr;
			}
			else{
				while(Temp->Next != NULL)
				{
					Temp = Temp->Next;
				}
				Temp->Next = NodePtr;
			}
			list->Size++;
		}
	}
	else{
		printf("Error: in function AddToBack list pointer has a NULL Address ....\n");
		FuncRetState = RET_NULL_PTR;
	}
	return FuncRetState;
}




ErrorState_t displayList(list_t *list)
{
	ErrorState_t FuncRetState = RET_OK;
	ListState_t ListState = LIST_NEMPTY;
	if(ListState == LIST_EMPTY)
	{
		printf("Sorry: the list is empty ...\n");
		FuncRetState = RET_NOK;
    }
    else
    {
        
        s32 i;
		node_t *Temp=NULL;
		Temp = list-> Head;
		if(list->Size==0)
        {
			printf("----the list is empty----\n");
			
        }
		else
		{   
	        printf("------------------Available books------------------\n");
			 for (i=0;i<list->Size;i++)
			{
				printf("BOOK NO.%d...\n",(i+1));
				printf(" name   : %s\n",  Temp->Value.bookName);// prints the data of current node
				printf(" author : %s\n",Temp->Value.author);
				printf(" price  : %d\n", Temp->Value.price);		
				Temp =Temp->Next;     // advances the position of current node
				printf("---------------------------------------\n");
			}		
		}
       
    }
	return FuncRetState;
} 

 ErrorState_t NumberOfListBooks(list_t *list)
{
   ErrorState_t FuncRetState = RET_OK;
   s32 NumberOfBooks = 0;
   node_t *Temp=NULL;
   Temp = list->Head;
   // check if the linked list is empty
   if(list != NULL)
	{
		if(Temp==NULL)
        {
        printf("number of avaiable books: %d\n", NumberOfBooks);
        }
	    else
	    {
			// list is not empty contains one node at least
		   NumberOfBooks = 1;
		   while(Temp->Next != NULL)
		   {
			Temp = Temp->Next;
			NumberOfBooks++;
		   }
		   printf("number of avaiable books: %d \n", NumberOfBooks);
	    }
	}
	else{
		printf("Error: in function AddToBack list pointer has a NULL Address ....\n");
		FuncRetState = RET_NULL_PTR;
	}
	return FuncRetState;
   
   
}

ErrorState_t DeleteBook(list_t *list, bookData_t *Data, s32 NumOfBook )
{
	ErrorState_t FuncRetState = RET_OK;
	ListState_t ListState = LIST_NEMPTY;
	node_t *Temp = NULL;
	node_t *Temp1 = NULL;
	s32 i;
	if((list != NULL) && (Data != NULL))
	{
		List_Empty(list, &ListState);
		if(ListState == LIST_EMPTY)
		{
			printf("Sorry: the list is empty ...\n");
			FuncRetState = RET_NOK;
		}
		else
		{
			Temp = list->Head;
			Temp1=list->Head;
			for(i=1;i<NumOfBook-1;i++)  /*we delete from any position here*/
			{
				Temp1 = Temp1->Next;
			}
			for(i=1;i<NumOfBook;i++)
			{
				Temp = Temp->Next;
			}
			*Data = Temp->Value;
			if(Temp!=Temp1)
			{
				Temp1->Next=Temp->Next;
				free(Temp);
			}
			else if((NumOfBook==1)&&(NumOfBook<list->Size))
			{
				*Data = list->Head->Value;
			    list->Head =Temp->Next;
			    free(Temp);
				
			}
			else
			{
				list->Head=NULL;
			}
			list->Size--;
			printf("the book has been Deleted successfully\n");
		}
	}
	else{
		FuncRetState = RET_NULL_PTR;
		printf("Error: in function RemoveFromBack one of the parameters or both is a NULL Ptr...\n ");
	}
	return FuncRetState;
}



