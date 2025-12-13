#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct NODE {
    int value;
    struct NODE* next;
} Node;

typedef struct LIST {
    int len;
    Node* head;
    Node* tail;
} List;

List* initList();
void deleteList(List* list);
bool findNode(List* list, int value);
void append(List* list, int number);
void swapNodes(Node** ptr1, Node** ptr2);
int distributionNodeArray(Node* array[], int low, int high);
void quickSortNodeArray(Node* array[], int low, int high);
void sortList(List* list);
void removeElementList(List* list, Node* node);
void printList(List* list);

#endif