/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:19:03 by quentin           #+#    #+#             */
/*   Updated: 2025/03/03 12:21:07 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				radix_sort(t_stack **a, t_stack **b, int size);
void				index_stack(t_stack *stack, int size);
int					get_max_bits(int max);
void				stack_add_back(t_stack **stack, int value);
void				print_stack(t_stack *stack, char *name);
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