#include <stdio.h>

int main(void)
{
    int number;

    scanf("%d", &number);

    int square = number * number;

    printf("%d", (square + number) * (square + 1) + 1);

    return 0;
}