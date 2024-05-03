/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:14:12 by rboits-b          #+#    #+#             */
/*   Updated: 2024/04/30 16:26:43 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	length_a;

	length_a = stack_length(*a);
	if(length_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if(length_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while(length_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while(*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while(*stack != top_node)
	{
		if(stack_name == 'a')
		{
			if(top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if(stack_name == 'b')
		{
			if(top_node->above_median)
				rrb(stack);
			else
				rrb(stack);
		}
	}
}
