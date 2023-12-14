/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:43:23 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:11:37 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a, t_stack **b)
{
	t_stack	*p;

	p = *a;
	if (p->val > p->next->val && p->val > p->next->next->val)
	{
		if (p->next->val > p->next->next->val)
		{
			sa(a, b);
			rra(a, b);
		}
		else if (p->next->val < p->next->next->val)
			ra(a, b);
	}
	else if (p->val > p->next->val && p->val < p->next->next->val)
		sa(a, b);
	else if (p->val < p->next->val && p->val > p->next->next->val)
		rra(a, b);
	else if (p->val < p->next->val && p->next->val > p->next->next->val)
	{
		sa(a, b);
		ra(a, b);
	}
	else
		return ;
}
