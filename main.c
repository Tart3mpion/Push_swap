#include "push_swap.h"

int main(int ac, char **argv)
{
	t_data *stack;

	stack = NULL;
	if (ac < 2)
		return (-1); //==>est ce que s'il y a un seul parametre avec des erreurs on doit retourner error
	stack = init_stack(stack, ac, argv);
	//create_index(stack);
	print_stack(stack);
	push_swap(stack);
	//chunk_sizes(stack);
	//min_is_first(stack->a);
	//stack->a = min_is_last(stack->a);
	
	//puts("arguments apres ==>\n");
	//rotation_efficiency(stack);
	//print_stack(stack);
	//ft_free();
  
	return (0);
}
