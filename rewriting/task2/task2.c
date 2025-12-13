#include "task2.h"

int countBits(int number)
{
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

int compareByBits(int num1, int num2)
{
    int bitsA = countBits(num1);
    int bitsB = countBits(num2);

    if (bitsA > bitsB) {
        return num1;
    } else if (bitsB > bitsA) {
        return num2;
    } else {
        return num1;
    }
}