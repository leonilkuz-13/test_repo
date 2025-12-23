#include "singly_linked_list.h"
#include <string.h>

bool testEmptyList()
{
    List* list = newList();
    if (list == NULL) {
        puts("failed test 1: newList returned NULL");
        return false;
    }

    bool valid1 = (list->len == 0);
    bool valid2 = (list->head == NULL);
    bool valid3 = (list->tail == NULL);
    bool result = valid1 && valid2 && valid3;

    if (result) {
        puts("test 1 passed");
    } else {
        puts("failed test 1");
    }

    deleteList(list);
    return result;
}

bool testInsert()
{
    List* list = newList();
    insert(0, list, 13);
    insert(0, list, 12);
    insert(1, list, 9);

    bool valid1 = (list->len == 3);
    bool valid2 = (list->head->data == 12);
    bool valid3 = (list->head->next->data == 9);
    bool valid4 = (list->tail->data == 13);
    bool result = valid1 && valid2 && valid3 && valid4;

    if (result) {
        puts("test 2 passed");
    } else {
        puts("failed test 2");
    }
    deleteList(list);
    return result;
}

bool testGet()
{
    List* list = newList();
    insert(0, list, 13);
    insert(0, list, 12);
    insert(1, list, 9);
    int number1 = get(list, 0);
    int number2 = get(list, 2);
    int number3 = get(list, 100);
    bool valid1 = (number1 == 12);
    bool valid2 = (number2 == 13);
    bool valid3 = (number3 == -1);
    bool result = valid1 && valid2 && valid3;

    if (result) {
        puts("test 3 passed");
        result = true;
    } else {
        puts("failed test 3");
        result = false;
    }
    deleteList(list);
    return result;
}

bool testFindIndexToInsert()
{
    List* list = newList();
    insert(0, list, 10);
    insert(1, list, 30);

    int index1 = findIndexToInsert(list, 5);
    int index2 = findIndexToInsert(list, 15);
    int index3 = findIndexToInsert(list, 35);

    bool valid1 = (index1 == 0);
    bool valid2 = (index2 == 1);
    bool valid3 = (index3 == 2);
    bool result = valid1 && valid2 && valid3;

    if (result) {
        puts("test 4 passed");
    } else {
        puts("failed test 4");
    }
    deleteList(list);
    return result;
}

bool testFindIndexToRemove()
{
    List* list = newList();
    insert(0, list, 10);
    insert(1, list, 20);
    insert(2, list, 30);

    bool valid1 = (findIndexToRemove(list, 10) == 0);
    bool valid2 = (findIndexToRemove(list, 20) == 1);
    bool valid3 = (findIndexToRemove(list, 30) == 2);
    bool invalid = (findIndexToRemove(list, 15) == -1);
    bool result = valid1 && valid2 && valid3 && invalid;

    if (result) {
        puts("test 5 passed");
    } else {
        puts("failed 5 test");
    }

    deleteList(list);
    return result;
}

bool testRemoveElement()
{
    List* list = newList();
    insert(0, list, 10);
    insert(1, list, 20);
    insert(2, list, 30);

    int index = findIndexToRemove(list, 20);
    listElementRemove(list, index);

    bool valid1 = (list->len == 2);
    bool valid2 = (list->head->data == 10);
    bool valid3 = (list->tail->data == 30);
    bool result = valid1 && valid2 && valid3;

    if (result) {
        puts("test 6 passed");
    } else {
        puts("failed 6 test");
    }
    deleteList(list);
    return result;
}

bool testCheckIndex()
{
    List* list = newList();
    insert(0, list, 10);

    bool valid = checkIndex(list, 0);
    bool invalid1 = !checkIndex(list, 1);
    bool invalid2 = !checkIndex(list, -1);
    bool result = valid && invalid1 && invalid2;

    if (result) {
        puts("test 7 passed");
    } else {
        puts("failed 7 test");
    }
    deleteList(list);
    return result;
}

bool testGetFromEmptyList()
{
    List* list = newList();
    int value = get(list, 0);
    bool result = (value == -1);

    if (result) {
        puts("test 8 passed");
    } else {
        puts("failed test 8");
    }

    deleteList(list);
    return result;
}

bool testGetFromSingleElementList()
{
    List* list = newList();
    insert(0, list, 42);

    int value1 = get(list, 0);
    int value2 = get(list, 1);

    bool valid1 = (value1 == 42);
    bool valid2 = (value2 == -1);
    bool result = valid1 && valid2;

    if (result) {
        puts("test 9 passed");
    } else {
        puts("failed test 9");
    }

    deleteList(list);
    return result;
}

bool testFindIndexToInsertEmptyList()
{
    List* list = newList();
    int index = findIndexToInsert(list, 10);
    bool result = (index == 0);

    if (result) {
        puts("test 10 passed");
    } else {
        puts("failed test 10");
    }

    deleteList(list);
    return result;
}

