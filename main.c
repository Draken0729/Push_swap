/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:56:26 by quentin           #+#    #+#             */
/*   Updated: 2025/03/03 12:03:23 by quentin          ###   ########.fr       */
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

void print_stack(t_stack *stack, char *name)
{
    ft_printf("Pile %s: ", name);
    while (stack)
    {
        ft_printf("%d ", stack->value);
        stack = stack->next;
    }
    ft_printf("\n");
}

t_stack *init_stack(int argc, char **argv)
{
    t_stack *stack = NULL;
    for (int i = 1; i < argc; i++)
        stack_add_back(&stack, atoi(argv[i]));
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

    print_stack(a, "A");

    index_stack(a, argc - 1);
    radix_sort(&a, &b, argc - 1);

    print_stack(a, "A (triée)");
    
    return 0;
}
