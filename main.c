/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:56:26 by quentin           #+#    #+#             */
/*   Updated: 2025/03/06 15:02:07 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_add_back(t_stack **stack, int value)
{
    t_stack *new = malloc(sizeof(t_stack));
    t_stack *temp = *stack;

    if (!new)
        return;
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

t_stack *init_stack(int argc, char **argv)
{
    int i;
    
    t_stack *stack = NULL;
    
    i = 1;
    while (i < argc)
    {
        stack_add_back(&stack, ft_atoi(argv[i]));
        i++;
    }
    return stack;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_printf("Usage: ./push_swap num1 num2 num3 ...\n");
        return 1;
    }

    t_stack *a = init_stack(argc, argv);
    t_stack *b = NULL;
    
    radix_sort(&a, &b);
    
    return 0;
}
