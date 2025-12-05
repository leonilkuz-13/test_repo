#include "pallindrome_list.h"

bool testInitList()
{
    LIST* list = initList();
    bool result = (list->len == 0) && (list->head == NULL) && (list->tail == NULL);
    if (result) {
        puts("test init passed");
        free(list);
        return result;
    }
    puts("test init failed");
    free(list);
    return result;
}

bool testAppend()
{
    LIST* list = initList();
    append(12, list, 0);
    append(100000000, list, 0);
    append(-10000000, list, 2);

    bool result = (list->len == 3) && (list->head->number == 100000000)
        && (list->head->next->number == 12) && (list->tail->number == -10000000);

    if (result) {
        puts("test append passed");
        deleteList(list);
        return result;
    }

    puts("test append failed");
    deleteList(list);
    return result;
}

bool testCheckpallindrome()
{
}

void runAllTests()
{
    bool result = true;
    result = testInitList() && testAppend();

    if (result) {
        puts("All tests passed");
    } else {
        puts("Some tests failed");
    }
}

bool testPalindrome()
{
    bool passed = true;

    LIST* list1 = initList();
    append(10, list1, 0);
    append(20, list1, 1);
    append(30, list1, 2);
    append(20, list1, 3);
    append(10, list1, 4);

    if (CheckPallindrome(list1) != 0) {
        passed = false;
    }
    deleteList(list1);

    LIST* list2 = initList();
    append(10, list2, 0);
    append(20, list2, 1);
    append(30, list2, 2);
    append(40, list2, 3);
    append(20, list2, 4);
    append(10, list2, 5);

    if (CheckPallindrome(list2) != -1) {
        passed = false;
    }
    deleteList(list2);

    LIST* list3 = initList();
    append(5, list3, 0);

    if (CheckPallindrome(list3) != 0) {
        passed = false;
    }
    deleteList(list3);

    return passed;
}

int main()
{
    runAllTests();
    return 0;
}