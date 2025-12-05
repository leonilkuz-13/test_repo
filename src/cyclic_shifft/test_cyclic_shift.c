#include "cyclic_shift.h"

int main()
{
    bool t1 = cyclicShift(0b1011, 4) == 0b1110;
    bool t2 = cyclicShift(0b0011, 4) == 0b1100;
    bool t3 = cyclicShift(0b1, 1) == 0b1;
    bool t4 = cyclicShift(0b0000, 4) == 0b0000;
    bool t5 = cyclicShift(0b1111, 4) == 0b1111;
    bool result = t1 && t2 && t3 && t4 && t5;
    if (result) {
        puts("All test passed");
        return 0;
    }
    puts("some test failed");
    return -1;
}