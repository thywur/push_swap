/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:46:20 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/02 17:05:26 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	int		temp;
	t_stack	*top;

	top = *stack;
	if (top)
	{
		temp = top->val;
		top->val = top->next->val;
		top->next->val = temp;
	}
}

void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*to_push;

	to_push = *src;
	if (!src || !dest)
		return ;
	if (to_push)
	{
		to_push->next = *dest;
		to_push->prev = NULL;
		*dest = to_push;
		*src = (*src)->next;
		(*src)->prev = NULL;
	}
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;

	top = *stack;
	last = ft_lstlast(*stack);
	*stack = top->next;
	last->next = top;
	top->prev = last;
	top->next = NULL;
	(*stack)->prev = NULL;
}

void	ft_revrotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;

	top = *stack;
	last = ft_lstlast(*stack);
	last->next = top;
	top->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack = last;
}
