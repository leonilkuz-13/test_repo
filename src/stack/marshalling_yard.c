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

char* reading(int* capacity, int* length)
{
    char* string = malloc(sizeof(char) * *capacity);
    if (string == NULL) {
        return NULL;
    }
    memset(string, 0, *capacity);
    int character_int;
    while ((character_int = getchar()) != EOF) {
        char character = (char)character_int;
        append(character, capacity, length, &string);
    }
    return string;
}

int operand(char symbol)
{
    if (symbol == '+' || symbol == '*' || symbol == '-' || symbol == '/') {
        return 1;
    }
    return 0;
}

int digit(char symbol)
{
    if (operand(symbol) == 0 && symbol != ')' && symbol != '(') {
        return 1;
    }
    return 0;
}

int operand_comparison(char symbol)
{
    switch (symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int main(void)
{
    int capacity = 2;
    int length = 0;
    char* string = reading(&capacity, &length);
    if (string == NULL) {
        return 1;
    }

    Node* top = NULL;
    size_t str_length = strlen(string);
    char output[str_length * 2 + 1];
    memset(output, 0, sizeof(output));
    size_t output_index = 0;

    for (size_t index = 0; index < str_length; index++) {
        if (digit(string[index]) == 1) {
            output[output_index++] = string[index];
            output[output_index++] = ' ';
        } else if (operand(string[index]) == 1) {
            while (top != NULL && peek(top) != '('
                   && operand_comparison(peek(top)) >= operand_comparison(string[index])) {
                output[output_index++] = peek(top);
                output[output_index++] = ' ';
                top = pop(top);
            }
            top = push(top, string[index]);
        } else if (string[index] == '(') {
            top = push(top, string[index]);
        } else if (string[index] == ')') {
            while (top != NULL && peek(top) != '(') {
                output[output_index++] = peek(top);
                output[output_index++] = ' ';
                top = pop(top);
            }
            top = pop(top);
        }
    }

    while (top != NULL) {
        output[output_index++] = peek(top);
        output[output_index++] = ' ';
        top = pop(top);
    }

    free(string);

    for (size_t index = 0; index < strlen(output); index++) {
        printf("%c", output[index]);
    }
    return 0;
}