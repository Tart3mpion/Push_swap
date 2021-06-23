#include "push_swap.h"

int	find_smallest(t_node *head, t_data *stack)
{
	t_node	*top;
	int		count;
	int		pos_min;

	top = head;
	pos_min = 0;
	count = 0;
	stack->smallest = head->data;
	while (top->next != head)
	{
		count++;
		top = top->next;
		if (top->data < stack->smallest)
		{
			stack->smallest = top->data;
			pos_min = count;
		}
	}
	return (pos_min);
}
int find_biggest(t_node *head, t_data *stack)
{
	t_node	*top;
	int		count;
	int		pos_big;

	top = head;
	pos_big = 1;
	count = 1;
	stack->biggest = top->data;
	while (count++ <= stack->size_b)
	{
		top = top->next;
		if (top->data > stack->biggest)
		{
			stack->biggest = top->data;
			pos_big = count;
		}
		
	}
	//printf("stack->biggest= %i\n", stack->biggest);
	//printf("pos_big ====> %i\n", pos_big);
	return (pos_big);
}

int	is_smaller(int nb, int n)
{
	if (nb < n)
		return (1);
	return (0);
}


