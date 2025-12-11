#include "doubly_linked_list.h"

int main()
{
    int n, m;

    puts("enter the number of warriors: ");
    scanf("%d", &n);

    puts("enter the number of step: ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        return -1;
    }

    LIST* warriors = initList();
    if (!warriors) {
        return -1;
    }

    for (int i = 1; i <= n; i++) {
        appendToBehind(i, warriors);
    }

    int current_index = 0;

    while (warriors->len > 1) {
        int index_to_remove = (current_index + m - 1) % warriors->len;
        elementRemoveToIndex(warriors, index_to_remove);
        current_index = index_to_remove;
        if (current_index >= warriors->len) {
            current_index = 0;
        }
    }
    int survivor = warriors->head->number;
    deleteList(warriors);

    printf("position of a surviving warrior: %d\n", survivor);
    return 0;
}