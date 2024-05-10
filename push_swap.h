/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:03:15 by rboits-b          #+#    #+#             */
/*   Updated: 2024/05/10 16:56:42 by rboits-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_stack_node
{
	int						nbr;
	int						index;
	int						final_index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

/* FILE ft_push_commands.c */
static void		push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

/* FILE ft_swap_commands.c */
static void		swap(t_stack_node **first_node);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

/* FILE ft_rotate_commands.c */
static void		rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

/* FILE ft_reverse_rotate_commands.c */
static void		reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

/* FILE ft_init.c */
static int		ft_is_number(char *str);
static int		has_duplicates(t_stack_node *a);
static int		checks(char *str, t_stack_node *stack);
static void		add_node(t_stack_node **stack, int nbr);
t_stack_node	*init_stack_a(int argc, char **argv);

/* FILE ft_algorithm.c */
static void		sort_three(t_stack_node **a);
static void		sort_two(t_stack_node **a);
static void		push_cheapest(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);

/* FILE ft_utils.c */
long			ft_atol(char *str);
int				stack_length(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

/* FILE ft_find_certain_nodes.c */
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_biggest(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *first_node);
t_stack_node	*return_cheapest(t_stack_node *stack);

/* FILE ft_rotate_to_top.c */
void			rotate_node_to_top_a(t_stack_node **a,
					t_stack_node *target_node);
void			rotate_node_to_top_b(t_stack_node **b,
					t_stack_node *target_node);

/* FILE ft_cost_calc.c */
void			current_position(t_stack_node *stack);
static void		set_target_node(t_stack_node *a, t_stack_node *b);
void			set_targets(t_stack_node *a, t_stack_node *b);
void			set_cost(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);

/* FILE ft_free_stack.c */
void			ft_free_stack(t_stack_node *stack);

#endif
