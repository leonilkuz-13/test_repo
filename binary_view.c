#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    unsigned char a8 = a;
    unsigned char b8 = b;

    printf("Двоичное представление:\n");
    printf("%d = ", a);
    for (int i = 7; i >= 0; i--)
        printf("%d", (a8 >> i) & 1);
    printf("\n");

    printf("%d = ", b);
    for (int i = 7; i >= 0; i--)
        printf("%d", (b8 >> i) & 1);
    printf("\n");

    printf("\n");

    printf("Сложение в столбик:\n");
    for (int i = 7; i >= 0; i--)
        printf("%d", (a8 >> i) & 1);
    printf("\n");

    for (int i = 7; i >= 0; i--)
        printf("%d", (b8 >> i) & 1);
    printf("\n");

    unsigned char result = a8 + b8;

    for (int i = 7; i >= 0; i--)
        printf("%d", (result >> i) & 1);
    printf("\n");

    printf("\n");

    printf("Сумма в двоичном представлении:\n");
    for (int i = 7; i >= 0; i--)
        printf("%d", (result >> i) & 1);
    printf("\n");

    printf("\n");

    printf("Сумма в десятичном виде:\n");
    if (result > 127) {
        printf("%d\n", (int)result - 256);
    } else {
        printf("%d\n", result);
    }

    return 0;
}