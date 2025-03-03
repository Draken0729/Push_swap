/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:24:28 by quentin           #+#    #+#             */
/*   Updated: 2025/03/03 11:51:40 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack)
{
    if (!*stack || !(*stack)->next)
        return;

    t_stack *first = *stack;
    t_stack *last = *stack;

    while (last->next)
        last = last->next;

    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void ra(t_stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
