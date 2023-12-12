/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:11:57 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 17:12:51 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_r_cost(t_stack *pos)
{
	int	cost;

	cost = 0;
	if (pos)
	{
		while (pos->prev)
		{
			cost++;
			pos = pos->prev;
		}
	}
	return (cost);
}

int	get_rr_cost(t_stack *pos)
{
	int	cost;

	cost = 0;
	if (pos)
	{
		while (pos->next)
		{
			cost++;
			pos = pos->next;
		}
		cost++;
	}
	return (cost);
}

int	get_cost(t_stack *a, t_stack *b)
{
	int	rarb;
	int	rrarrb;
	int	rarrb;
	int	rrarb;

	rarb = ft_max(2, get_r_cost(a), get_r_cost(b));
	rrarrb = ft_max(2, get_rr_cost(a), get_rr_cost(b));
	rarrb = get_r_cost(a) + get_rr_cost(b);
	rrarb = get_rr_cost(a) + get_r_cost(b);
	return (ft_min(4, rarb, rrarrb, rarrb, rrarb));
}
