#include "stack.h"

void append(const char character, int* capacity, int* length, char** string)
{
    if (*capacity - 1 <= *length) {
        char* pointer = malloc(sizeof(char) * *capacity * 2);
        if (pointer == NULL) {
            return;
        }
        *capacity *= 2;
        strcpy(pointer, *string);
        free(*string);
        *string = pointer;
    }
    (*string)[*length] = character;
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
    int character_int;
    while ((character_int = getchar()) != EOF) {
        char character = (char)character_int;
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

    size_t length = strlen(string);

    for (size_t index = 0; index < length; index++) {
        if (string[index] == '(' || string[index] == '[' || string[index] == '{') {
            top = push(top, string[index]);
        } else if (string[index] == ')' || string[index] == ']' || string[index] == '}') {
            char expected = matching(string[index]);
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
    } else {
        puts("unclosed brackets");
        freestack(top);
        free(string);
        return 1;
    }
}