#include "singly_linked_list.h"

bool checkIndex(List* list, int index)
{
    if (list == NULL) {
        return false;
    }
    if (list->len <= index) {
        puts("index is greater than array length!!");
        return false;
    }
    if (index < 0) {
        puts("the item is not the list!!");
        return false;
    }
    return true;
}

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

int findIndexToInsert(List* list, int number)
{
    if (list == NULL) {
        return 0;
    }
    if (list->head == NULL) {
        return 0;
    }

    Node* ptr = list->head;
    int index = 0;

    while (ptr != NULL && ptr->data < number) {
        index++;
        ptr = ptr->next;
        if (ptr == NULL) {
            return index;
        }
    }
    return index;
}

int findIndexToRemove(List* list, int number)
{
    if (list == NULL) {
        return -1;
    }
    Node* ptr = list->head;
    if (ptr == NULL) {
        return -1;
    }
    int index = 0;
    int len = list->len;
    while (ptr != NULL && ptr->data != number) {
        if (index + 1 == len) {
            return -1;
        }
        ptr = ptr->next;
        index++;
    }
    if (ptr == NULL) {
        return -1;
    }
    return index;
}

void insert(int index, List* list, int number)
{
    if (list == NULL) {
        return;
    }
    if (index < 0 || index > list->len) {
        return;
    }

    Node* newElement = malloc(sizeof(Node));
    if (newElement == NULL) {
        return;
    }
    newElement->data = number;
    newElement->next = NULL;

    if (list->len == 0) {
        list->head = newElement;
        list->tail = newElement;
    } else if (index == 0) {
        newElement->next = list->head;
        list->head = newElement;
    } else if (index == list->len) {
        list->tail->next = newElement;
        list->tail = newElement;
    } else {
        Node* temp = list->head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newElement->next = temp->next;
        temp->next = newElement;
    }
    list->len++;
}

int get(List* list, int index)
{
    if (list == NULL) {
        return -1;
    }
    if (!checkIndex(list, index)) {
        return -1;
    }
    Node* temp = list->head;
    if (temp == NULL) {
        return -1;
    }
    for (int i = 0; i < index; i++) {
        if (temp == NULL) {
            return -1;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        return -1;
    }
    return temp->data;
}

void listElementRemove(List* list, int index)
{
    if (list == NULL) {
        return;
    }
    if (!checkIndex(list, index)) {
        return;
    }

    Node* temp = list->head;
    if (temp == NULL) {
        return;
    }

    if (index == 0) {
        list->head = temp->next;
        list->tail = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++) {
            if (temp == NULL) {
                return;
            }
            temp = temp->next;
        }

        if (temp == NULL) {
            return;
        }
        Node* temp1 = temp->next;
        if (temp1 == NULL) {
            return;
        }
        temp->next = temp1->next;
        if (temp1 == list->tail) {
            list->tail = temp;
        }
        free(temp1);
    }
    list->len--;
}

void printList(List* list)
{
    if (list == NULL) {
        return;
    }
    Node* temp = list->head;
    int len = list->len;
    for (int i = 0; i < len; i++) {
        if (temp == NULL) {
            return;
        }
        printf("%d ", temp->data);
        temp = temp->next;
    }
    void printList(List * l)
    {
        if (l == NULL) {
            return;
        }
        Node* temp = l->head;
        int len = l->len;
        for (int i = 0; i < len; i++) {
            if (temp == NULL) {
                return;
            }
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
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