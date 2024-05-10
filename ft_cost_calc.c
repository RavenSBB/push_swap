/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:28:12 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/10 16:52:13 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node(t_stack_node *a, t_stack_node *b)
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

void	current_position(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_length(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	length_a;
	int	length_b;

	length_a = stack_length(a);
	length_b = stack_length(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = length_b - (b->index);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += length_a - (b->target_node->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_match_nbr;
	t_stack_node	*best_match_node;

	if (b == NULL)
		return ;
	best_match_nbr = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_match_nbr)
		{
			best_match_nbr = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}
