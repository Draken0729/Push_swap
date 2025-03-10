/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:07:57 by qbaret            #+#    #+#             */
/*   Updated: 2025/03/07 11:09:19 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z)
		ra(a);
	else if (x < y && y > z && x > z)
		rra(a);
	else if (x < y && y > z)
	{
		sa(a);
		ra(a);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = stack_min(*a);
	while ((*a)->value != min)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	second_min;

	min = stack_min(*a);
	second_min = stack_second_min(*a);
	while (stack_size(*a) > 3)
	{
		if ((*a)->value == min || (*a)->value == second_min)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
