#include "push_swap.h"

void	push_b(t_data *stack)
{
	int	tmp;

	if (stack->a)
	{
		tmp = stack->a->data;
		stack->a = del_element_top(stack->a);
		stack->b = add_element_top(stack, tmp, stack->b);
		printf("pb\n");
		stack->size_a -= 1;
		stack->size_b += 1;
	}
}

void	push_a(t_data *stack)
{
	int	tmp;

	if (stack->b)
	{
		tmp = stack->b->data;
		stack->b = del_element_top(stack->b);
		stack->a = add_element_top(stack, tmp, stack->a);
		printf("pa\n");
		stack->size_b -= 1;
		stack->size_a += 1;
	}
}

t_node	*swap_a(t_node *a)
{
	t_node	*head;
	int		tmp;

	if (a == NULL || a->next == NULL)
		return (a);
	head = a->next;
	tmp = head->data;
	head->data = a->data;
	a->data = tmp;
	printf("sa\n");
	return (a);
}

t_node	*swap_b(t_node *b)
{
	t_node	*head;
	int		tmp;

	if (b == NULL || b->next == NULL)
		return (b);
	head = b->next;
	tmp = head->data;
	head->data = b->data;
	b->data = tmp;
	printf("sb\n");
	return (b);
}
