#include "push_swap.h"

t_node	*min_is_first(t_node *a)
{
	if (is_smaller(a->prev->data, a->next->data))
	{
		a = reverse_rotate_a(a);
		a = swap_a(a);
	}
	return (a);
}

t_node	*min_is_last(t_node *a)
{
	if (is_smaller(a->data, a->next->data))
		a = reverse_rotate_a(a);
	else
	{
		a = swap_a(a);
		a = reverse_rotate_a(a);
	}
	return (a);
}

t_node	*min_is_second(t_node *a)
{
	if (is_smaller(a->data, a->prev->data))
		a = swap_a(a);
	else
		a = rotate_a(a);
	return (a);
}

void	put_min_to_top(t_data *stack)
{
	int	pos_min;

	pos_min = find_smallest(stack->a, stack);
	while (pos_min != 0)
	{
		if (pos_min < 2)
			stack->a = rotate_a(stack->a);
		else if (pos_min >= 2)
			stack->a = reverse_rotate_a(stack->a);
		pos_min = find_smallest(stack->a, stack);
	}
}
