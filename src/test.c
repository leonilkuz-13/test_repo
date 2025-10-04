#include <stdio.h>

int main(void)
{
    typedef struct test
    {
        char name[50];
        int age;
        float height;
    } test1;
    test1 test;
    test.age = 12;
    printf("%d",test.age); 

}

