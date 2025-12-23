#include "Quick_sort.h"

int partittion(int arr[], int low, int high)
{
    int pivot = arr[(low + high) / 2];
    int left = low - 1;
    int right = high + 1;
    int t;

    while (true) {
        do {
            left++;
        } while (arr[left] < pivot);

        do {
            right--;
        } while (arr[right] > pivot);

        if (left >= right)
            return right;

        t = arr[left];
        arr[left] = arr[right];
        arr[right] = t;
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int p = partittion(arr, low, high);
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}