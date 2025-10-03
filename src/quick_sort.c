#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int arr[MAX_SIZE] = {};
int lenArray = 0;

void reading(void)
{
	while (scanf("%d ", arr + lenArray) == 1)
		lenArray++;
}

int distribution(int arr[], int low, int high)
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
		int p = distribution(arr, low, high);
		quickSort(arr, low, p);
		quickSort(arr, p + 1, high);
	}
}

int main(void)
{
	reading();

	int array1[MAX_SIZE];
	for (int i = 0; i < lenArray; i++)
		array1[i] = arr[i];

	quickSort(arr, 0, lenArray - 1);

	int count = 0;
	for (int i = 0; i < lenArray; i++) {
		if (arr[i] != array1[i])
			count++;
	}
	printf("%d", count);

	return 0;
}