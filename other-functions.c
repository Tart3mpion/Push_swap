#include "push_swap.h"

void    push_back_to_a(t_data *stack)
{
	int	pos;

	pos = find_biggest(stack->b, stack);
	if (pos < (stack->chunk_size / 2))
	{
		while (pos >= 0)
		{
			reverse_rotate_b(stack->b);
			pos--;
		}
	}
	else
	{
		while (pos >= 0)
		{
			rotate_b(stack->b);
			pos--;
		}
	}
	push_a(stack);
}
void    rotation_efficiency(t_data *stack)
{
	t_node *head;
	int pos;

	head = stack->a;
	stack->chunk_size = 5;
	if (high_position(stack) > low_position(stack))
	{
		pos = low_position(stack);
		while (pos >= 0)
		{
			rotate_a(stack->a);
			pos--;
		}    
	}
	else
	{
		pos = high_position(stack);
		while (pos >= 0)
		{
			reverse_rotate_a(stack->a);
			pos--;
		}    
	}
	push_b(stack);
}
int	high_position(t_data *stack)
{
	t_node	*top;
	int		pos;
	int		count;

	top = stack->a;
	pos = 0;
	count = 0;
	while (top->next != stack->a)
	{
		if (top->index > -1 && top->index < stack->chunk_size)
		{
			pos = count;
			return (pos);
		}
		top = top->next;
		count++;
	}
	return (pos);
}

int	low_position(t_data *stack)
{
	t_node	*bottom;
	int		pos;
	int		count;

	bottom = stack->a->prev;
	pos = 0;
	count = 0;
	while (bottom->prev != stack->a)
	{
		if (bottom->index > -1 && bottom->index < stack->chunk_size)
		{
			pos = count;
			return (pos);
		}
		bottom = bottom->prev;
		count++;
	}
	return (pos);
}//