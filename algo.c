/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:24:40 by quentin           #+#    #+#             */
/*   Updated: 2025/03/07 13:48:36 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = stack_max(stack);
	bits = 0;
	while (max >> bits != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	max_bits = get_max_bits(*a);
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
