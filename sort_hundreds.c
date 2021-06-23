#include "push_swap.h"

void    chunk_sizes(t_data *stack)
{
	t_node *head;

	head = stack->a;
	if (stack->size_a == 100)
		stack->chunk_size =  stack->size_a / 5;
	if (stack->size_a == 500)
		stack->chunk_size = stack->size_a / 11;
}

// /*  ==>scanner par le haut si on en trouve un on stocke sa position
//     ==>puis chercher un autre en commencant par le bas
//     ==>calculer lequel est le plus rapide a push
// */
void	create_chunk(t_data *stack, int max)
{
	t_node *head;
	int i;
	int pos;

	i = 0;
	pos = 1;
	head = stack->a;
	printf("head = %p\n", head);
	printf("=========> ici %i\n", max);
	while (i < stack->chunk_size)
	{
		
		// if (head->prev->index <= max)
		// {
		// 	stack->a = reverse_rotate_a(stack->a);
		// 	push_b(stack);
		// 	i++;
		// }
		pos = find_position(stack, max);
		printf ("pos == %i\n", pos);
		while (pos > 1)
		{
			stack->a = rotate_a(stack->a);
			printf ("stack->a->index == %i\n", stack->a->index);
			pos--;
		}
		//printf ("max == %i\n", max);
		push_b(stack);
		i++;
		// if (stack->size_a == 3)
		// 	break;
	}
	//print_stack(stack);
}

int	find_position(t_data *stack, int max)
{
	t_node *head;
	int count;
	int pos;

	head = stack->a;
	count = 1;
	pos = 1;
	// if (head == NULL)
	// 	return (1)
	printf("=======> ca rentre ou pas ?\n");
	while (count <= stack->size_a)
	{
		printf("head->index ===> %i\n", head->index);
		printf("max ===> %i\n", max);
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
t_node *find_lower(t_node *a, int size)
{
	t_node *min;
	t_node *lower;

	lower = a;
	min = NULL;
	while (size >= 0)
	{
		if ((!min && lower->index == -1) || (min && min->data > lower->data && 
			lower->index == -1))
			min = lower;
		//printf("min_find_lower == %p\n", min);
		lower = lower->next;
		size--;;
	}
	return (min);
}

void    create_index(t_data *stack)
{
	t_node *lower;
	t_node *tmp;

	int index;
	tmp = stack->a;
	index = 1;
	lower = find_lower(stack->a, stack->size_a);
	//printf("lower->index= %i lower data= %i\n", lower->index, lower->data);
	while (index <= stack->size_a)
	{
		tmp = tmp->next;
		lower->index = index;
		//printf("lower->index = %i\n", lower->index);
		lower = find_lower(stack->a, stack->size_a);
		//printf("lower->data= %i\n", lower->data);
		//printf("lower ==> %p\n", lower);
		index++;
		//printf("index = %i\n", index);
		
	}
	tmp = stack->a;
	int i;
	i = 0;
	while (i < 20)
	{
		printf("lower->index= %i lower data= %i\n", tmp->index, tmp->data);
		tmp = tmp->next;
		i++;
	}
}