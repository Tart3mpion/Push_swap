#include "push_swap.h"

void	create_chunk(t_data *stack, int max)
{
	t_node	*head;
	int		i;
	int		pos;

	i = 0;
	pos = 1;
	head = stack->a;
	while (i < stack->chunk_size)
	{
		pos = find_position(stack, max);
		while (pos > 1)
		{
			stack->a = rotate_a(stack->a);
			pos--;
		}
		push_b(stack);
		i++;
	}
}

int	find_position(t_data *stack, int max)
{
	t_node	*head;
	int		count;
	int		pos;

	head = stack->a;
	count = 1;
	pos = 1;
	while (count <= stack->size_a)
	{
		if (head->index <= max)
		{
			pos = count;
			return (pos);
		}
		head = head->next;
		count++;
	}
	return (pos);
}

t_node	*find_lower(t_node *a, int size)
{
	t_node	*min;
	t_node	*lower;

	lower = a;
	min = NULL;
	while (size >= 0)
	{
		if ((!min && lower->index == -1) || (min && min->data > lower->data
				&& lower->index == -1))
			min = lower;
		lower = lower->next;
		size--;
	}
	return (min);
}

void	create_index(t_data *stack)
{
	t_node	*lower;
	t_node	*tmp;
	int		index;

	tmp = stack->a;
	index = 1;
	lower = find_lower(stack->a, stack->size_a);
	while (index <= stack->size_a)
	{
		tmp = tmp->next;
		lower->index = index;
		lower = find_lower(stack->a, stack->size_a);
		index++;
	}
}
