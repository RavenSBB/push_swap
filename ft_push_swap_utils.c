/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:31:51 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/08 15:50:56 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + sign * (str[i] - '0');
		if (INT_MAX < result || result < INT_MIN)
			return (errno = EINVAL, 0);
		i++;
	}
	return (result);
}

int	ft_is_number(char *str)
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

t_stack_node	*find_last_node(t_stack_node *first_node)
{
	if (first_node == NULL)
		return(NULL);
	while (first_node->next)
		first_node = first_node->next;
	return (first_node);
}

int	stack_length(t_stack_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	checks(char *str, t_stack_node *stack)
{
	long	result;

	if (ft_is_number(str) == 0)
		return (EXIT_FAILURE);
	result = ft_atol(str);
	if (errno)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
