#include "quick_sort.h"

typedef struct NODE {
    int value;
    int count;
    struct NODE* next;
} Node;

typedef struct LIST {
    int len;
    Node* head;
    Node* tail;
} List;

List* initList()
{
    List* list = malloc(sizeof(List));
    list->len = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node* findNode(List* list, int value)
{
    if (list == NULL)
        return NULL;
    Node* current = list->head;
    while (current != NULL) {
        if (current->value == value)
            return current;
        current = current->next;
    }
    return NULL;
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

void insert(List* list, int number)
{
    if (list == NULL)
        return;

    Node* ptr = findNode(list, number);
    if (ptr != NULL)
        return;

    Node* new_element = malloc(sizeof(Node));
    if (new_element == NULL) {
        deleteList(list);
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

    Node** array = malloc(list->len * sizeof(Node));
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

int pop(List* list)
{
    if (list == NULL || list->len == 0)
        return -2133333331;

    int value;
    if (list->head->next == NULL) {
        value = list->head->value;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->len = 0;
        return value;
    }

    Node* current = list->head;
    while (current->next != list->tail) {
        current = current->next;
    }

    Node* ptr = list->tail;
    value = ptr->value;
    list->tail = current;
    current->next = NULL;
    list->len--;
    free(ptr);
    return value;
}

void reverse(List* list)
{
    if (list == NULL || list->len <= 1)
        return;

    list->tail = list->head;
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}
