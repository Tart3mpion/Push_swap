#include "push_swap.h"

void    ft_errors(t_data *stack)
{
    printf("Error\n");
    if (stack)
        free(stack);
    // if (stack->a)
    //     free()
    ///
    exit (1);
}
//=====>>needs to create a free function which will free the entire chained list.