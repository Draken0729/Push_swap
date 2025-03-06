/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:24:40 by quentin           #+#    #+#             */
/*   Updated: 2025/03/06 14:50:51 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_max(t_stack *stack)
{
    int max;

    if (!stack)
        return (0);
        
    max = stack->value;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return (max);
}

int stack_size(t_stack *stack)
{
    int size = 0;

    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int get_max_bits(t_stack *stack)
{
    int max = stack_max(stack);
    int bits = 0;

    while (max >> bits != 0)
        bits++;
    return bits;
}


void radix_sort(t_stack **a, t_stack **b)
{
    int i;
    int j;
    int size;
    int max_bits = get_max_bits(*a);

    size = stack_size(*a);

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((((*a)->value >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j++;
        }
        while (*b)
            pa(a, b);
        i++;
    }
}


