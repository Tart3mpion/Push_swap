#include "push_swap.h"

void push_b(t_data *stack)
{
    int tmp;

    if (stack->a)
    {
        tmp = stack->a->data;
        stack->a = del_element_top(stack->a);
        stack->b = add_element_top(stack, tmp, stack->b);
        printf("pb\n");
        stack->size_a -= 1;
        stack->size_b += 1;
    }
    
}
void push_a(t_data *stack)
{
    int tmp;

    if (stack->b)
    {
        tmp = stack->b->data;
        stack->b = del_element_top(stack->b);
        stack->a = add_element_top(stack, tmp, stack->a);
        printf("pa\n");
        stack->size_b -= 1;
        stack->size_a += 1;
    }
}

//========>segfault si il  n'y a rien sur a ou b...pkoi ?