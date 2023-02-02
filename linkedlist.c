
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node *node_construct(int value, Node *next)
{
    Node *node = (Node *)calloc(1, sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

void node_delete(Node *node)
{
    free(node);
}

LinkedList *list_construct()
{
    LinkedList *lst = (LinkedList *)calloc(1, sizeof(LinkedList));
    lst->head = NULL;
    lst->size = 0;
    return lst;
}

void list_add_left(LinkedList *lst, int value)
{
    lst->head = node_construct(value, lst->head);
    lst->size++;
}

int list_pop_left(LinkedList *lst)
{
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    int head_value = lst->head->value; //add o próximo valor na lista
    Node *previous_head = lst->head;                  //posição atual da list

    lst->head = lst->head->next; // aqui aparece o valor atualizado no nó
    lst->size--; // após isso é decrementado op valor

    node_delete(previous_head); // o nó mais antigo é removido da pilha

    return head_value;
}

int list_get_left(LinkedList *lst)
{
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    return lst->head->value;
}

void list_print(LinkedList *lst)
{
    Node *it = lst->head;

    while (it != NULL)
    {
        printf("%d ", it->value);
        it = it->next;
    }
}
void list_add_sorted(LinkedList *lst, int value) {
    Node *new_node = node_new(value);
    Node *current = lst->head;
    Node *previous = NULL;

    while (current != NULL && current->value < value) {
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

void list_delete(LinkedList *lst)
{
    // do not use lst->size in the loop below becasue
    // pop_left decrease size.
    int size = lst->size;

    for (int i = 0; i < size; i++)
        list_pop_left(lst);

    free(lst);
}