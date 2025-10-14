#ifndef STACK_H
#define STACK_H

typedef struct object_stack
{
    char symbol;
    struct object_stack* last;
} OBJ;

OBJ* push(OBJ* top, char symbol);
OBJ* pop(OBJ* top);
void freestack(OBJ* top);
void show(OBJ* top);

#endif