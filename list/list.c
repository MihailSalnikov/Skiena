#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list *search_list(list *l, int x)
{
    if (l == NULL)
        return NULL;
    if (l->item == x)
        return l;
    else
        return search_list(l->next, x);
}

void insert_list(list **l, int x)
{
    list *p;
    p = (list*) malloc(sizeof(list));
    p->item = x;
    p->next = *l;
    *l = p;
}

list *predecessor_list(list *l, int x)
{
    if ((l == NULL) || (l->next == NULL))
    {
        printf("Error: predecessor sought null list\n");
        return NULL;
    } 
    if ((l->next)->item == x)
        return l;
    else  
        return predecessor_list(l->next, x);
}

void delete_list_item(list **l, int x)
{
    list *p;
    list *pred;
    p = search_list(*l, x);
    if (p != NULL)
    {
        pred = predecessor_list(*l, x);
        if (pred == NULL) // If we want to delete first element of list
            *l = p->next;
        else
            pred->next = p->next;
        free(p);
    }
}
