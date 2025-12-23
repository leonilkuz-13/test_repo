#include <stdio.h>
#include "Quick_sort.h"
#define MAX_SIZE 100

void reading(int array[], int* length)
{
    while (*length < MAX_SIZE && scanf("%d", array + *length) == 1) {
        (*length)++;
    }
}

int main(void)
{
    int array[MAX_SIZE] = {};
    int length = 0;

    reading(array, &length);

    if (length == 0) {
        puts("0");
        return 0;
    }

    int arrayCopy[MAX_SIZE];
    for (int i = 0; i < length; i++) {
        arrayCopy[i] = array[i];
    }

    quickSort(array, 0, length - 1);

    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] != arrayCopy[i]) {
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}