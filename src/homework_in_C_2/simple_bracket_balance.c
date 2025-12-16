#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int charIndex = 0;
    char inputString[101];

    for (int i = 0; i < sizeof(inputString); i++) {
        inputString[i] = '\0';
    }

    int scanResult;
    bool inputError = false;
    while ((scanResult = getchar()) != EOF && scanResult != '\n' && charIndex < 100) {
        char currentChar = (char)scanResult;

        if (currentChar != '{' && currentChar != '}' && currentChar != '[' && currentChar != ']'
            && currentChar != '>' && currentChar != '<') {
            inputString[charIndex++] = currentChar;
        } else {
            inputError = true;
            break;
        }
    }

    if (inputError) {
        puts("Incorrect input");
        return 0;
    }

    size_t stringLength = strlen(inputString);

    int bracketCounter = 0;
    bool bracketFound = false;

    for (size_t stringIndex = 0; stringIndex < stringLength; stringIndex++) {
        if (inputString[stringIndex] == '(') {
            bracketCounter++;
            bracketFound = true;
        }

        if (inputString[stringIndex] == ')') {
            bracketCounter--;
        }

        if (bracketCounter < 0) {
            puts("The balance of brackets isn't maintained");
            return 0;
        }
    }

    if (bracketCounter != 0) {
        puts("The balance of brackets isn't maintained");
        return 0;
    }

    if (bracketFound) {
        puts("The balance of brackets is maintained");
    } else {
        puts("No brackets were entered");
    }

    return 0;
}