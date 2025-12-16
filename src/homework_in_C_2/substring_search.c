#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[101];
    char substr[100];
    int count = 0;

    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }
    if (fgets(substr, sizeof(substr), stdin) == NULL) {
        return 1;
    }

    char* newlinePositionInStr = strchr(str, '\n');
    char* newlinePositionInSubstr = strchr(substr, '\n');

    if (newlinePositionInStr != NULL) {
        newlinePositionInStr[0] = '\0';
    }
    if (newlinePositionInSubstr != NULL) {
        newlinePositionInSubstr[0] = '\0';
    }

    char* currentPosition = str;

    while ((currentPosition = strstr(currentPosition, substr)) != NULL) {
        count++;
        currentPosition++;
    }

    if (count > 0) {
        printf("count substr in str = %d", count);
    } else {
        puts("The substr isn't in str");
    }

    return 0;
}