/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:56:26 by quentin           #+#    #+#             */
/*   Updated: 2025/03/07 13:47:31 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*temp;

	new = malloc(sizeof(t_stack));
	temp = *stack;
	if (!new)
		return ;
	new->value = value;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

t_stack	*init_stack(int argc, char **argv)
{
	int		i;
	t_stack *temp;
	t_stack	*stack;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		temp = stack;
		while(temp)
		{
			if(ft_atoi(argv[i]) == temp->value)
			{
				ft_printf("Error\n");
				free_stack(stack);
				return (1);
			}
			temp = temp->next;
		}
		stack_add_back(&stack, ft_atoi(argv[i]));
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	a = init_stack(argc, argv);
	b = NULL;
	if (stack_size(a) == 2)
		sort_two(&a);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 4)
		sort_four(&a, &b);
	else if (stack_size(a) == 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
