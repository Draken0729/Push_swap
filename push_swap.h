/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:19:03 by quentin           #+#    #+#             */
/*   Updated: 2025/03/06 15:02:13 by qbaret           ###   ########.fr       */
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
    int             *a;
    int             *b;
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

int                 stack_max(t_stack *stack);
int                 stack_size(t_stack *stack);
int                 get_max_bits(t_stack *stack);
void                radix_sort(t_stack **a, t_stack **b);
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