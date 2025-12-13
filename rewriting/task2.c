#include <stdio.h>

int countBits(int number)
{
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int bitsA = countBits(num1);
    int bitsB = countBits(num2);
    if (bitsA > bitsB)
        printf("%d", num1);
    else if (bitsA == bitsB)
        printf("%d", num1);
    else
        printf("%d", num2);
    return 0;
}