/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:01:35 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/10 14:46:33 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				length;

	length = stack_length(*stack);
	if (stack == NULL || *stack == NULL || length == 1)
		return ;
	last_node = find_last_node (*stack);
	last_node->next = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
