#include "singly_linked_list.h"

typedef enum Instruction { EXIT, ADD, REMOVE, PRINT } Instruction;

int main(void)
{
    List* list = newList();
    int value;
    Instruction choice = EXIT;

    do {
        puts("0 - Exit");
        puts("1 - Add element in list");
        puts("2 - Remove element");
        puts("3 - Print list");
        puts("enter number");
        int input;
        if (scanf("%d", &input) != 1) {
            puts("NUMBER!");
            while (getchar() != '\n') {
                ;
            }
            continue;
        }

        choice = (Instruction)input;
        switch (choice) {
            case EXIT:
                deleteList(list);
                puts("list released");
                break;

            case ADD:
                puts("enter number");
                while (scanf("%d", &value) != 1) {
                    puts("NUMBER!!!");
                    while (getchar() != '\n') {
                        ;
                    }
                }
                insert(list, value);
                break;

            case REMOVE:
                puts("enter number");
                while (scanf("%d", &value) != 1) {
                    puts("NUMBER!!!");
                    while (getchar() != '\n') {
                        ;
                    }
                }
                removeByValue(list, value);
                break;

            case PRINT: printList(list); break;

            default: puts("Invalid choice! Please enter 0-3"); break;
        }
    } while (choice != EXIT);

    return 0;
}