/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:24:40 by quentin           #+#    #+#             */
/*   Updated: 2025/03/03 11:54:04 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(int max)
{
    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

void index_stack(t_stack *stack, int size)
{
    int *sorted = malloc(size * sizeof(int));
    t_stack *tmp = stack;
    int i = 0;
    
    while (tmp)
    {
        sorted[i++] = tmp->value;
        tmp = tmp->next;
    }
    
    for (int j = 0; j < size - 1; j++)
        for (int k = 0; k < size - j - 1; k++)
            if (sorted[k] > sorted[k + 1])
            {
                int temp = sorted[k];
                sorted[k] = sorted[k + 1];
                sorted[k + 1] = temp;
            }
    
    tmp = stack;
    while (tmp)
    {
        for (i = 0; i < size; i++)
            if (tmp->value == sorted[i])
            {
                tmp->index = i;
                break;
            }
        tmp = tmp->next;
    }
    free(sorted);
}

void radix_sort(t_stack **a, t_stack **b, int size)
{
    int max_bits = get_max_bits(size - 1);
    int i, j;
    
    for (i = 0; i < max_bits; i++)
    {
        int len = size;
        for (j = 0; j < len; j++)
        {
            if ((((*a)->index >> i) & 1) == 0)
                pb(b, a); // Pousser vers B si le bit est 0
            else
                ra(a); // Sinon, rotation
        }
        
        while (*b)
            pa(a, b); // Remettre les éléments dans A
    }
}
