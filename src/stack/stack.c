#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct object_stack
{
    char symbol;
    struct object_stack* last;
} OBJ;

OBJ* push(OBJ* top, char symbol)
{
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->symbol = symbol;
    ptr->last = top;
    return ptr;
}

OBJ* pop(OBJ* top)
{
    if (top == NULL)
        return top;
    OBJ* ptr_last = top->last;
    free(top);
    return ptr_last;
}

void freestack(OBJ* top)
{
    while (top != NULL)
    {
        OBJ* temp = top;
        top = top->last;
        free(temp);
    }
}

void show(OBJ* top)
{
    OBJ* current = top;
    while (current != NULL)
    {
        printf("%c ", current->symbol);
        current = current->last;
    }
}
