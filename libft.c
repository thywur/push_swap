/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:41:42 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/02 15:41:42 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstclear(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = ((*stack)->next);
		free(temp);
	}
	*stack = NULL;
}

int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_max(int n, ...)
{
	va_list	val;
	int		i;
	int		max;
	int		curr;

	max = INT_MIN;
	i = 0;
	va_start(val, n);
	while (i < n)
	{
		curr = va_arg(val, int);
		if (curr > max)
			max = curr;
		i++;
	}
	va_end(val);
	return (max);
}

int	ft_min(int n, ...)
{
	va_list	val;
	int		i;
	int		min;
	int		curr;

	min = INT_MAX;
	i = 0;
	va_start(val, n);
	while (i < n)
	{
		curr = va_arg(val, int);
		if (curr < min)
			min = curr;
		i++;
	}
	va_end(val);
	return (min);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
