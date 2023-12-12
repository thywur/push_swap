/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:45:11 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 17:45:22 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_top(t_stack **a, t_stack *pos)
{
	int	r_cost;
	int	rr_cost;

	r_cost = get_r_cost(pos);
	rr_cost = get_rr_cost(pos);
	if (r_cost < rr_cost)
	{
		while (r_cost)
		{
			ra(a);
			r_cost--;
		}
	}
	else
	{
		while (rr_cost)
		{
			rra(a);
			rr_cost--;
		}
	}
}
