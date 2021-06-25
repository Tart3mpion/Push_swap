#include "push_swap.h"

int	main(int ac, char **argv)
{
	t_data	*stack;

	stack = NULL;
	if (ac < 2)
		return (-1);
	stack = init_stack(stack, ac, argv);
	push_swap(stack);
	ft_free(stack);
	return (0);
}
