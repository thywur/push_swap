/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:40:30 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 17:40:38 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int n, ...)
{
	va_list	val;
	int		i;
	int		max;
	int		curr;

	max = INT_MIN;
	i = 0;
	va_start(val, n);
	while (i < n)
	{
		curr = va_arg(val, int);
		if (curr > max)
			max = curr;
		i++;
	}
	va_end(val);
	return (max);
}

int	ft_min(int n, ...)
{
	va_list	val;
	int		i;
	int		min;
	int		curr;

	min = INT_MAX;
	i = 0;
	va_start(val, n);
	while (i < n)
	{
		curr = va_arg(val, int);
		if (curr < min)
			min = curr;
		i++;
	}
	va_end(val);
	return (min);
}
