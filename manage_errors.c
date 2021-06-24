#include "push_swap.h"

void	ft_errors(t_data *stack)
{
	printf("Error\n");
	if (stack->a)
		free(stack->a);
	exit (1);
}

void	ft_free(t_data *stack)
{
	while (stack->a->next == NULL)
	{
		stack->a = stack->a->next;
		free(stack->a->prev);
		stack->a->prev = NULL;
	}
}
