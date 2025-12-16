#include <stdio.h>
#include <string.h>

int main(void)
{
    int charIndex = 0;
    char inputString[101];
    char currentChar;

    int scanResult;

    while ((scanResult = getchar()) != EOF && scanResult != '\n' && charIndex < 100) {
        currentChar = (char)scanResult;

        if (currentChar != '{' && currentChar != '}' && currentChar != '[' && currentChar != ']'
            && currentChar != '>' && currentChar != '<') {
            inputString[charIndex++] = currentChar;
        } else {
            puts("Incorrect input");
            return 0;
        }
    }

    inputString[charIndex] = '\0';

    int stringLength = strlen(inputString);

    int bracketCounter = 0;
    int bracketFlag = 0;

    for (int stringIndex = 0; stringIndex < stringLength; stringIndex++) {
        if (inputString[stringIndex] == '(') {
            bracketCounter++;
            bracketFlag = 1;
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

    if (bracketFlag == 1) {
        puts("The balance of brackets is maintained");
    } else {
        puts("No brackets were entered");
    }

    return 0;
}