#include <stdio.h>

int main(void)
{
    int arrayLength;
    int segmentSize;

    if (scanf("%d %d", &arrayLength, &segmentSize) != 2) {
        return 1;
    }

    if (arrayLength <= segmentSize) {
        printf("incorrect input");
        return 0;
    }

    int array[arrayLength + 1];

    int arraySize = arrayLength + 1;
    for (int index = 0; index < arraySize; index++) {
        array[index] = index + 1;
    }

    for (int shiftCount = 0; shiftCount <= arrayLength - (segmentSize + 1); shiftCount++) {
        int tempValue = array[arrayLength];
        for (int position = arrayLength; position > 0; position--) {
            array[position] = array[position - 1];
        }
        array[0] = tempValue;
    }
    for (int index = 0; index < arraySize; index++) {
        printf("%d ", array[index]);
    }

    return 0;
}