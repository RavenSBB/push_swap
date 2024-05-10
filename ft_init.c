/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:26:30 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/10 16:40:33 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_number(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(t_stack_node *a)
{
	t_stack_node	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->nbr == temp->nbr)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

static int	checks(char *str, t_stack_node *stack)
{
	long	result;

	if (ft_is_number(str) == 0)
		return (EXIT_FAILURE);
	result = ft_atol(str);
	if (errno)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	add_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->cheapest = false;
	node->next = NULL;
	node->nbr = nbr;
	if (*stack == NULL)
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

t_stack_node	*init_stack_a(int argc, char **argv)
{
	t_stack_node	*stack_a;
	int				i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (checks(argv[i], stack_a))
			(ft_free_stack(stack_a),
				write(2, "Error\n", 6), exit(EXIT_FAILURE));
		add_node(&stack_a, ft_atol(argv[i]));
		i++;
	}
	if (has_duplicates(stack_a))
		(ft_free_stack(stack_a), write(2, "Error\n", 6), exit(EXIT_FAILURE));
	return (stack_a);
}
