#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct Node {
    void *value;
    struct Node *next;
} Node;

Node *node_new(void *value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void node_delete(Node *node, void (*value_free)(void *)) {
    value_free(node->value);
    free(node);
}

typedef struct LinkedList {
    Node *head;
    int size;
    int (*value_cmp)(void *, void *);
    void (*value_free)(void *);
} LinkedList;

LinkedList *list_construct(int (*value_cmp)(void *, void *), void (*value_free)(void *)) {
    LinkedList *lst = (LinkedList *) malloc(sizeof(LinkedList));
    lst->head = NULL;
    lst->size = 0;
    lst->value_cmp = value_cmp;
    lst->value_free = value_free;
    return lst;
}

void list_delete(LinkedList *lst) {
    Node *node = lst->head;
    while (node != NULL) {
        Node *next = node->next;
        node_delete(node, lst->value_free);
        node = next;
    }
    free(lst);
}

void *list_pop_left(LinkedList *lst) {
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    void *head_value = lst->head->value;
    Node *previous_head = lst->head;

    lst->head = lst->head->next;
    lst->size--;

    node_delete(previous_head, lst->value_free);

    return head_value;
}

void list_add_sorted(LinkedList *lst, void *value) {
    Node *new_node = node_new(value);
    Node *current = lst->head;
    Node *previous = NULL;

    while (current != NULL && lst->value_cmp(current->value, value) < 0) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        new_node->next = lst->head;
        lst->head = new_node;
    } else {
        previous->next = new_node;
        new_node->next = current;
    }

    lst->size++;
}