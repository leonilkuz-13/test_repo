#include <stdio.h>

int main(void)
{
    int cnt = 0;
    int arraySize;
    if (scanf("%d", &arraySize) != 1) {
        return 1;
    }
    int array[arraySize];
    for (int index = 0; index < arraySize; index++) {
        if (scanf("%d", &array[index]) != 1) {
            return 1;
        }
    }
    for (int index = 0; index < arraySize; index++) {
        if (array[index] == 0) {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}