#include <stdio.h>

int main(void)
{
    int const arrayLength, segmentSize;
    scanf("%d %d", &arrayLength, &segmentSize);

    if (arrayLength <= segmentSize) {
        printf("incorrect input");
    } else {
        int array[arrayLength + 1];

        for (int index = 0; index < sizeof(array) / sizeof(*array); index++) {
            array[index] = index + 1;
        }

        for (int shiftCount = 0; shiftCount <= arrayLength - (segmentSize + 1); shiftCount++) {
            int tempValue = array[arrayLength];
            for (int position = arrayLength; position > 0; position--) {
                array[position] = array[position - 1];
            }
            array[0] = tempValue;
        }

        for (int index = 0; index < sizeof(array) / sizeof(*array); index++) {
            printf("%d ", array[index]);
        }
    }
    return 0;
}