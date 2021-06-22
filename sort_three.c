#include "push_swap.h"

t_node * min_is_first(t_node *a)
{
    //printf ("here");
    if (is_smaller(a->prev->data, a->next->data))
    {
        //printf("min is first !!!!\n\n");
        a = reverse_rotate_a(a);
        a = swap_a(a);
    }
    return (a);
}
t_node * min_is_last(t_node *a)
{
    if (is_smaller(a->data, a->next->data))
    {
        a = reverse_rotate_a(a); 
    }
    else
    {
        a = swap_a(a);
        a = reverse_rotate_a(a);
    }
    return (a);
}
t_node * min_is_second(t_node *a)
{
    //printf("Min is in the middle!\n");
    if (is_smaller(a->data, a->prev->data))
        a = swap_a(a);
    else
        a = rotate_a(a);
    return (a);
}
