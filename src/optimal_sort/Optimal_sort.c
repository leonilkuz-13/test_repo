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
    int array[MAX_SIZE] = { 0 };
    int length = 0;

    reading(array, &length);

    if (length == 0) {
        puts("0");
        return 0;
    }

    int arrayCopy[MAX_SIZE];
    for (int index = 0; index < length; index++) {
        arrayCopy[index] = array[index];
    }

    quickSort(array, 0, length - 1);

    int count = 0;
    for (int index = 0; index < length; index++) {
        if (array[index] != arrayCopy[index]) {
            count++;
        }
    }
    return count;
}