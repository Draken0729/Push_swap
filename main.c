/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:56:26 by quentin           #+#    #+#             */
/*   Updated: 2025/03/10 10:15:37 by quentin          ###   ########.fr       */
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

int	check_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	validate_and_convert(const char *str, int *error)
{
	if (!is_valid_number(str))
	{
		*error = 1;
		return (0);
	}
	return (ft_atoi_secure(str, error));
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack;

	int i, error, value;
	stack = NULL;
	i = 1;
	while (i < argc)
	{
		error = 0;
		value = validate_and_convert(argv[i], &error);
		if (error || check_duplicate(stack, value))
		{
			ft_printf("Error\n");
			free_stack(stack);
			return (NULL);
		}
		stack_add_back(&stack, value);
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
