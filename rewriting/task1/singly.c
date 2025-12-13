#include "singly_linked_list.h"

int main(void)
{
    List* list = initList();
    int number;
    puts("enter numbers");
    while (scanf("%d", &number) == 1 && number != 0)
        append(list, number);

    if (list->len == 0) {
        puts("ok, not this time");
        deleteList(list);
        return 0;
    }

    sortList(list);

    Node* current = list->head;

    while (current != NULL) {
        Node* next_node = current->next;

        if (next_node != NULL && next_node->value == current->value + 1) {
            Node* to_remove = current;
            current = next_node;
            removeElementList(list, to_remove);
        } else {
            current = next_node;
        }
    }
    puts("Numbers without pair:");
    if (list->len == 0) {
        puts("none");
    } else {
        printList(list);
    }
    deleteList(list);
    return 0;
}