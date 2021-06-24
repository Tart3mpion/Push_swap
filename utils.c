#include "push_swap.h"

void	print_stack(t_data *stack)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = stack->a;
	head_b = stack->b;
	if (head_a != NULL)
	{
		printf("stack_a ==>\n");
		while (head_a->next != stack->a)
		{
			printf("%i\n", head_a->data);
			head_a = head_a->next;
		}
		printf("%i\n", head_a->data);
	}
	if (head_b != NULL)
	{
		printf("stack_b ==>\n");
		while (head_b->next != stack->b)
		{
			printf("%i\n", head_b->data);
			head_b = head_b->next;
		}
		printf("%i\n", head_b->data);
	}
}

// /*  ==>scanner par le haut si on en trouve un on stocke sa position
//     ==>puis chercher un autre en commencant par le bas
//     ==>calculer lequel est le plus rapide a push
// */

void	rotation_efficiency(t_data *stack)
{
	t_node	*head;
	int		pos;

	pos = 1;
	head = stack->b;
	if (high_position(stack) > low_position(stack))
	{
		pos = low_position(stack);
		while (pos >= 1)
		{
			stack->b = reverse_rotate_b(stack->b);
			pos--;
		}
	}
	else
	{
		pos = high_position(stack);
		while (pos > 1)
		{
			stack->b = rotate_b(stack->b);
			pos--;
		}
	}
	push_a(stack);
}

int	high_position(t_data *stack)
{
	t_node	*top;
	int		pos;
	int		count;

	top = stack->b;
	pos = INT_MAX;
	count = 0;
	while (count++ <= (stack->size_b / 2))
	{
		if (top->data == stack->biggest)
		{
			pos = count;
			return (pos);
		}
		top = top->next;
	}
	return (pos);
}

int	low_position(t_data *stack)
{
	t_node	*bottom;
	int		pos;
	int		count;

	bottom = stack->b->prev;
	pos = INT_MAX;
	count = 0;
	while (count++ <= (stack->size_b / 2))
	{
		if (bottom->data == stack->biggest)
		{
			pos = count;
			return (pos);
		}
		bottom = bottom->prev;
	}
	return (pos);
}

void	push_back_to_a(t_data *stack)
{
	int	i;

	i = 0;
	while (stack->b != NULL)
	{
		find_biggest(stack->b, stack);
		rotation_efficiency(stack);
		i++;
	}
}
