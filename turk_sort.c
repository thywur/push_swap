/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:20:32 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/11 15:08:39 by alermolo         ###   ########.fr       */
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

// int	get_command(t_stack *st)
// {
// 	if (ft_min(2, get_r_cost(st), get_rr_cost(st)) == get_r_cost(st))
// 		return (1);
// 	else if (ft_min(2, get_r_cost(st), get_rr_cost(st)) == get_rr_cost(st))
// 		return (2);
// 	return (-1);
// }

int	get_command(t_stack *a, t_stack *b)
{
	// int	rarb;
	// int	rrarrb;
	// int	rarrb;
	// int	rrarb;
	int cost;
	int command;

	cost = ft_max(2, get_r_cost(a), get_r_cost(b));
	command = 1;
	if (ft_max(2, get_rr_cost(a), get_rr_cost(b)) < cost)
	{
		cost = ft_max(2, get_rr_cost(a), get_rr_cost(b));
		command = 3;
	}
	if ((get_r_cost(a) + get_rr_cost(b)) < cost)
	{
		cost = get_r_cost(a) + get_rr_cost(b);
		command = 2;
	}
	if ((get_rr_cost(a) + get_r_cost(b)) < cost)
	{
		cost = get_rr_cost(a) + get_r_cost(b);
		command = 4;
	}
	return (command);
	// if (get_r_cost(a) <= get_cost(a, b))
	// {
	// 	if (get_r_cost(b) <= get_cost(a, b))
	// 		return (1);
	// 	else
	// 		return (2);
	// }
	// else
	// {
	// 	if (get_rr_cost(b) <= get_cost(a, b))
	// 		return (3);
	// 	else
	// 		return (4);
	// }
	// return (-1);

	// rarb = ft_max(2, get_r_cost(a), get_r_cost(b));
	// rrarrb = ft_max(2, get_rr_cost(a), get_rr_cost(b));
	// rarrb = get_r_cost(a) + get_rr_cost(b);
	// rrarb = get_rr_cost(a) + get_r_cost(b);
	// return (ft_min(4, rarb, rrarrb, rarrb, rrarb));
}

void	push_a_to_top(t_stack **a, t_stack *next_big)
{
	int	moves;
	int	r_moves;

	moves = get_r_cost(next_big);
	r_moves = get_rr_cost(next_big);
	if (moves < r_moves)
	{
		while (moves)
		{
			ra(a);
			moves--;
		}
	}
	else
	{
		while (r_moves)
		{
			rra(a);
			r_moves--;
		}
	}
}

// void	push_b_to_top(t_stack **b, t_stack *to_push)
// {
// 	int	command;

// 	command = get_command(to_push);
// 	if (command == 1)
// 	{
// 		while (to_push->prev)
// 			rb(b);
// 	}
// 	else if (command == 2)
// 	{
// 		while (to_push->prev)
// 			rrb(b);
// 	}
// 	if (command == -1)
// 		exit(-1);
// }

void	push_to_top(t_stack **a, t_stack **b, t_stack *a_pos, t_stack *b_pos)
{
	int	command;

	command = get_command(a_pos, b_pos);
	if (command == 1)
	{
		while (a_pos->prev && b_pos->prev)
			rr(a, b);
		while (a_pos->prev)
			ra(a);
		while (b_pos->prev)
			rb(b);
	}
	else if (command == 2)
	{
		while (a_pos->prev)
			ra(a);
		while (b_pos->prev)
		{
			// printf("b_pos should be: %d\n", b_pos->val);
			// t_stack *head;
			// head = *b;
			// while (head)
			// {
			// 	if (head->prev)
			// 		printf("prev content: %d\n", head->prev->val);
			// 	printf("content: %d\n", head->val);
			// 	head = head->next;
			// }
			rrb(b);
		}
	}
	else if (command == 3)
	{
		while (a_pos->prev && b_pos->prev)
			rrr(a, b);
		while (a_pos->prev)
			rra(a);
		while (b_pos->prev)
			rrb(b);
	}
	else if (command == 4)
	{
		while (a_pos->prev)
			rra(a);
		while (b_pos->prev)
			rb(b);
	}
	else if (command == -1)
		exit(-1);
}

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

void	turk_sort(t_stack **a, t_stack **b)
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
		// push_b_to_top(b, push_to);
		// push_a_to_top(a, to_push);
		push_to_top(a, b, to_push, push_to);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		next_val = directly_bigger((*b)->val, a);
		// printf("next val %d\n", next_val->val);
		push_a_to_top(a, next_val);
		pa(a, b);
		// printf("*a == %d\n", (*a)->val);

		// if (get_r_cost(next_val) > get_rr_cost(next_val))
		// 	rra(a);
		// else
		// 	ra(a);
		// if (*a == next_val)
		// 	pa(a, b);
		// else
		// {
		// 	push_to_top(b, a, *b, next_val);
		// 	pa(a, b);
		// }
	}
	push_a_to_top(a, find_smallest(a));
}
