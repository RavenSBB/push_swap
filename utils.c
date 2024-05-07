/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:36:25 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/07 16:57:24 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if(stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if(node == NULL)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	if(*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node	*find_biggest(t_stack_node *stack)
{
	long			biggest;
	t_stack_node	*biggest_node;

	if(stack == NULL)
		return(NULL);
	biggest = LONG_MIN;
	while(stack)
	{
		if(stack->nbr > biggest)
		{
			biggest = stack->nbr;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return(biggest_node);
}

/*
t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if(stack == NULL)
		return(NULL);
	smallest = LONG_MAX;
	while(stack)
	{
		if(stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return(smallest_node);
}
*/

/*
t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if(stack == NULL)
		return(NULL);
	while(stack)
	{
		if(stack->cheapest)
			return(stack);
		stack = stack->next;
	}
	return(NULL);
}
*/
