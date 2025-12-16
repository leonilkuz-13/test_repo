#include "singly_linked_list.h"

bool testEmptyList()
{
    List* l = newList();
    bool result = (l != NULL) && (l->len == 0) && (l->head == NULL) && (l->tail == NULL);

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
    bool result = (l->len == 3) && (l->head->data == 12) && (l->head->next->data == 9)
        && (l->tail->data == 13);
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

    bool result = (l->len == 2) && (l->head->data == 10) && (l->tail->data == 30);
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

    bool valid = checkIndex(l, 0);
    bool invalid1 = !checkIndex(l, 1);
    bool invalid2 = !checkIndex(l, -1);
    bool result = valid && invalid1 && invalid2;
    if (result) {
        puts("test 7 passed");
    } else {
        puts("failed 7 test");
    }
    deleteList(l);
    return result;
}

bool testGetFromEmptyList()
{
    List* l = newList();
    int value = get(l, 0);
    bool result = (value == -1);

    if (result) {
        puts("test 8 passed");
    } else {
        puts("failed test 8");
    }

    deleteList(l);
    return result;
}

bool testGetFromSingleElementList()
{
    List* l = newList();
    insert(0, l, 42);

    int value1 = get(l, 0);
    int value2 = get(l, 1);

    bool result = (value1 == 42) && (value2 == -1);

    if (result) {
        puts("test 9 passed");
    } else {
        puts("failed test 9");
    }

    deleteList(l);
    return result;
}

bool testFindIndexToInsertEmptyList()
{
    List* l = newList();
    int index = findIndexToInsert(l, 10);
    bool result = (index == 0);

    if (result) {
        puts("test 10 passed");
    } else {
        puts("failed test 10");
    }

    deleteList(l);
    return result;
}

bool testFindIndexToRemoveEmptyList()
{
    List* l = newList();
    int index = findIndexToRemove(l, 10);

    bool result = (index == -1);
    if (result) {
        puts("test 11 passed");
    } else {
        puts("failed test 11");
    }

    deleteList(l);
    return result;
}

bool testFindIndexToRemoveSinglyElement()
{
    List* l = newList();
    insert(0, l, 25);

    int index1 = findIndexToRemove(l, 25);
    int index2 = findIndexToRemove(l, 30);

    bool result = (index1 == 0) && (index2 == -1);
    if (result) {
        puts("test 12 passed");
    } else {
        puts("failed test 12");
    }

    deleteList(l);
    return result;
}

bool testRemoveFromEmptyList()
{
    List* l = newList();
    listElementRemove(l, 0);

    bool result = (l->len == 0) && (l->head == NULL) && (l->tail == NULL);
    if (result) {
        puts("test 13 passed");
    } else {
        puts("failed test 13");
    }

    deleteList(l);
    return result;
}

bool testRemoveFromSinglyElementList()
{
    List* l = newList();
    insert(0, l, 99);
    listElementRemove(l, 0);

    bool result = (l->len == 0) && (l->head == NULL) && (l->tail == NULL);
    if (result) {
        puts("test 14 passed");
    } else {
        puts("failed test 14");
    }

    deleteList(l);
    return result;
}

bool testCheckIndexEmptyList()
{
    List* l = newList();

    bool result = !checkIndex(l, 0) && !checkIndex(l, -1) && !checkIndex(l, 1);
    if (result) {
        puts("test 15 passed");
    } else {
        puts("failed test 15");
    }

    deleteList(l);
    return result;
}

bool testInsertDuplicates()
{
    List* l = newList();
    insert(0, l, 10);
    insert(1, l, 10);
    insert(2, l, 20);
    insert(3, l, 10);

    bool result = (l->len == 4) && (l->head->data == 10) && (l->head->next->data == 10)
        && (l->head->next->next->data == 20) && (l->tail->data == 10);

    if (result) {
        puts("test 16 passed");
    } else {
        puts("failed test 16");
    }

    deleteList(l);
    return result;
}

bool testFindIndexToRemoveDuplicates()
{
    List* l = newList();
    insert(0, l, 10);
    insert(1, l, 20);
    insert(2, l, 10);
    insert(3, l, 30);
    insert(4, l, 10);

    int index1 = findIndexToRemove(l, 10);
    int index2 = findIndexToRemove(l, 20);

    bool result = (index1 == 0) && (index2 == 1);

    if (result) {
        puts("test 17 passed");
    } else {
        puts("failed test 17");
    }

    deleteList(l);
    return result;
}

bool testRemoveWithDuplicates()
{
    List* l = newList();
    insert(0, l, 10);
    insert(1, l, 20);
    insert(2, l, 10);
    insert(3, l, 30);
    insert(4, l, 10);

    int index = findIndexToRemove(l, 10);
    listElementRemove(l, index);

    bool result = (l->len == 4) && (l->head->data == 20);

    if (result) {
        puts("test 18 passed");
    } else {
        puts("failed test 18");
    }

    deleteList(l);
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