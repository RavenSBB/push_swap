/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:20 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/10 14:24:07 by rboits-b         ###   ########.fr       */
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
*/

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
		stack->index = i;
		if(i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

t_stack_node	*init_stack_a(int argc, char **argv)
{
	t_stack_node	*stack_a;
	int				i;

	stack_a = NULL;
	i = 1;
	while(i < argc)
	{
		if (checks(argv[i], stack_a))
			(ft_free_stack(stack_a),
			 write(2, "Error\n", 6), exit(EXIT_FAILURE));
		add_node(&stack_a, ft_atol(argv[i]));
		i++;
	}
	if (has_duplicates(stack_a))
		(ft_free_stack(stack_a), write(2, "Error\n", 6), exit(EXIT_FAILURE));
	return(stack_a);
}

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	length_a;
	int	length_b;

	length_a = stack_length(a);
	length_b = stack_length(b);
	while(b)
	{
		b->push_cost = b->index;
		if(!(b->above_median))
			b->push_cost = length_b - (b->index);
		if(b->target_node->above_median)
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

	if(b == NULL)
		return ;
	best_match_nbr = LONG_MAX;
	while(b)
	{
		if(b->push_cost < best_match_nbr)
		{
			best_match_nbr = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}
