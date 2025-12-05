#include "cyclic_shift.h"
unsigned int cyclicShift(unsigned int num, unsigned int n)
{
    if (n == 0)
        return 0;
    unsigned int max = num;
    for (int i = 1; i < n; i++) {
        unsigned int s = (num << i) | (num >> (n - i));
        if (n < 32)
            s &= (1u << n) - 1;
        if (s > max)
            max = s;
    }
    return max;
}
