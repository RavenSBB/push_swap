/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:04:39 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/10 14:24:41 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_two(t_stack_node **a)
{
	if((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*start;
	t_stack_node	*iter;

	start = find_smallest(a);
	iter = start;
	while (iter)
	{
		if (iter->nbr > b->nbr)
			return (b->target_node = iter, (void)0);
		iter = iter->next;
	}
	iter = a;
	while (iter && iter != start)
	{
		if (iter->nbr > b->nbr)
			return (b->target_node = iter, (void)0);
		iter = iter->next;
	}
	return (b->target_node = iter, (void)0);
}

void	set_targets(t_stack_node *a, t_stack_node *b)
{
	while (b)
	{
		set_target_node(a, b);
		b = b->next;
	}
}


void	rotate_node_to_top(t_stack_node **a, t_stack_node *target_node)
{
	if (!a || !*a || !target_node)
		return ;
	if (target_node->above_median)
		while (*a != target_node)
			ra(a);
	else
		while (*a != target_node)
			rra(a);
}

void	push_cheapest(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*to_push;

	current_position(*a);
	current_position(*b);
	set_targets(*a, *b);
	set_cost(*a, *b);
	set_cheapest(*b);
	to_push = return_cheapest(*b);
	rotate_node_to_top(a, to_push->target_node);
	rotate_node_to_top(b, to_push);
	pa(a, b);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	if (stack_length(*a) == 1)
		return ;
	while (stack_length(*a) > 3)
		pb(b, a);
	//ft_print_stack(*a);
	//ft_print_stack(*b);
	if (stack_length(*a) == 3)
		sort_three(a);
	else
		sort_two(a);
	//ft_print_staprintfck(*a);
	//ft_print_stack(*b);
	while (stack_length(*b))
	{
		push_cheapest(a, b);
		//ft_print_stack(*a);
		//ft_print_stack(*b);
	}
	rotate_node_to_top(a, find_smallest(*a));
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
		

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = init_stack_a(argc, argv);
	ft_print_stack(a);
	ft_print_stack(b);
	push_swap(&a, &b);
	ft_print_stack(a);
	ft_print_stack(b);

	bool sorted = stack_sorted(a);
	if(sorted)
		write(2, "Yay!\n", 5);
	else
		write(2, "bah\n", 4);

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
