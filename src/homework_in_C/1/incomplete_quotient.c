#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int cnt = 0;

    if (b == 0) {
        puts("Incorrect input");
        return 0;
    }

    int sign = 1;
    if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        sign = -1;
    }

    int dividend = abs(a);
    int divisor = abs(b);

    while (dividend >= divisor) {
        dividend -= divisor;
        cnt++;
    }

    printf("incomplete quotient = %d", cnt * sign);
    return 0;
}