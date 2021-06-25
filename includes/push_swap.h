#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_data
{
	t_node		*a;
	t_node		*b;
	int			i;
	int			ac;
	int			smallest;
	int			biggest;
	long int	size_a;
	long int	size_b;
	int			chunk_size;
	int			*chunk;
}				t_data;

int		main(int ac, char **argv);

/*check_inputs*/
int		is_numeric(char *input);
int		is_an_integer(long int nb);
int		is_duplicate(int nb, t_node *stack);
int		is_sorted(t_data *stack);

/*manage_errors*/
void	ft_errors(t_data *stack);
void	ft_free(t_data *stack);

/*initialization*/
t_data	*init_stack(t_data *stack, int ac, char **argv);
void	fill_stack(t_data *stack, char **argv);
t_node	*add_element_end(t_data *stack, int nb, t_node *head);
t_node	*add_element_top(t_data *stack, int nb, t_node *head);
t_node	*del_element_top(t_node *stack);

/*utils*/
void	print_stack(t_data *stack);
void	rotation_efficiency(t_data *stack);
int		low_position(t_data *stack);
int		high_position(t_data *stack);

/*actions*/
t_node	*swap_a(t_node *a);
t_node	*swap_b(t_node *b);
t_node	*rotate_a(t_node *a);
t_node	*rotate_b(t_node *b);
t_node	*reverse_rotate_a(t_node *a);
t_node	*reverse_rotate_b(t_node *b);
void	push_b(t_data *stack);
void	push_a(t_data *stack);

/*compare*/
int		find_smallest(t_node *head, t_data *stack);
int		find_biggest(t_node *head, t_data *stack);
int		is_smaller(int nb, int n);

/*push_swap*/
void	push_swap(t_data *stack);
void	sort_three_a(t_data *stack);
void	insertion_sort(t_data *stack);
void	quick_sort(t_data *stack);
void	chunk_sizes(t_data *stack);

/*sort_three*/
t_node	*min_is_first(t_node *a);
t_node	*min_is_second(t_node *a);
t_node	*min_is_last(t_node *a);
void	put_min_to_top(t_data *stack);

/*quick_sort*/
t_node	*find_lower(t_node *a, int size);
void	create_index(t_data *stack);
void	create_chunk(t_data *stack, int max);
void	push_back_to_a(t_data *stack);
int		find_position(t_data *stack, int max);

#endif