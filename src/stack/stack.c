#include "stack.h"

Node* push(Node* top, char symbol)
{
    Node* ptr = malloc(sizeof(Node));
    ptr->symbol = symbol;
    ptr->last = top;
    return ptr;
}

Node* pop(Node* top)
{
    if (top == NULL)
        return top;
    Node* ptr = top->last;
    free(top);
    return ptr;
}

void freestack(Node* top)
{
    while (top != NULL) {
        Node* temp = top;
        top = top->last;
        free(temp);
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
    if (top == NULL)
        return 0;
    return top->symbol;
}
