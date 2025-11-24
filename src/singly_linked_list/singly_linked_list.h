#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* tail;
    Node* head;
    int len;
} List;

bool checkIndex(List* list, int index);
List* newList();
int findIndexToInsert(List* list, int number);
int findIndexToRemove(List* list, int number);
void insert(int index, List* list, int number);
int get(List* list, int index);
void listElementRemove(List* list, int index);
void printList(List* list);
void deleteList(List* list);

#endif