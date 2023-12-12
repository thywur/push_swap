/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:50:53 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 17:48:45 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rarb(t_stack **a, t_stack **b, t_stack *a_pos, t_stack *b_pos)
{
	while (a_pos->prev && b_pos->prev)
		rr(a, b);
	while (a_pos->prev)
		ra(a);
	while (b_pos->prev)
		rb(b);
}

static void	rarrb(t_stack **a, t_stack **b, t_stack *a_pos, t_stack *b_pos)
{
	while (a_pos->prev)
		ra(a);
	while (b_pos->prev)
		rrb(b);
}

static void	rrarrb(t_stack **a, t_stack **b, t_stack *a_pos, t_stack *b_pos)
{
	while (a_pos->prev && b_pos->prev)
		rrr(a, b);
	while (a_pos->prev)
		rra(a);
	while (b_pos->prev)
		rrb(b);
}

static void	rrarb(t_stack **a, t_stack **b, t_stack *a_pos, t_stack *b_pos)
{
	while (a_pos->prev)
		rra(a);
	while (b_pos->prev)
		rb(b);
}

void	push_to_top(t_stack **a, t_stack **b, t_stack *a_pos, t_stack *b_pos)
{
	int	command;

	command = get_command(a_pos, b_pos);
	if (command == 1)
		rarb(a, b, a_pos, b_pos);
	else if (command == 2)
		rarrb(a, b, a_pos, b_pos);
	else if (command == 3)
		rrarrb(a, b, a_pos, b_pos);
	else if (command == 4)
		rrarb(a, b, a_pos, b_pos);
	else if (command == -1)
		exit(-1);
}
