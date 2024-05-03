/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:20 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/03 17:45:46 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_position(a);
	current_position(b);
	set_target_node(a,b);
	set_price(a,b);
	set_cheapest(b);
}

void	current_position(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if(!stack)
		return ;
	median = stack_length(stack) / 2;
	while(stack)
	{
		stack->position = i;
		if(i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}
*/

t_stack_node	*init_stack_a(int argc, char **argv)
{
	t_stack_node	*stack_a;
	int				i;

	stack_a = NULL;
	i = 1;
	while(i < argc)
	{
		//checks(argv[i], stack_a);
		add_node(&stack_a, ft_atol(argv[i]));
		i++;
	}
	return(stack_a);
}

/*
void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	length_a;
	int	length_b;

	length_a = stack_length(a);
	length_b = stack_length(b);
	while(b)
	{
		b->push_price = b->current_position;
		if(!(b->above_median))
			b->push_price = length_b - (b->current_position);
		if(b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += length_a - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if(b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while(b)
	{
		if(b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}
*/
