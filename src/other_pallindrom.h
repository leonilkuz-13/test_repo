#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int palindrom(int array[], int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        if (array[i] != array[len - 1 - i])
            return 0;
    }
    return 1;
}

void bin(int n, int num[], int* len)
{
    int i = 0;
    while (n > 0)
    {
        num[i] = n % 2;
        n = n / 2;
        i++;
    }
    *len = i;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++)
    {
        int len = 0;
        int num[32];
        bin(i, num, &len);
        if (palindrom(num, len))
            printf("%d ", i);
    }
    return 0;
}
