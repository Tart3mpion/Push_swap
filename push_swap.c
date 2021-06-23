#include "push_swap.h"
void    push_swap(t_data *stack)
{
    //printf("ac-1 == %i\n", stack->ac - 1);
    if (stack->ac - 1 == 2)
        stack->a = swap_a(stack->a);
    if (stack->ac -1 == 3)
        sort_three_a(stack);
    if (stack->ac -1 > 3 && stack->ac -1 < 100)
        insertion_sort(stack);
    else
    {
        sort_hundreds(stack);
        //printf("ici");
    }
}

void sort_three_a(t_data *stack)
{
    t_node *top;
    int pos_min;

    top = stack->a;
    pos_min = find_smallest(stack->a, stack);
    //printf ("stack->smallest ---> %i\n", stack->smallest);
    // printf("a->data == %i\n", a->data);
    // printf("a->next->data == %i\n", a->next->data); 
    if (pos_min == 0)//(top->data == stack->smallest)
        stack->a = min_is_first(stack->a);
    else if (pos_min == 1)//(top->next->data == stack->smallest)
        stack->a = min_is_second(stack->a);
    else
        stack->a = min_is_last(stack->a);
}

void insertion_sort(t_data *stack)
{
    while (stack->size_a > 3)
    {
        put_min_to_top(stack);
        push_b(stack);
    }
    sort_three_a(stack);
    while (stack->b)
        push_a(stack);

}

void    sort_hundreds(t_data *stack)
{
	t_node *head;
	//int i;
	int nbr_chunk;
    int max;

    
	head = stack->a;
	chunk_sizes(stack);
	//stack->chunk_size = 5;
    max = stack->chunk_size;
	nbr_chunk = (stack->size_a / stack->chunk_size);
	//printf("stack->size_a ==> %li\n", stack->size_a);
	//printf("nbr_chunk ==> %i\n", nbr_chunk);
	//printf("stack->chunk_size ==> %i\n", stack->chunk_size);
	create_index(stack);
    while (stack->size_a > 3)
    {
        //printf("stack->size_a ==> %li\n", stack->size_a);
        create_chunk(stack, max);
        max = stack->chunk_size + max;
    }
    //sort_three_a(stack);
    push_back_to_a(stack);
	//print_stack(stack);
}

void push_back_to_a(t_data *stack)
{
    int i;

    i = 0;
    while (stack->b != NULL)
    {
        //printf("stack->size_b ==> %li\n", stack->size_b);
        find_biggest(stack->b, stack);
        rotation_efficiency(stack);
        i++;
    }
    //print_stack(stack);
}

