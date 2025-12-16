#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1;
    int num2;
    if (scanf("%d %d", &num1, &num2) != 2) {
        return 1;
    }
    int cnt = 0;

    if (num2 == 0) {
        puts("Incorrect input");
        return 0;
    }

    int sign = 1;
    if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0)) {
        sign = -1;
    }

    int dividend = abs(num1);
    int divisor = abs(num2);

    while (dividend >= divisor) {
        dividend -= divisor;
        cnt++;
    }

    printf("incomplete quotient = %d", cnt * sign);
    return 0;
}