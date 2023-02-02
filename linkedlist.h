
#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} LinkedList;

Node *node_construct(int value, Node *next);
void node_delete(Node *node);

LinkedList *list_construct();
void list_add_left(LinkedList *lst, int value);
int list_pop_left(LinkedList *lst);
int list_get_left(LinkedList *lst);
void list_print(LinkedList *lst);
void list_delete(LinkedList *lst);

#endif
