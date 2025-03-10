/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:19:03 by quentin           #+#    #+#             */
/*   Updated: 2025/03/10 10:20:47 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>

typedef struct s_stack
{
	int				*a;
	int				*b;
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					is_valid_number(const char *str);
int					ft_atoi_secure(const char *str, int *error);
int					check_int(int argc, char **argv);
void				free_stack(t_stack *stack);
void				sort_five(t_stack **a, t_stack **b);
void				sort_four(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
void				sort_two(t_stack **a);
int					stack_max(t_stack *stack);
int					stack_second_min(t_stack *stack);
int					stack_min(t_stack *stack);
int					stack_size(t_stack *stack);
int					get_max_bits(t_stack *stack);
void				radix_sort(t_stack **a, t_stack **b);
void				stack_add_back(t_stack **stack, int value);
t_stack				*init_stack(int argc, char **argv);
void				push(t_stack **from, t_stack **to);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				rotate(t_stack **stack);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				swap(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

#endif