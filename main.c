
#include <stdio.h>
#include "linkedlist.h"

int main()
{
    LinkedList *lst = list_construct();

    list_add_left(lst, 3);
    list_add_left(lst, 1);
    list_add_left(lst, 5);
    list_add_left(lst, 7);
    list_add_left(lst, -2);

    list_print(lst);
    printf("\n");

    list_delete(lst);

    return 0;
}