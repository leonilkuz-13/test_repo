#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* tail;
    Node* head;
    int len;
} List;

List* newList();
void insert(List* list, int number);
void listElementRemove(List* list, int number);
void printList(List* list);
void deleteList(List* list);