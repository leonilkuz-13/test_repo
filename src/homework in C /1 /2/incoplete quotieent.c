#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a,b;
    scanf("%d %d",&a,&b);
    int cnt = 0;
    while (a > 0) {
        if (a - b > 0) {
            a -= b;
            cnt++;
        }
        if (a - b < 0) {
            printf("incoplete quotieent = %d",cnt);
            a -= b;
        }
        if (a - b == 0) { 
            a -= b;
            cnt++;
            printf("incoplete quotieent = %d",cnt);
        }
    }

    return 0;
}