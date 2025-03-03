/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:20:44 by quentin           #+#    #+#             */
/*   Updated: 2025/03/03 11:50:29 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack)
{
    if (!*stack || !(*stack)->next)
        return;

    t_stack *first = *stack;
    t_stack *second = (*stack)->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

void sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}
