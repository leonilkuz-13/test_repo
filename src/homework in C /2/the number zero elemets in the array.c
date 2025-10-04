#include <stdio.h>

int main(void) {
    int n,cnt = 0;
    scanf("%d",&n);
    const int ar_r[n];
    for (int i = 0; i < sizeof(ar_r) / sizeof(*ar_r); i++)
        if (ar_r[i] == 0) cnt++;
    printf("%d",cnt);
    return 0;
}

