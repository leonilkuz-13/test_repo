#include <stdio.h>

int main()
{
    int count[28] = {0};
    for (int n = 0; n < 1000; n++) {
        int sum = (n / 100) + ((n / 10) % 10) + (n % 10);
        count[sum]++;
    }
    int total = 0;
    for (int s = 0; s <= 27; s++) {
        total += count[s] * count[s];
    }
    printf("%d", total);
    return 0;
}