#include "pallindrome_list.h"

LIST* initList()
{
    LIST* list = malloc(sizeof(LIST));
    if (list == NULL)
        return NULL;
    list->len = 0;
    list->tail = NULL;
    list->head = NULL;

    return list;
}

void appendToEmptyList(LIST* list, NODE* ptr)
{
    list->head = ptr;
    list->tail = ptr;
    ptr->next = ptr;
    ptr->last = ptr;
    list->len++;
}

void appendToBegging(int number, LIST* list)
{
    NODE* ptr = malloc(sizeof(NODE));
    if (ptr == NULL)
        return;
    ptr->number = number;
    if (list->len == 0) {
        appendToEmptyList(list, ptr);
    } else {
        list->tail->next = ptr;
        list->head->last = ptr;
        ptr->next = list->head;
        ptr->last = list->tail;
        list->head = ptr;
        list->len++;
    }
}

void appendToBehind(int number, LIST* list)
{
    NODE* ptr = malloc(sizeof(NODE));
    if (ptr == NULL)
        return;
    ptr->number = number;
    if (list->len == 0) {
        appendToEmptyList(list, ptr);
    } else {
        list->tail->next = ptr;
        list->head->last = ptr;
        ptr->next = list->head;
        ptr->last = list->tail;
        list->tail = ptr;
        list->len++;
    }
}

void append(int number, LIST* list, int index)
{
    if (list == NULL)
        return;
    if (index < 0 || index > list->len) {
        puts("Invalid index!!!");
        return;
    } else if (index == 0)
        appendToBegging(number, list);
    else if (index == list->len)
        appendToBehind(number, list);
    else {
        NODE* current = malloc(sizeof(NODE));
        if (current == NULL)
            return;
        int count = 0;
        current->number = number;
        NODE* ptr = list->head;
        while (count < index) {
            ptr = ptr->next;
            count++;
        }
        current->next = ptr;
        current->last = ptr->last;
        ptr->last->next = current;
        ptr->last = current;
        list->len++;
    }
}

void deleteList(LIST* list)
{
    if (list == NULL) {
        return;
    } else if (list->len == 0) {
        puts("the list is empty");
        return;
    }

    while (list->len != 0) {
        NODE* ptr = list->head;
        if (list->len == 1) {
            list->head = NULL;
            list->tail = NULL;
            list->len--;
            free(ptr);
        } else {
            list->head = list->head->next;
            list->head->last = list->tail;
            list->tail->next = list->head;
            list->len--;
            free(ptr);
        }
    }
    free(list);
}

int сheckPallindrome(LIST* list)
{
    if (list == NULL)
        return -1;
    if (list->len <= 1) {
        return 0;
    }

    int steps = list->len / 2;

    for (int i = 0; i < steps; i++) {
        if (list->head->number != list->tail->number) {
            return -1;
        }
        list->head = list->head->next;
        list->tail = list->tail->last;
    }

    return 0;
}
