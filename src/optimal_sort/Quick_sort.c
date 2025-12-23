#include "Quick_sort.h"
#include <stdbool.h>

int partition(int array[], int low, int high)
{
    int pivot = array[(low + high) / 2];
    int left = low - 1;
    int right = high + 1;
    int temporary;

    while (true) {
        do {
            left++;
        } while (array[left] < pivot);

        do {
            right--;
        } while (array[right] > pivot);

        if (left >= right) {
            return right;
        }

        temporary = array[left];
        array[left] = array[right];
        array[right] = temporary;
    }
}

void quickSort(int array[], int low, int high)
{
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex);
        quickSort(array, pivotIndex + 1, high);
    }
}