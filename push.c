/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:24:35 by quentin           #+#    #+#             */
/*   Updated: 2025/03/03 11:52:12 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack **from, t_stack **to)
{
    if (!*from)
        return;

    t_stack *temp = *from;
    *from = (*from)->next;  // Avancer dans la pile source
    temp->next = *to;       // Lier l'élément au sommet de la destination
    *to = temp;             // Mettre à jour la tête de la destination
}

void pa(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}
