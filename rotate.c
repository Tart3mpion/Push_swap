#include "push_swap.h"

t_node	*reverse_rotate_a(t_node *a)
{
	if (a != NULL)
		a = a->prev;
	printf("rra\n");
	return (a);
}

t_node	*reverse_rotate_b(t_node *b)
{
	if (b != NULL)
		b = b->prev;
	printf("rrb\n");
	return (b);
}

t_node	*rotate_a(t_node *a)
{
	if (a != NULL)
		a = a->next;
	printf("ra\n");
	return (a);
}

t_node	*rotate_b(t_node *b)
{
	if (b != NULL)
		b = b->next;
	printf("rb\n");
	return (b);
}
