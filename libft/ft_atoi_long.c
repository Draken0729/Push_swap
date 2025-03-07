/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:40:27 by qbaret            #+#    #+#             */
/*   Updated: 2025/03/07 14:30:51 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "libft.h"

int	ft_atoi_long(const char *nptr, int *error)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] >= 9 && nptr[i] <= 13)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 &&
				-result < INT_MIN))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return ((int)result * sign);
}
