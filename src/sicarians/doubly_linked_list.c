#include "doubly_linked_list.h"

List *initList()
{
    List *list = malloc(sizeof(List));
    if (list == NULL)
        return NULL;
    list->len = 0;
    list->tail = NULL;
    list->head = NULL;

    return list;
}

void printList(List *list)
{
    if (list == NULL)
        return;
    if (list->len == 0)
    {
        printf("Empty list\n");
        return;
    }
    else if (list->len == 1)
    {
        printf("%d ", list->head->number);
    }
    else
    {
        Node *current = list->head;
        int count = 0;
        while (count != list->len)
        {
            printf("%d ", current->number);
            current = current->next;
            count++;
        }
    }
}

void deleteList(List *list)
{
    if (list == NULL)
    {
        return;
    }
    Node *current = list->head;
    int count = 0;
    while (count < list->len && current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
        count++;
    }
    free(list);
}

void appendToEmptyList(List *list, Node *ptr)
{

    list->head = ptr;
    list->tail = ptr;
    ptr->next = ptr;
    ptr->last = ptr;
    list->len++;
}

void appendToBegging(int number, List *list)
{
    Node *ptr = malloc(sizeof(Node));
    if (ptr == NULL)
        return;
    ptr->number = number;
    if (list->len == 0)
    {
        appendToEmptyList(list, ptr);
    }
    else
    {
        list->tail->next = ptr;
        list->head->last = ptr;
        ptr->next = list->head;
        ptr->last = list->tail;
        list->head = ptr;
        list->len++;
    }
}

void appendToBehind(int number, List *list)
{
    Node *ptr = malloc(sizeof(Node));
    if (ptr == NULL)
        return;
    ptr->number = number;
    if (list->len == 0)
    {
        appendToEmptyList(list, ptr);
    }
    else
    {
        list->tail->next = ptr;
        list->head->last = ptr;
        ptr->next = list->head;
        ptr->last = list->tail;
        list->tail = ptr;
        list->len++;
    }
}

void append(int number, List *list, int index)
{
    if (list == NULL)
        return;
    if (index < 0 || index > list->len)
    {
        return;
    }
    else if (index == 0)
        appendToBegging(number, list);
    else if (index == list->len)
        appendToBehind(number, list);
    else
    {
        Node *current = malloc(sizeof(Node));
        if (current == NULL)
            return;
        int count = 0;
        current->number = number;
        Node *ptr = list->head;
        while (count < index)
        {
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

Node *elementSearch(List *list, int number)
{
    if (list == NULL)
        return NULL;
    Node *current = list->head;
    int count = 0;
    while (count < list->len)
    {
        if (current->number == number)
            return current;
        current = current->next;
        count++;
    }
    return NULL;
}

void elementRemoveToValue(List *list, int number)
{
    if (list == NULL)
        return;
    Node *ptr = elementSearch(list, number);
    if (ptr == NULL)
        return;
    if (list->len > 1)
    {
        ptr->last->next = ptr->next;
        ptr->next->last = ptr->last;
    }
    if (ptr == list->head)
    {
        list->head = (list->len > 1) ? ptr->next : NULL;
    }
    if (ptr == list->tail)
    {
        list->tail = (list->len > 1) ? ptr->last : NULL;
    }
    list->len--;
    free(ptr);
    if (list->len == 0)
    {
        list->head = NULL;
        list->tail = NULL;
    }
}

void elementRemoveToIndex(List *list, int index)
{
    if (list == NULL)
        return;
    if (index < 0 || index > list->len - 1)
    {
        puts("Invalid index!");
        return;
    }
    Node *ptr = list->head;
    int count = 0;
    while (count < index)
    {
        ptr = ptr->next;
        count++;
    }
    if (list->len > 1)
    {
        ptr->last->next = ptr->next;
        ptr->next->last = ptr->last;
    }
    if (ptr == list->head)
    {
        list->head = (list->len > 1) ? ptr->next : NULL;
    }
    if (ptr == list->tail)
    {
        list->tail = (list->len > 1) ? ptr->last : NULL;
    }

    list->len--;
    free(ptr);
    if (list->len == 0)
    {
        list->head = NULL;
        list->tail = NULL;
    }
}