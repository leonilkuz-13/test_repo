#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ObjectStack {
    char symbol;
    struct ObjectStack* last;
} OBJ;

OBJ* push(OBJ* top, char symbol);
OBJ* pop(OBJ* top);
void freestack(OBJ* top);
void show(OBJ* top);
char peek(OBJ* top);

#endif