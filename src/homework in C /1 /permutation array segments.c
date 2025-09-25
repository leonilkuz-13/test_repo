#include <stdio.h>
int main(void) {
    int const n,m;
    scanf("%d %d",&n,&m);
    if(n <= m)
        printf("incorrect input");
    else {
        int array[n + 1]; /*если n - последний элемент, то всего элементов n + 1*/
        for(int i = 0; i < sizeof(array) / sizeof(*array); i++)
            array[i] = i + 1; /*массив вида {1, 2, ..., n, n + 1}*/
        for (int k = 0; k <= n - (m + 1); k++) {
            int t = array[n];
            for (int j = n; j > 0; j--) 
                array[j] = array[j - 1];
            array[0] = t;
        }
        for(int i = 0; i < sizeof(array) / sizeof(*array); i++) printf("%d ",array[i]);
    }
    return 0;
}

/*в условии задачи идндексация с array[1] элемента, а в моем решении индексация с array[0] элемента. Т.е., если на входе m = 2, то будут передвинуты 3 элемента. Надеюсь, что я правильно понял задачу и это не ошибка.*/