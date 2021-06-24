#include "push_swap.h"

int	is_an_integer(long int nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	return (0);
}

int	is_numeric(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if ((!(input[i] >= '0' && input[i] <= '9') && !(input[i] == '-' )))
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicate(int nb, t_node *stack)
{
	t_node	*head;

	head = stack;
	while (head->next != stack)
	{
		if (nb == head->data)
			return (1);
		head = head->next;
	}
	return (0);
}

int	is_sorted(t_data *stack)
{
	t_node	*head;

	head = stack->a;
	while (head->next != stack->a)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}
