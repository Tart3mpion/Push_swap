#include "push_swap.h"

void	ft_errors(t_data *stack)
{
	printf("Error\n");
	if (stack->a)
		ft_free(stack);
	exit (1);
}

void	free_stack(t_node *top)
{
	t_node	*head;
	t_node	*tofree;

	if (top)
	{
		head = top->next;
		while (head->next != top)
		{
			tofree = head;
			head = head->next;
			free(tofree);
			tofree = NULL;
		}
		free(head);
	}
}

void	ft_free(t_data *stack)
{
	if (stack)
	{
		if (stack->a)
			free_stack(stack->a);
		if (stack->b)
			free_stack(stack->b);
		free(stack);
	}
}
