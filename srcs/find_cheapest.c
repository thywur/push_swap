/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:28:38 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:10:14 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*pos;
	int		pos_cost;
	int		lowest_cost;
	int		lowest_cost_val;

	pos = *a;
	lowest_cost = -1;
	while (pos)
	{
		pos_cost = get_cost(pos, directly_smaller(pos->val, b));
		if (pos_cost < lowest_cost || lowest_cost == -1)
		{
			lowest_cost = pos_cost;
			lowest_cost_val = pos->val;
		}
		pos = pos->next;
	}
	pos = *a;
	while (pos)
	{
		if (pos->val == lowest_cost_val)
			return (pos);
		pos = pos->next;
	}
	return (pos);
}

t_stack	*find_cheapest_back(t_stack **a, t_stack **b)
{
	t_stack	*pos;
	int		pos_cost;
	int		lowest_cost;
	int		lowest_cost_val;

	pos = *b;
	lowest_cost = -1;
	while (pos)
	{
		pos_cost = get_cost(pos, directly_bigger(pos->val, a));
		if (pos_cost < lowest_cost || lowest_cost == -1)
		{
			lowest_cost = pos_cost;
			lowest_cost_val = pos->val;
		}
		pos = pos->next;
	}
	pos = *b;
	while (pos)
	{
		if (pos->val == lowest_cost_val)
			return (pos);
		pos = pos->next;
	}
	return (pos);
}
