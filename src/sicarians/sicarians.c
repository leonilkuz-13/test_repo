#include "doubly_linked_list.h"

int main()
{
    int count;
    puts("enter the number of warriors: ");
    if (scanf("%d", &count) != 1) {
        puts("Invalid input!!!");
        return -1;
    }

    int step;
    puts("enter the number of step: ");
    if (scanf("%d", &step) != 1) {
        puts("Invalid input!!!");
        return -1;
    }

    if (count <= 0 || step <= 0) {
        puts("Values must be positive!");
        return -1;
    }

    List* list = initList();
    if (list == NULL) {
        puts("Memory allocation failed!");
        return -1;
    }

    for (int num = 1; num <= count; num++) {
        appendToBehind(num, list);
    }

    Node* current = list->head;
    while (list->len > 1) {
        for (int stepcnt = 1; stepcnt < step; stepcnt++) {
            current = current->next;
        }
        Node* ptr = current->next;
        elementRemoveToValue(list, current->number);
        current = ptr;
    }

    int survivor = list->head->number;
    deleteList(list);

    printf("position of a surviving warrior: %d\n", survivor);
    return 0;
}