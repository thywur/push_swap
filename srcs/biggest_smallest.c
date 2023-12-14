/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_smallest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:03:46 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:10:05 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	biggest(t_stack **stack)
{
	int		max;
	t_stack	*pos;

	max = INT_MIN;
	pos = *stack;
	while (pos)
	{
		if (pos->val > max)
			max = pos->val;
		pos = pos->next;
	}
	return (max);
}

static int	smallest(t_stack **stack)
{
	int		min;
	t_stack	*pos;

	min = INT_MAX;
	pos = *stack;
	while (pos)
	{
		if (pos->val < min)
			min = pos->val;
		pos = pos->next;
	}
	return (min);
}

t_stack	*find_smallest(t_stack **a)
{
	t_stack	*curr;
	int		min;

	curr = *a;
	min = smallest(a);
	while (curr->next)
	{
		if (curr->val == min)
			return (curr);
		curr = curr->next;
	}
	return (curr);
}

t_stack	*directly_smaller(int to_place, t_stack **stack)
{
	int		min;
	t_stack	*pos;

	min = to_place + 1;
	pos = *stack;
	while (pos)
	{
		if (pos->val < to_place && (pos->val > min || min == to_place + 1))
			min = pos->val;
		pos = pos->next;
	}
	if (min == to_place + 1)
		min = biggest(stack);
	pos = *stack;
	while (pos)
	{
		if (pos->val == min)
			return (pos);
		pos = pos->next;
	}
	return (NULL);
}

t_stack	*directly_bigger(int to_place, t_stack **stack)
{
	int		max;
	t_stack	*pos;

	max = to_place - 1;
	pos = *stack;
	while (pos)
	{
		if (pos->val > to_place && (pos->val < max || max == to_place - 1))
			max = pos->val;
		pos = pos->next;
	}
	if (max == to_place - 1)
		max = smallest(stack);
	pos = *stack;
	while (pos)
	{
		if (pos->val == max)
			return (pos);
		pos = pos->next;
	}
	return (NULL);
}
