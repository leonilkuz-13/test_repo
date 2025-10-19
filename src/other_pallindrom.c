#include <stdio.h>

int digit_sum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(void)
{
    int ar[] = {13, 15, 17, 27, 99, 108, 54, 31};
    int size = sizeof(ar) / sizeof(int);
    int max_sum = 0;
    for (int i = 0; i < size; i++)
    {
        int sum = digit_sum(ar[i]);
        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }
    int ar1[sizeof(ar)];
    for (int j = 0; j < sizeof(ar) / sizeof(ar[0]); j++)
    {
        if (digit_sum(ar[j]) == max_sum)
        {
            ar1[j] = ar[j];
        }
        else
        {
            ar1[j] = -1;
        }
    }
    for (int i = 0; i < sizeof(ar1) / sizeof(ar1[0]); i++)
    {
        printf("%d ", ar1[i]);
    }
    return 0;
}