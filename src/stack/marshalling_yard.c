#include <stdio.h>
#include <stdlib.h>
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

char* reading(int* capasity, int* lenght)
{
    char* str = malloc(sizeof(char) * *capasity);
    if (str == NULL)
        return NULL;
    char ch;
    while ((ch = getchar()) != EOF)
        append(&ch, capasity, lenght, &str);
    return str;
}

int operand(char symbol)
{
    if (symbol == '+' || symbol == '*' || symbol == '-' || symbol == '/')
        return 1;
    return 0;
}

int digit(char symbol)
{
    if (operand(symbol) == 0 && symbol != ')' && symbol != '(')
        return 1;
    return 0;
}

int operand_comparison(char symbol)
{
    switch (symbol)
    {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int main(void)
{
    int capasity = 2, lenght = 0;
    char* str = reading(&capasity, &lenght);
    OBJ* top = NULL;
    size_t len = strlen(str);
    char output[len * 2 + 1];
    size_t j = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (digit(str[i]) == 1)
        {
            output[j++] = str[i];
            output[j++] = ' ';
        }
        else if (operand(str[i]) == 1)
        {
            while (top != NULL && peek(top) != '(' &&
                   operand_comparison(peek(top)) >= operand_comparison(str[i]))
            {
                output[j++] = peek(top);
                output[j++] = ' ';
                top = pop(top);
            }
            top = push(top, str[i]);
        }
        else if (str[i] == '(')
        {
            top = push(top, str[i]);
        }
        else if (str[i] == ')')
        {
            while (top != NULL && peek(top) != '(')
            {
                output[j++] = peek(top);
                output[j++] = ' ';
                top = pop(top);
            }
            top = pop(top);
        }
    }
    while (top != NULL)
    {
        output[j++] = peek(top);
        output[j++] = ' ';
        top = pop(top);
    }
    free(str);
    for (size_t i = 0; i < strlen(output); i++)
        printf("%c", output[i]);
    return 0;
}