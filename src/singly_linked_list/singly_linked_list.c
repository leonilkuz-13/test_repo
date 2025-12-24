#include "singly_linked_list.h"

List* newList()
{
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    return list;
}

void insert(List* list, int number)
{
    if (list == NULL) {
        return;
    }

    Node* new = malloc(sizeof(Node));
    if (new == NULL) {
        return;
    }
    new->data = number;
    new->next = NULL;
    if (list->len == 0) {
        list->head = new;
        list->tail = new;
        list->len++;
        return;
    }
    if (number < list->head->data) {
        new->next = list->head;
        list->head = new;
        list->len++;
        return;
    }
    if (number > list->tail->data) {
        list->tail->next = new;
        list->tail = new;
        list->len++;
        return;
    }

    Node* ptr = list->head;
    Node* current = list->head->next;
    while (current != NULL && current->data < number) {
        ptr = current;
        current = current->next;
    }

    ptr->next = new;
    new->next = current;
    list->len++;
}

void listElementRemove(List* list, int number)
{
    if (list == NULL || list->head == NULL) {
        return;
    }
    if (list->head->data == number) {
        Node* temp = list->head;
        list->head = list->head->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
        free(temp);
        list->len--;
        return;
    }

    Node* ptr = list->head;
    Node* current = list->head->next;
    while (current != NULL && current->data != number) {
        ptr = current;
        current = current->next;
    }

    if (current != NULL) {
        ptr->next = current->next;
        if (current == list->tail) {
            list->tail = ptr;
        }
        free(current);
        list->len--;
    }
}

void printList(List* list)
{
    if (list == NULL) {
        return;
    }
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteList(List* list)
{
    if (list == NULL) {
        return;
    }
    Node* ptr = list->head;
    while (ptr != NULL) {
        Node* ptr1 = ptr;
        ptr = ptr->next;
        free(ptr1);
    }
    free(list);
}