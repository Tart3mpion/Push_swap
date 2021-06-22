#include "push_swap.h"

t_node  *swap_a(t_node *a)
{
    if (a == NULL || a->next == NULL)
        return (a);
    t_node *head;
    int tmp;

    head = a->next;
    tmp = head->data;
    head->data = a->data;
    a->data = tmp;
    printf("sa\n");
    return (a);
}
t_node  *swap_b(t_node *b)
{ 
    if (b == NULL || b->next == NULL)
        return (b);
    t_node *head;
    int tmp;

    head = b->next;
    tmp = head->data;
    head->data = b->data;
    b->data = tmp;
    printf("sb\n");
    return (b);
}

//====>swap both ==> ss
