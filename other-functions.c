#include "push_swap.h"

// void    push_back_to_a(t_data *stack)
// {
// 	int	pos;

// 	pos = find_biggest(stack->b, stack);
// 	if (pos < (stack->chunk_size / 2))
// 	{
// 		while (pos >= 0)
// 		{
// 			reverse_rotate_b(stack->b);
// 			pos--;
// 		}
// 	}
// 	else
// 	{
// 		while (pos >= 0)
// 		{
// 			rotate_b(stack->b);
// 			pos--;
// 		}
// 	}
// 	push_a(stack);
// }
void    rotation_efficiency(t_data *stack)
{
	t_node *head;
	int pos;

	pos = 1;
	head = stack->b;
	//print_stack(stack);
	//printf("high_position(stack) ==> %i\n", high_position(stack));
	//printf("low_position(stack) ==> %i\n", low_position(stack));
	if (high_position(stack) > low_position(stack))
	{
		pos = low_position(stack);
		//printf("low_position %i\n", pos);
		while (pos >= 1)
		{
			stack->b = reverse_rotate_b(stack->b);
			pos--;
		}    
	}
	else
	{
		pos = high_position(stack);
		//printf("high_position %i\n", pos);
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
		//printf("===========> la ");
		if (top->data == stack->biggest)
		{
			pos = count;
			//printf("count ==> %i\n", count);
			
			return (pos);
		}
		top = top->next;
		//printf("pos_high ==> %i\n", pos);
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
		//printf("===========> lalala ");
		if (bottom->data == stack->biggest)
		{
			pos = count;
			return (pos);
		}
		bottom = bottom->prev;
	}
	//printf("pos_low ==> %i\n", pos);
	return (pos);
}