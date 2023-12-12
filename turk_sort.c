/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:20:32 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 18:02:09 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_stack **a, t_stack **b)
{
	t_stack	*to_push;
	t_stack	*push_to;

	if (ft_lstsize(*a) == 4)
		pb(a, b);
	else if (ft_lstsize(*a) > 4)
	{
		pb(a, b);
		pb(a, b);
	}
	while (ft_lstsize(*a) > 3 && !is_sorted(*a))
	{
		to_push = find_cheapest(a, b);
		push_to = directly_smaller(to_push->val, b);
		push_to_top(a, b, to_push, push_to);
		pb(a, b);
	}
	sort_three(a, b);
	while (*b)
	{
		push_to = directly_bigger((*b)->val, a);
		push_a_to_top(a, b, push_to);
		pa(a, b);
	}
	push_a_to_top(a, b, find_smallest(a));
}
