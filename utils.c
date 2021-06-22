#include "push_swap.h"
long int	ft_atoli(const char *str)
{
	long int i;
	long int nb;
	int sign;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}
int	ft_atoi(const char *str)
{
	int i;
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

void print_stack(t_data *stack)
{
	// printf("youhouuu?\n");
	// printf("%p\n", head_a);
	t_node *head_a;
	t_node *head_b;

	head_a = stack->a;
	head_b = stack->b;
	//printf("here %li\n", head_a->data);
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
void stack_len(t_data *stack)
{
    t_node *head;
    
    head = stack->a;
    while (head->next != stack->a)
    {
        head = head->next;
        stack->size_a++;
    }
    stack->size_a++;
}
void put_min_to_top(t_data *stack)
{
    int pos_min;

    pos_min = find_smallest(stack->a, stack);
    while (pos_min != 0)
    {    
        if (pos_min < 2)
            stack->a = rotate_a(stack->a);
        else if (pos_min >= 2)
            stack->a = reverse_rotate_a(stack->a);   
        pos_min = find_smallest(stack->a, stack);    
    }
}