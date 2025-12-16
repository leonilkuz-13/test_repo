#include <stdio.h>

int main()
{
    int count[28] = { 0 };
    for (int num = 0; num < 1000; num++) {
        int sum = (num / 100) + ((num / 10) % 10) + (num % 10);
        count[sum]++;
    }
    int total = 0;
    for (int sum = 0; sum <= 27; sum++) {
        total += count[sum] * count[sum];
    }
    printf("%d", total);
    return 0;
}