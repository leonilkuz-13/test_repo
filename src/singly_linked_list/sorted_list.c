#include "singly_linked_list.h"

typedef enum instruction
{
    EXIT,
    ADD,
    REMOVE,
    PRINT
} Instruction;

int main(void)
{
    List* l = newList();
    int value;
    Instruction choice;

    do
    {
        puts("");
        puts("0 - Exit");
        puts("1 - Add element in list");
        puts("2 - Remove element");
        puts("3 - Print list");
        puts("enter number");
        int input;
        if (scanf("%d", &input) != 1)
        {
            puts("NUMBER!");
            while (getchar() != '\n')
                continue;
            continue;
        }

        choice = (Instruction)input;
        switch (choice)
        {
            case EXIT:
                Exit(l);
                puts("list released");
                break;

            case ADD:
                puts("enter number");
                while (scanf("%d", &value) != 1)
                {
                    puts("NUMBER!!!");
                    while (getchar() != '\n')
                        continue;
                }
                int index_add = findIndexToInsert(l, value);
                insert(index_add, l, value);
                break;

            case REMOVE:
                puts("enter number");
                while (scanf("%d", &value) != 1)
                {
                    puts("NUMBER!!!");
                    while (getchar() != '\n')
                        continue;
                }

                int index_remove = findIndexToRemove(l, value);
                listElementRemove(l, index_remove);
                break;

            case PRINT: printList(l); break;

            default: break;
        }
    } while (choice != EXIT);
    return 0;
}