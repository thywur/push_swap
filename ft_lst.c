/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:33:02 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 17:48:20 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*ft_lstnew(int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = *lst;
	if (*lst)
		new->next->prev = new;
	*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	last = ft_lstlast(*lst);
	if (last)
	{
		last->next = new;
		new->prev = last;
	}
	else
		*lst = new;
}
