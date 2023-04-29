#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "ERROR_STATE.h"
#include "STD_TYPES.h"

typedef struct {
	u8 bookName[30];
	u8 author[30];
	u32 price;
}bookData_t;

typedef struct node{
	bookData_t Value;
	struct node *Next;
}node_t;


typedef struct List{
	u32 Size;
    node_t *Head;
}list_t;


typedef enum{
	LIST_EMPTY,
	LIST_NEMPTY
}ListState_t;


ErrorState_t Create_List(list_t **RetPtr);
ErrorState_t List_Empty(list_t *List, ListState_t *StatePtr);
ErrorState_t  AddBook(list_t *list, bookData_t *Data);
ErrorState_t DeleteBook(list_t *list, bookData_t *Data, s32 NumOfBook );
ErrorState_t displayList(list_t *list);
ErrorState_t NumberOfListBooks(list_t *list);
#endif