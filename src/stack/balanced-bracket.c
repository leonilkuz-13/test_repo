#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

void append(char* ch, int* campsity, int* lenght, char** str)
{
    if (*campsity - 1 <= *lenght)
    {
        char* ptr = malloc(sizeof(char) * *campsity * 2);
        if (ptr == NULL)
            return;

        *campsity *= 2;
        strcpy(ptr, *str);
        free(*str);
        *str = ptr;
    }
    (*str)[*lenght] = *ch;
    (*lenght)++;
    (*str)[*lenght] = '\0';
}

char* reading(void)
{
    int campsity = 10;
    int lenght = 0;
    char* str = malloc(sizeof(char) * campsity);
    if (str == NULL)
        return NULL;
    char ch;
    while ((ch = getchar()) != EOF)
        append(&ch, &campsity, &lenght, &str);
    return str;
}
int main(void)
{
    char* str = reading();
    OBJ* top = NULL;
    size_t len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            top = push(top, str[i]);
        }
        else if (str[i] == ')')
        {
            if (top == NULL || top->symbol != '(')
            {
                puts("error balanced");
                freestack(top);
                return 1;
            }
            top = pop(top);
        }
        else if (str[i] == ']')
        {
            if (top == NULL || top->symbol != '[')
            {
                puts("error balanced");
                freestack(top);
                return 1;
            }
            top = pop(top);
        }
        else if (str[i] == '}')
        {
            if (top == NULL || top->symbol != '{')
            {
                puts("error balanced");
                freestack(top);
                return 1;
            }
            top = pop(top);
        }
    }

    if (top == NULL)
    {
        puts("bracket balanced");
    }
    else
    {
        puts("unclosed brackets");
        freestack(top);
        return 1;
    }
}