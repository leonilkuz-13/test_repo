#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct List
{
    Node* tail;
    Node* head;
    int len;
} List;

bool indexCorrectness(List* l, int index);
bool indexCorrectnessToInsert(List* l, int index);
List* newList();
int findIndexToInsert(List* l, int digit);
int findIndexToRemove(List* l, int digit);
void insert(int index, List* l, int digit);
int get(List* l, int index);
void listElementRemove(List* l, int index);
void printList(List* l);
void Exit(List* l);

#endif