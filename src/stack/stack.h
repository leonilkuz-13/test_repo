#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ObjectStack {
    char symbol;
    struct ObjectStack* last;
} Node;

Node* push(Node* top, char symbol);
Node* pop(Node* top);
void freestack(Node* top);
void show(Node* top);
char peek(Node* top);

#endif