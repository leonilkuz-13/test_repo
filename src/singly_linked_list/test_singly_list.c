#include "singly_linked_list.h"

bool testEmptyList()
{
    List* l = newList();
    bool result =
        (l != NULL) && (l->len == 0) && (l->head == NULL) && (l->tail == NULL);

    if (result) {
        puts("test 1 passed");
    } else {
        puts("failed test 1");
    }

    deleteList(l);
    return result;
}

bool testInsert()
{
    List* l = newList();
    insert(0, l, 13);
    insert(0, l, 12);
    insert(1, l, 9);
    bool result = (l->len == 3) && (l->head->data == 12) &&
                  (l->head->next->data == 9) && (l->tail->data == 13);
    if (result) {
        puts("test 2 passed");
    } else {
        puts("failed test 2");
    }
    deleteList(l);
    return result;
}

bool testGet()
{
    List* l = newList();
    insert(0, l, 13);
    insert(0, l, 12);
    insert(1, l, 9);
    int number1 = get(l, 0);
    int number2 = get(l, 2);
    int number3 = get(l, 100);
    bool result;
    if (number1 == 12 && number2 == 13 && number3 == -1) {
        puts("test 3 passed");
        result = true;
    } else {
        puts("failed test 3");
        result = false;
    }
    deleteList(l);
    return result;
}

bool testFindIndexToInsert()
{
    List* l = newList();
    insert(0, l, 10);
    insert(1, l, 30);

    int index1 = findIndexToInsert(l, 5);
    int index2 = findIndexToInsert(l, 15);
    int index3 = findIndexToInsert(l, 35);

    bool result = (index1 == 0) && (index2 == 1) && (index3 == 2);
    if (result) {
        puts("test 4 passed");
    } else {
        puts("failed test 4");
    }
    deleteList(l);
    return result;
}

bool testFindIndexToRemove()
{
    List* l = newList();

    bool test1 = (findIndexToRemove(l, 10) == -1);

    insert(0, l, 10);
    insert(1, l, 20);
    insert(2, l, 30);

    bool valid1 = (findIndexToRemove(l, 10) == 0);
    bool valid2 = (findIndexToRemove(l, 20) == 1);
    bool valid3 = (findIndexToRemove(l, 30) == 2);
    bool invalid = (findIndexToRemove(l, 15) == -1);
    bool result = valid1 && valid2 && valid3 && invalid;
    if (result) {
        puts("test 5 passed");
    } else {
        puts("failed 5 test");
    }

    deleteList(l);
    return result;
}

bool testRemoveElement()
{
    List* l = newList();
    insert(0, l, 10);
    insert(1, l, 20);
    insert(2, l, 30);

    int index = findIndexToRemove(l, 20);
    listElementRemove(l, index);

    bool result =
        (l->len == 2) && (l->head->data == 10) && (l->tail->data == 30);
    if (result) {
        puts("test 6 passed");
    } else {
        puts("failed 6 test");
    }
    deleteList(l);
    return result;
}

bool testCheckIndex()
{
    List* l = newList();
    insert(0, l, 10);

    bool valid = CheckIndex(l, 0);
    bool invalid1 = !CheckIndex(l, 1);
    bool invalid2 = !CheckIndex(l, -1);
    bool result = valid && invalid1 && invalid2;
    if (result) {
        puts("test 7 passed");
    } else {
        puts("failed 7 test");
    }
    deleteList(l);
    return result;
}

void runAllTests()
{
    int passed = 0;
    int total = 7;

    if (testEmptyList()) {
        passed++;
    }
    if (testInsert()) {
        passed++;
    }
    if (testGet()) {
        passed++;
    }
    if (testFindIndexToInsert()) {
        passed++;
    }
    if (testFindIndexToRemove()) {
        passed++;
    }
    if (testRemoveElement()) {
        passed++;
    }
    if (testCheckIndex()) {
        passed++;
    }

    if (passed == total) {
        printf("All tests passed!\n");
    } else {
        printf("Some tests failed!\n");
    }
}

int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        runAllTests();
        return 0;
    }
    printf("Use --test flag to run tests\n");
    return 0;
}