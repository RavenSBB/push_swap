/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:04:39 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/07 17:49:19 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_number;

	biggest_number = find_biggest(*a);
	if(*a == biggest_number)
		ra(a);
	else if((*a)->next == biggest_number)
		rra(a);
	if((*a)->nbr > (*a)->next->nbr)
		sa(a);
 }

/*void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				length_a;

	length_a = stack_length(*a);
	if(length_a <= 3)
		sort_three(a);
	while(length_a-- > 3)
		pb(b, a);
	while(*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	current_position(*a);
	smallest = find_smallest(*a);
	if(smallest->above_median)
		while(*a != smallest)
			ra(a);
	else
		while(*a != smallest)
			rra(a);
}*/

#include <stdio.h>
void	ft_print_stack(t_stack_node *stack)
{
	printf("Stack: ");
	while (stack)
	{
		printf("%i", stack->nbr);
		if (stack->next)
			printf(" -> ");
		stack = stack->next;
	}
	printf("\n");
}
		

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = init_stack_a(argc, argv);
	ft_print_stack(a);
	ft_print_stack(b);
	sort_three(&a);

	bool sorted = stack_sorted(a);
	printf("sorted: %i\n", sorted);
	if(sorted)
		printf("Yay!\n");
	else
		printf("bah\n");

	ft_free_stack(a);
	ft_free_stack(b);

	/*
	if(!stack_sorted(a))
	{
		if(stack_length(a) == 2)
			sa(&a);
		else if(stack_length(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	*/
	//free_stack(&a);
	return(0);
}
