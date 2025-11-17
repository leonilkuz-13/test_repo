#include "singly_linked_list.h"

bool CheckIndex(List* l, int index)
{
    if (l == NULL) {
        return false;
    }
    if (l->len <= index) {
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
    List* l = malloc(sizeof(List));
    if (l == NULL) {
        return NULL;
    }
    l->head = NULL;
    l->tail = NULL;
    l->len = 0;
    return l;
}

int findIndexToInsert(List* l, int number)
{
    if (l == NULL) {
        return 0;
    }
    if (l->head == NULL) {
        return 0;
    }

    Node* ptr_find = l->head;
    int index = 0;

    while (ptr_find != NULL && ptr_find->data < number) {
        index++;
        ptr_find = ptr_find->next;
        if (ptr_find == NULL) {
            return index;
        }
    }
    return index;
}

int findIndexToRemove(List* l, int number)
{
    if (l == NULL) {
        return -1;
    }
    Node* ptr_find = l->head;
    if (ptr_find == NULL) {
        return -1;
    }
    int index = 0;
    int len = l->len;
    while (ptr_find != NULL && ptr_find->data != number) {
        if (index + 1 == len) {
            return -1;
        }
        ptr_find = ptr_find->next;
        index++;
    }
    if (ptr_find == NULL) {
        return -1;
    }
    return index;
}

void insert(int index, List* l, int number)
{
    if (l == NULL) {
        return;
    }
    if (index < 0 || index > l->len) {
        return;
    }

    Node* new_element = malloc(sizeof(Node));
    if (new_element == NULL) {
        return;
    }
    new_element->data = number;
    new_element->next = NULL;

    if (l->len == 0) {
        l->head = new_element;
        l->tail = new_element;
    } else if (index == 0) {
        new_element->next = l->head;
        l->head = new_element;
    } else if (index == l->len) {
        l->tail->next = new_element;
        l->tail = new_element;
    } else {
        Node* temp = l->head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        new_element->next = temp->next;
        temp->next = new_element;
    }
    l->len++;
}

int get(List* l, int index)
{
    if (l == NULL) {
        return -1;
    }
    if (!CheckIndex(l, index)) {
        return -1;
    }
    Node* temp = l->head;
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

void listElementRemove(List* l, int index)
{
    if (l == NULL) {
        return;
    }
    if (!CheckIndex(l, index)) {
        return;
    }

    Node* temp = l->head;
    if (temp == NULL) {
        return;
    }

    if (index == 0) {
        l->head = temp->next;
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
        if (temp1 == l->tail) {
            l->tail = temp;
        }
        free(temp1);
    }
    l->len--;
}

void printList(List* l)
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

void deleteList(List* l)
{
    if (l == NULL) {
        return;
    }
    Node* ptr = l->head;
    while (ptr != NULL) {
        Node* ptr1 = ptr;
        ptr = ptr->next;
        free(ptr1);
    }
    free(l);
}