#include "singly_linked_list.h"

List* initList()
{
    List* list = malloc(sizeof(List));
    list->len = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void deleteList(List* list)
{
    if (list == NULL)
        return;

    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
}

bool findNode(List* list, int value)
{
    if (list == NULL)
        return false;
    Node* current = list->head;
    while (current != NULL) {
        if (current->value == value)
            return true;
        current = current->next;
    }
    return false;
}

void append(List* list, int number)
{
    if (list == NULL)
        return;

    if (findNode(list, number))
        return;

    Node* new_element = malloc(sizeof(Node));
    if (new_element == NULL) {
        return;
    }

    new_element->value = number;
    new_element->next = NULL;

    if (list->len == 0) {
        list->head = new_element;
        list->tail = new_element;
    } else {
        list->tail->next = new_element;
        list->tail = new_element;
    }
    list->len++;
}

void swapNodes(Node** ptr1, Node** ptr2)
{
    Node* temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int distributionNodeArray(Node* array[], int low, int high)
{
    int pivot = array[(low + high) / 2]->value;
    int left = low - 1;
    int right = high + 1;

    while (1) {
        do {
            left++;
        } while (array[left]->value < pivot);
        do {
            right--;
        } while (array[right]->value > pivot);
        if (left >= right)
            return right;
        swapNodes(&array[left], &array[right]);
    }
}

void quickSortNodeArray(Node* array[], int low, int high)
{
    if (low < high) {
        int p = distributionNodeArray(array, low, high);
        quickSortNodeArray(array, low, p);
        quickSortNodeArray(array, p + 1, high);
    }
}

void sortList(List* list)
{
    if (list == NULL || list->len <= 1)
        return;

    Node** array = malloc(list->len * sizeof(Node*));
    if (array == NULL)
        return;

    Node* current = list->head;
    for (int i = 0; i < list->len; i++) {
        array[i] = current;
        current = current->next;
    }

    quickSortNodeArray(array, 0, list->len - 1);

    for (int i = 0; i < list->len - 1; i++) {
        array[i]->next = array[i + 1];
    }

    array[list->len - 1]->next = NULL;

    list->head = array[0];
    list->tail = array[list->len - 1];

    free(array);
}

void removeElementList(List* list, Node* node)
{
    if (list == NULL || node == NULL || list->head == NULL)
        return;
    if (list->head == node) {
        list->head = list->head->next;
        if (list->head == NULL) {
            list->tail = NULL;
        } else if (list->head->next == NULL) {
            list->tail = list->head;
        }
        free(node);
        list->len--;
        return;
    }
    Node* current = list->head;
    while (current != NULL && current->next != node) {
        current = current->next;
    }
    if (current != NULL) {
        current->next = node->next;
        if (node == list->tail) {
            list->tail = current;
        }
        free(node);
        list->len--;
    }
}

void printList(List* list)
{
    if (list == NULL)
        return;

    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

List* merge(List* list1, List* list2)
{
    if (list1 == NULL || list1->head == NULL) {
        if (list2 != NULL) {
            return list2;
        }
        return initList();
    }
    if (list2 == NULL || list2->head == NULL) {
        if (list1 != NULL) {
            return list1;
        }
        return initList();
    }

    List* result = initList();
    result->head = list1->head;

    Node* ptr1 = list1->head;
    Node* ptr2 = list2->head;
    Node* prev = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (prev != NULL) {
            prev->next = ptr1;
        }

        Node* next1 = ptr1->next;
        Node* next2 = ptr2->next;

        ptr1->next = ptr2;
        prev = ptr2;

        ptr1 = next1;
        ptr2 = next2;
    }

    if (ptr1 != NULL) {
        if (prev != NULL) {
            prev->next = ptr1;
        }
        result->tail = list1->tail;
    } else if (ptr2 != NULL) {
        if (prev != NULL) {
            prev->next = ptr2;
        }
        result->tail = list2->tail;
    } else {
        result->tail = prev;
    }

    result->len = list1->len + list2->len;

    list1->head = NULL;
    list1->tail = NULL;
    list1->len = 0;

    list2->head = NULL;
    list2->tail = NULL;
    list2->len = 0;

    return result;
}
