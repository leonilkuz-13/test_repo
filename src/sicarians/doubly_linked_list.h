#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
    int number;
    struct Node *last;
    struct Node *next;
} NODE;

typedef struct list
{
    int len;
    NODE *tail;
    NODE *head;
} LIST;

LIST *initList();
void printList(LIST *list);
void deleteList(LIST *list);
void appendToEmptyList(LIST *list, NODE *ptr);
void appendToBegging(int number, LIST *list);
void appendToBehind(int number, LIST *list);
void append(int number, LIST *list, int index);
NODE *elementSearch(LIST *list, int number);
void elementRemoveToValue(LIST *list, int number);
void elementRemoveToIndex(LIST *list, int index);

#endif