bool testFindIndexToRemoveEmptyList()
{
    List* list = newList();
    int index = findIndexToRemove(list, 10);

    bool result = (index == -1);
    if (result) {
        puts("test 11 passed");
    } else {
        puts("failed test 11");
    }

    deleteList(list);
    return result;
}

bool testFindIndexToRemoveSinglyElement()
{
    List* list = newList();
    insert(0, list, 25);

    int index1 = findIndexToRemove(list, 25);
    int index2 = findIndexToRemove(list, 30);

    bool valid1 = (index1 == 0);
    bool valid2 = (index2 == -1);
    bool result = valid1 && valid2;

    if (result) {
        puts("test 12 passed");
    } else {
        puts("failed test 12");
    }

    deleteList(list);
    return result;
}

bool testRemoveFromEmptyList()
{
    List* list = newList();
    listElementRemove(list, 0);

    bool valid1 = (list->len == 0);
    bool valid2 = (list->head == NULL);
    bool valid3 = (list->tail == NULL);
    bool result = valid1 && valid2 && valid3;

    if (result) {
        puts("test 13 passed");
    } else {
        puts("failed test 13");
    }

    deleteList(list);
    return result;
}

bool testRemoveFromSinglyElementList()
{
    List* list = newList();
    insert(0, list, 99);
    listElementRemove(list, 0);

    bool valid1 = (list->len == 0);
    bool valid2 = (list->head == NULL);
    bool valid3 = (list->tail == NULL);
    bool result = valid1 && valid2 && valid3;

    if (result) {
        puts("test 14 passed");
    } else {
        puts("failed test 14");
    }

    deleteList(list);
    return result;
}

bool testCheckIndexEmptyList()
{
    List* list = newList();

    bool invalid1 = !checkIndex(list, 0);
    bool invalid2 = !checkIndex(list, -1);
    bool invalid3 = !checkIndex(list, 1);
    bool result = invalid1 && invalid2 && invalid3;

    if (result) {
        puts("test 15 passed");
    } else {
        puts("failed test 15");
    }

    deleteList(list);
    return result;
}

bool testInsertDuplicates()
{
    List* list = newList();
    insert(0, list, 10);
    insert(1, list, 10);
    insert(2, list, 20);
    insert(3, list, 10);

    bool valid1 = (list->len == 4);
    bool valid2 = (list->head->data == 10);
    bool valid3 = (list->head->next->data == 10);
    bool valid4 = (list->head->next->next->data == 20);
    bool valid5 = (list->tail->data == 10);
    bool result = valid1 && valid2 && valid3 && valid4 && valid5;

    if (result) {
        puts("test 16 passed");
    } else {
        puts("failed test 16");
    }

    deleteList(list);
    return result;
}

bool testFindIndexToRemoveDuplicates()
{
    List* list = newList();
    insert(0, list, 10);
    insert(1, list, 20);
    insert(2, list, 10);
    insert(3, list, 30);
    insert(4, list, 10);

    int index1 = findIndexToRemove(list, 10);
    int index2 = findIndexToRemove(list, 20);

    bool valid1 = (index1 == 0);
    bool valid2 = (index2 == 1);
    bool result = valid1 && valid2;

    if (result) {
        puts("test 17 passed");
    } else {
        puts("failed test 17");
    }

    deleteList(list);
    return result;
}

bool testRemoveWithDuplicates()
{
    List* list = newList();
    insert(0, list, 10);
    insert(1, list, 20);
    insert(2, list, 10);
    insert(3, list, 30);
    insert(4, list, 10);

    int index = findIndexToRemove(list, 10);
    listElementRemove(list, index);

    bool valid1 = (list->len == 4);
    bool valid2 = (list->head->data == 20);
    bool result = valid1 && valid2;

    if (result) {
        puts("test 18 passed");
    } else {
        puts("failed test 18");
    }

    deleteList(list);
    return result;
}

void runAllTests()
{
    bool result = true;
    result = result && testEmptyList();
    result = result && testInsert();
    result = result && testGet();
    result = result && testFindIndexToInsert();
    result = result && testFindIndexToRemove();
    result = result && testRemoveElement();
    result = result && testCheckIndex();
    result = result && testGetFromEmptyList();
    result = result && testGetFromSingleElementList();
    result = result && testFindIndexToInsertEmptyList();
    result = result && testFindIndexToRemoveEmptyList();
    result = result && testFindIndexToRemoveSinglyElement();
    result = result && testRemoveFromEmptyList();
    result = result && testRemoveFromSinglyElementList();
    result = result && testCheckIndexEmptyList();
    result = result && testInsertDuplicates();
    result = result && testFindIndexToRemoveDuplicates();
    result = result && testRemoveWithDuplicates();

    if (result) {
        puts("all test passed");
    } else {
        puts("some test failed");
    }
}

int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        runAllTests();
        return 0;
    }
    puts("Use --test flag to run tests");
    return 0;
}