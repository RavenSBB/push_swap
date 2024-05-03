/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:03:15 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/03 18:25:03 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_stack_node
{
	int		nbr;
	int		index;
	int		final_index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct	s_stack_node	*target_node;
	struct	s_stack_node	*next;
	struct	s_stack_node	*prev;
}	t_stack_node;

//main
int				main(int argc, char **argv);
//sorting
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
/*void			push_swap(t_stack_node **a, t_stack_node **b);*/
//push_swap_utils
void			checks(char *str, t_stack_node *stack);
//utils
long			ft_atol(char *str);
t_stack_node	*find_last_node(t_stack_node *first_node);
int				stack_length(t_stack_node *stack);
void			finish_rotation(t_stack_node **stack, t_stack_node *top_node, char stack_name);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
void			add_node(t_stack_node **stack, int nbr);
//commands
static	void	push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
static	void	rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
static	void	reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
static	void	swap(t_stack_node **first_node);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
//initialize
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			current_position(t_stack_node *stack);
t_stack_node	*init_stack_a(int argc, char **argv);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
//free stuff
void			ft_free_stack(t_stack_node *stack);
