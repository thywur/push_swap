/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:46:20 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/08 13:40:03 by alermolo         ###   ########.fr       */
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

	if (!(*src))
		return ;
	to_push = *src;
	if (!(*dest))
	{
		*src = to_push->next;
		(*src)->prev = NULL;
		to_push->next = NULL;
		*dest = to_push;
	}
	else if (to_push)
	{
		*src = to_push->next;
		if (*src)
			(*src)->prev = NULL;
		to_push->next = *dest;
		to_push->prev = NULL;
		(*dest)->prev = to_push;
		*dest = to_push;
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
