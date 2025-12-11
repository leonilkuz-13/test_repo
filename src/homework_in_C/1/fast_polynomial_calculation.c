#include <stdio.h>

int main(void)
{
    int x;

    scanf("%d", &x);

    int square = x * x;

    printf("%d", (square + x) * (square + 1) + 1);

    return 0;
}