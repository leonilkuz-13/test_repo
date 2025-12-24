#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int number;
    struct Node *last;
    struct Node *next;
} Node;

typedef struct list
{
    int len;
    Node *tail;
    Node *head;
} List;

List *initList();
void printList(List *list);
void deleteList(List *list);
void appendToEmptyList(List *list, Node *ptr);
void appendToBegging(int number, List *list);
void appendToBehind(int number, List *list);
void append(int number, List *list, int index);
Node *elementSearch(List *list, int number);
void elementRemoveToValue(List *list, int number);
void elementRemoveToIndex(List *list, int index);
