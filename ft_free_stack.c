/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:16:33 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/03 18:25:36 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_free_stack(t_stack_node *stack)
{
	t_stack_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		stack = stack->next;
		free(tmp);
		tmp = stack;
	}
}
