#include "push_swap.h"
void	push_swap(t_data *stack)
{
	if (stack->ac - 1 == 2)
		stack->a = swap_a(stack->a);
	else if (stack->ac - 1 == 3)
		sort_three_a(stack);
	else if (stack->ac - 1 > 3 && stack->ac - 1 < 100)
		insertion_sort(stack);
	else
		quick_sort(stack);
}

void	chunk_sizes(t_data *stack)
{
	t_node	*head;

	head = stack->a;
	if (stack->size_a == 100)
		stack->chunk_size = stack->size_a / 5;
	if (stack->size_a == 500)
		stack->chunk_size = stack->size_a / 10;
}

void	sort_three_a(t_data *stack)
{
	t_node	*top;
	int		pos_min;

	top = stack->a;
	pos_min = find_smallest(stack->a, stack);
	if (pos_min == 0)
		stack->a = min_is_first(stack->a);
	else if (pos_min == 1)
		stack->a = min_is_second(stack->a);
	else
		stack->a = min_is_last(stack->a);
}

void	insertion_sort(t_data *stack)
{
	while (stack->size_a > 3)
	{
		put_min_to_top(stack);
		push_b(stack);
	}
	sort_three_a(stack);
	while (stack->b)
		push_a(stack);
}

void	quick_sort(t_data *stack)
{
	t_node	*head;
	int		nbr_chunk;
	int		max;

	head = stack->a;
	chunk_sizes(stack);
	max = stack->chunk_size;
	nbr_chunk = (stack->size_a / stack->chunk_size);
	create_index(stack);
	while (stack->size_a > 3)
	{
		create_chunk(stack, max);
		max = stack->chunk_size + max;
	}
	push_back_to_a(stack);
}
