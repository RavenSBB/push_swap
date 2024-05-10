/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:04:39 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/10 16:51:23 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
#include <stdio.h>
void	ft_print_stack(t_stack_node *stack)
{
	printf("Stack: ");
	while (stack)
	{
		printf("%i", stack->nbr);
		if (stack->next)
			printf(" -> ");
		stack = stack->next;
	}
	printf("\n");
}
*/

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	a = init_stack_a(argc, argv);
	push_swap(&a, &b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
