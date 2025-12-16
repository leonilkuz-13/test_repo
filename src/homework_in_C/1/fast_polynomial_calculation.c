#include <stdio.h>

int main(void)
{
    int number;

    if (scanf("%d", &number) != 1) {
        return 1;
    }

    int square = number * number;

    printf("%d", (square + number) * (square + 1) + 1);

    return 0;
}