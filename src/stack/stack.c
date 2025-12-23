#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Node* push(Node* top, char symbol)
{
    Node* pointer = malloc(sizeof(Node));
    if (pointer == NULL) {
        return top;
    }
    pointer->symbol = symbol;
    pointer->last = top;
    return pointer;
}

Node* pop(Node* top)
{
    if (top == NULL) {
        return top;
    }
    Node* pointer = top->last;
    free(top);
    return pointer;
}

void freestack(Node* top)
{
    while (top != NULL) {
        Node* temporary = top;
        top = top->last;
        free(temporary);
    }
}

void show(Node* top)
{
    Node* current = top;
    while (current != NULL) {
        printf("%c ", current->symbol);
        current = current->last;
    }
}

char peek(Node* top)
{
    if (top == NULL) {
        return 0;
    }
    return top->symbol;
}