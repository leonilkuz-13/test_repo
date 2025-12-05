#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct NODE {
    int number;
    struct NODE* next;
    struct NODE* last;
} NODE;

typedef struct LIST {
    int len;
    NODE* head;
    NODE* tail;
} LIST;

LIST* initList();
void appendToEmptyList(LIST* list, NODE* ptr);
void appendToBegging(int number, LIST* list);
void append(int number, LIST* list, int index);
void deleteList(LIST* list);
int CheckPallindrome(LIST* list);
#endif