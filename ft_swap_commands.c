/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:18:15 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/03 18:07:11 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **first_node)
{
	int	length;

	length = stack_length(*first_node);
	if(first_node == NULL || *first_node == NULL || length == 1)
		return ;
	*first_node = (*first_node)->next;
	(*first_node)->prev->prev = *first_node;
	(*first_node)->prev->next = (*first_node)->next;
	if((*first_node)->next)
		(*first_node)->next->prev = (*first_node)->prev;
	(*first_node)->next = (*first_node)->prev;
	(*first_node)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
