#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

void append(char* ch, int* capasity, int* lenght, char** str)
{
    if (*capasity - 1 <= *lenght)
    {
        char* ptr = malloc(sizeof(char) * *capasity * 2);
        if (ptr == NULL)
            return;

        *capasity *= 2;
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
    int capasity = 10;
    int lenght = 0;
    char* str = malloc(sizeof(char) * capasity);
    if (str == NULL)
        return NULL;
    char ch;
    while ((ch = getchar()) != EOF)
        append(&ch, &capasity, &lenght, &str);
    return str;
}
int main(void)
{
    char* str = reading();
    OBJ* top = NULL;
    int len = strlen(str);

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
        freestack(top);
        return 0;
    }
    else
    {
        puts("unclosed brackets");
        freestack(top);
        return 1;
    }
}