#include "stack.h"

void append(const char CHARACTER, int* capacity, int* length, char** string)
{
    if (*capacity - 1 <= *length) {
        char* pointer = malloc(sizeof(char) * *capacity * 2);
        if (pointer == NULL) {
            return;
        }
        *capacity *= 2;
        memcpy(pointer, *string, *length + 1);
        free(*string);
        *string = pointer;
    }
    (*string)[*length] = CHARACTER;
    (*length)++;
    (*string)[*length] = '\0';
}

char* reading(void)
{
    int capacity = 10;
    int length = 0;
    char* string = malloc(sizeof(char) * capacity);
    if (string == NULL) {
        return NULL;
    }
    memset(string, 0, capacity);
    int characterInt;
    while ((characterInt = getchar()) != EOF) {
        char character = (char)characterInt;
        append(character, &capacity, &length, &string);
    }
    return string;
}

char matching(char bracket)
{
    switch (bracket) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return '\0';
    }
}

int main(void)
{
    char* string = reading();
    Node* top = NULL;
    if (string == NULL) {
        return 1;
    }

    size_t len = strlen(string);

    for (size_t i = 0; i < len; i++) {
        if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
            top = push(top, string[i]);
        } else if (string[i] == ')' || string[i] == ']' || string[i] == '}') {
            char expected = matching(string[i]);
            if (top == NULL || top->symbol != expected) {
                puts("error balanced");
                freestack(top);
                free(string);
                return 1;
            }
            top = pop(top);
        }
    }

    if (top == NULL) {
        puts("bracket balanced");
        freestack(top);
        free(string);
        return 0;
    }

    puts("unclosed brackets");
    freestack(top);
    free(string);
    return 1;
}