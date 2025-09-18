#include <stdio.h>

int main(void) { 
    int x;
    scanf("%d",&x);
    printf("%d", (x * x + x) * (x * x + 1) + 1); 
    return 0;
}
/*2 операции умножения: 1) число возводится в квадрат 2) умножаются значения двух скобок*/