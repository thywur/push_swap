/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:20:32 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/08 14:15:46 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest(t_stack **stack)
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

int	smallest(t_stack **stack)
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
// int	get_command(t_stack *a, t_stack *b)
// {
// 	int	rarb;
// 	int	rrarrb;
// 	int	rarrb;
// 	int	rrarb;

// 	rarb = ft_max(2, get_r_cost(a), get_r_cost(b));
// 	rrarrb = ft_max(2, get_rr_cost(a), get_rr_cost(b));
// 	rarrb = get_r_cost(a) + get_rr_cost(b);
// 	rrarb = get_rr_cost(a) + get_r_cost(b);
// 	if (ft_min(4, rarb, rrarrb, rarrb, rrarb) == rarb)
// 		return (1);
// 	else if (ft_min(4, rarb, rrarrb, rarrb, rrarb) == rrarrb)
// 		return (2);
// 	else if (ft_min(4, rarb, rrarrb, rarrb, rrarb) == rarrb)
// 		return (3);
// 	else if (ft_min(4, rarb, rrarrb, rarrb, rrarb) == rrarb)
// 		return (4);
// 	return (-1);
// }

int	get_command(t_stack *st)
{
	if (ft_min(2, get_r_cost(st), get_rr_cost(st)) == get_r_cost(st))
		return (1);
	else if (ft_min(2, get_r_cost(st), get_rr_cost(st)) == get_rr_cost(st))
		return (2);
	return (-1);
}

// int	get_command_b(t_stack *b)
// {
// 	if (ft_min(2, get_r_cost(b), get_rr_cost(b)) == get_r_cost(b))
// 		return (1);
// 	else if (ft_min(2, get_r_cost(b), get_rr_cost(b)) == get_rr_cost(b))
// 		return (2);
// 	return (-1);
// }

void	push_a_to_top(t_stack **stack, t_stack *to_push)
{
	int	command;

	command = get_command(to_push);
	if (command == 1)
	{
		while(to_push->prev)
			ra(stack);
	}
	else if (command == 2)
	{
		while(to_push->prev)
			rra(stack);
	}
	if (command == -1)
		exit(-1);
}

void	push_b_to_top(t_stack **b, t_stack *to_push)
{
	int	command;

	command = get_command(to_push);
	if (command == 1)
	{
		while(to_push->prev)
			rb(b);
	}
	else if (command == 2)
	{
		while(to_push->prev)
			rrb(b);
	}
	if (command == -1)
		exit(-1);
}

t_stack *find_cheapest(t_stack **a, t_stack **b)
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
	return (NULL);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void sort_turk(t_stack **a, t_stack **b)
{
	t_stack *to_push;
	t_stack *push_to;
	t_stack	*next_val;

	pb(a, b);
	if (ft_lstsize(*a) > 3)
		pb(a, b);
	while (ft_lstsize(*a) > 3 && !is_sorted(*a))
	{
		to_push = find_cheapest(a, b);
		push_to = directly_smaller(to_push->val, b);
		push_b_to_top(b, push_to);
		push_a_to_top(a, to_push);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		next_val = directly_bigger((*b)->val, a);
		if (*a == next_val)
			pa(a, b);
		else
			push_a_to_top(a, next_val);
	}
}
