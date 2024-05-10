/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_certain_nodes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:27:39 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/10 16:49:05 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *first_node)
{
	if (first_node == NULL)
		return (NULL);
	while (first_node->next)
		first_node = first_node->next;
	return (first_node);
}

t_stack_node	*find_biggest(t_stack_node *stack)
{
	long			biggest;
	t_stack_node	*biggest_node;

	if (stack == NULL)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > biggest)
		{
			biggest = stack->nbr;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < smallest)
		{
			smallest = stack->nbr;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
