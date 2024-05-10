/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:27:58 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/10 16:50:39 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_node_to_top_a(t_stack_node **a, t_stack_node *target_node)
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

void	rotate_node_to_top_b(t_stack_node **b, t_stack_node *target_node)
{
	if (!b || !*b || !target_node)
		return ;
	if (target_node->above_median)
		while (*b != target_node)
			rb(b);
	else
		while (*b != target_node)
			rrb(b);
}
