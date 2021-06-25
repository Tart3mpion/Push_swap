#include "push_swap.h"

t_data	*init_stack(t_data *stack, int ac, char **argv)
{
	stack = (t_data *)malloc(sizeof(t_data));
	if (stack == NULL)
		exit(1);
	stack->a = NULL;
	stack->b = NULL;
	stack->chunk = NULL;
	stack->ac = ac;
	stack->i = 1;
	stack->size_a = stack->ac - 1;
	stack->size_b = 0;
	stack->chunk_size = 0;
	fill_stack(stack, argv);
	return (stack);
}

void	fill_stack(t_data *stack, char **argv)
{
	while (stack->i < (stack->ac))
	{
		if (is_numeric(argv[stack->i])
			|| (is_an_integer(ft_atoli(argv[stack->i]))
				|| ft_strlen(argv[stack->i]) == 0))
			ft_errors(stack);
		stack->a = add_element_end(stack, ft_atoi(argv[stack->i]), stack->a);
		stack->a->index = -1;
		if (is_duplicate(ft_atoi(argv[stack->i]), stack->a))
			ft_errors(stack);
		stack->i++;
	}
	if (is_sorted(stack))
	{
		ft_free(stack);
		exit(0);
	}		
}

t_node	*add_element_end(t_data *stack, int nb, t_node *head)
{
	t_node	*tmp;

	tmp = NULL;
	if (head != NULL)
	{
		tmp = (t_node *)malloc(sizeof(t_node));
		if (tmp == NULL)
			ft_errors(stack);
		tmp->next = head;
		tmp->prev = head->prev;
		head->prev = tmp;
		tmp->prev->next = tmp;
		tmp->data = nb;
		tmp->index = -1;
	}
	else
	{
		head = (t_node *)malloc(sizeof(t_node));
		if (head == NULL)
			ft_errors(stack);
		head->next = head;
		head->prev = head;
		head->data = nb;
	}
	return (head);
}

t_node	*add_element_top(t_data *stack, int nb, t_node *head)
{
	t_node	*tmp;

	tmp = NULL;
	if (head != NULL)
	{
		tmp = (t_node *)malloc(sizeof(t_node));
		if (tmp == NULL)
			ft_errors(stack);
		tmp->next = head;
		tmp->prev = head->prev;
		head->prev = tmp;
		tmp->prev->next = tmp;
		tmp->data = nb;
		head = head->prev;
	}
	else
	{
		head = (t_node *)malloc(sizeof(t_node));
		if (head == NULL)
			ft_errors(stack);
		head->next = head;
		head->prev = head;
		head->data = nb;
	}
	return (head);
}

t_node	*del_element_top(t_node *head)
{
	t_node	*tmp;

	tmp = NULL;
	if (head->next == head)
	{
		free(head);
		head = NULL;
	}
	else
	{
		tmp = head;
		head = tmp->next;
		tmp->prev->next = head;
		head->prev = tmp->prev;
		free(tmp);
	}
	return (head);
}
