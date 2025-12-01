#include <stdio.h>
#include <stdint.h>

typedef union {
    double d;
    uint64_t u;
} DoubleUnion;

int main()
{
    DoubleUnion du;

    printf("Enter a number: ");
    scanf("%lf", &du.d);

    uint64_t bits = du.u;

    int sign = (bits >> 63) & 1;

    int exponent = (bits >> 52) & 0x7FF;

    uint64_t mantissa = bits & 0xFFFFFFFFFFFFFULL;

    if (exponent == 0) {
        if (mantissa == 0) {
            printf("Result: %c0*2^0\n", sign ? '-' : '+');
        } else {
            printf("Subnormal number\n");
        }
        return 0;
    }

    if (exponent == 0x7FF) {
        if (mantissa == 0) {
            printf("Infinity\n");
        } else {
            printf("NaN\n");
        }
        return 0;
    }

    int biased_exponent = exponent - 1023;

    double m = 1.0;

    for (int i = 51; i >= 0; i--) {
        if ((mantissa >> i) & 1) {
            m += 1.0 / (1ULL << (52 - i));
        }
    }

    printf("Result: %c%.19g*2^%d\n", sign ? '-' : '+', m, biased_exponent);

    return 0;
}