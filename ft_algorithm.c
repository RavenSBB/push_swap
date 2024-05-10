/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:27:09 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/10 16:43:03 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_number;

	biggest_number = find_biggest(*a);
	if (*a == biggest_number)
		ra(a);
	else if ((*a)->next == biggest_number)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

static void	sort_two(t_stack_node **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

static void	push_cheapest(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*to_push;

	current_position(*a);
	current_position(*b);
	set_targets(*a, *b);
	set_cost(*a, *b);
	set_cheapest(*b);
	to_push = return_cheapest(*b);
	rotate_node_to_top_a(a, to_push->target_node);
	rotate_node_to_top_b(b, to_push);
	pa(a, b);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	if (stack_length(*a) == 1)
		return ;
	while (stack_length(*a) > 3)
		pb(b, a);
	if (stack_length(*a) == 3)
		sort_three(a);
	else
		sort_two(a);
	while (stack_length(*b))
	{
		push_cheapest(a, b);
	}
	rotate_node_to_top_a(a, find_smallest(*a));
}
