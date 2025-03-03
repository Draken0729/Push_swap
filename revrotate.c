/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:24:32 by quentin           #+#    #+#             */
/*   Updated: 2025/03/03 11:52:50 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
    if (!*stack || !(*stack)->next)
        return;

    t_stack *prev = NULL;
    t_stack *last = *stack;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}

void rra(t_stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
