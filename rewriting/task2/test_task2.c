#include "task2.h"

bool testBasic()
{
    int result = compareByBits(5, 3);
    bool ok = result == 5;
    if (ok) {
        puts("testBasic passed");
    } else {
        puts("testBasic failed");
    }
    return ok;
}

bool testMoreBits()
{
    int result = compareByBits(7, 8);
    bool ok = result == 7;
    if (ok) {
        puts("testMoreBits passed");
    } else {
        puts("testMoreBits failed");
    }
    return ok;
}

bool testEqualBits()
{
    int result = compareByBits(10, 12);
    bool ok = result == 12;
    if (ok) {
        puts("testEqualBits passed");
    } else {
        puts("testEqualBits failed");
    }
    return ok;
}

bool testBigNumbers()
{
    int result = compareByBits(255, 256);
    bool ok = result == 255;
    if (ok) {
        puts("testBigNumbers passed");
    } else {
        puts("testBigNumbers failed");
    }
    return ok;
}

bool testZero()
{
    int result = compareByBits(0, 1);
    bool ok = result == 1;
    if (ok) {
        puts("testZero passed");
    } else {
        puts("testZero failed");
    }
    return ok;
}

bool testSameNumber()
{
    int result = compareByBits(42, 42);
    bool ok = result == 42;
    if (ok) {
        puts("testSameNumber passed");
    } else {
        puts("testSameNumber failed");
    }
    return ok;
}

bool testCountBits()
{
    bool ok = true;
    ok = ok && (countBits(0) == 0);
    ok = ok && (countBits(1) == 1);
    ok = ok && (countBits(3) == 2);
    ok = ok && (countBits(7) == 3);
    ok = ok && (countBits(255) == 8);

    if (ok) {
        puts("testCountBits passed");
    } else {
        puts("testCountBits failed");
    }
    return ok;
}

void runAllTests()
{
    bool ok = true;
    ok = ok && testCountBits();
    ok = ok && testBasic();
    ok = ok && testMoreBits();
    ok = ok && testEqualBits();
    ok = ok && testBigNumbers();
    ok = ok && testZero();
    ok = ok && testSameNumber();

    if (ok) {
        puts("All tests passed");
    } else {
        puts("Some tests failed");
    }
}

int main()
{
    runAllTests();
    return 0;
}