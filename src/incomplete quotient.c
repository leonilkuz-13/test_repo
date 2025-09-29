#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int cnt = 0;

    if (a > 0 && b != 0)
    {
        while (a > 0)
        {
            if (a - b > 0)
            {
                a -= b;
                cnt++;
            }
            if (a - b < 0)
            {
                printf("incomplete quotient = %d", cnt);
                a -= b;
            }
            if (a - b == 0)
            {
                a -= b;
                cnt++;
                printf("incomplete quotient = %d", cnt);
            }
        }
        return 0;
    }
    else
    {
        puts("Incorrect input");
        return 0;
    }
}