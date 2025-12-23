#include <stdio.h>
#include "quick_sort.h"
#define MAX_SIZE 100

void reading(int arr[], int* lenArray)
{
    while (*lenArray < MAX_SIZE && scanf("%d", arr + *lenArray) == 1)
        (*lenArray)++;
}

int main(void)
{
    int arr[MAX_SIZE] = {};
    int lenArray = 0;

    reading(arr, &lenArray);

    if (lenArray == 0) {
        puts("0\n");
        return 0;
    }

    int array1[MAX_SIZE];
    for (int i = 0; i < lenArray; i++)
        array1[i] = arr[i];

    quickSort(arr, 0, lenArray - 1);

    int count = 0;
    for (int i = 0; i < lenArray; i++) {
        if (arr[i] != array1[i])
            count++;
    }
    printf("%d\n", count);

    return 0;
}