#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct List
{
    Node* tail;
    Node* head;
    int len;
} List;

bool indexCorrectness(List* l, int index)
{
    if (l->len <= index)
    {
        puts("index is greater than array length!!");
        return false;
    }
    if (index < 0)
    {
        puts("the item is not the list!!");
        return false;
    }
    return true;
}

bool indexCorrectnessToInsert(List* l, int index)
{
    if (l->len < index)
    {
        puts("index is greater than array length!!");
        return false;
    }
    if (index < 0)
    {
        puts("the item is not the list!!");
        return false;
    }
    return true;
}

List* newList()
{
    List* l = malloc(sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    l->len = 0;
    return l;
}

int findIndexToInsert(List* l, int digit)
{
    Node* ptr_find = l->head;
    if (ptr_find == NULL)
        return 0;
    int index = 0;
    int len = l->len;
    while (ptr_find->data < digit)
    {
        if (index + 1 == len)
        {
            return index + 1;
            break;
        }
        index++;
        ptr_find = ptr_find->next;
    }
    return index;
}

int findIndexToRemove(List* l, int digit)
{
    Node* ptr_find = l->head;
    int index = 0;
    int len = l->len;
    while (ptr_find->data != digit)
    {
        if (index + 1 == len)
        {
            return -1;
        }
        ptr_find = ptr_find->next;
        index++;
    }
    return index;
}

void insert(int index, List* l, int digit)
{
    if (!indexCorrectnessToInsert(l, index))
        return;

    Node* new_element = malloc(sizeof(Node));
    new_element->data = digit;

    if (l->len == 0)
    {
        new_element->next = NULL;
        l->head = new_element;
        l->tail = new_element;
    }

    else if (index == 0)
    {
        new_element->next = l->head;
        l->head = new_element;
    }

    else if (index == l->len)
    {
        new_element->next = NULL;
        l->tail->next = new_element;
        l->tail = new_element;
    }

    else
    {
        Node* temp = l->head;
        for (size_t i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        new_element->next = temp->next;
        temp->next = new_element;
    }
    l->len++;
}

int get(List* l, int index)
{
    if (!indexCorrectness(l, index))
        return -1;
    Node* temp = l->head;
    for (size_t i = 0; i < index; i++)
        temp = temp->next;
    return temp->data;
}

void listElementRemove(List* l, int index)
{
    if (!indexCorrectness(l, index))
        return;

    Node* temp = l->head;

    if (index == 0)
    {
        l->head = temp->next;
        free(temp);
    }

    else
    {
        for (size_t i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        Node* temp1 = temp->next;
        temp->next = temp1->next;
        if (temp1 == l->tail)
            l->tail = temp;
        free(temp1);
    }
    l->len--;
}

void printList(List* l)
{
    Node* temp = l->head;
    int len = l->len;
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

void Exit(List* l)
{
    Node* ptr = l->head;
    while (ptr != NULL)
    {
        Node* ptr1 = ptr;
        ptr = ptr->next;
        free(ptr1);
    }

    free(l);
}
