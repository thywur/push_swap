/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:43:23 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/05 17:48:56 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*p;

	p = *a;
	if (p->val > p->next->val && p->val > p->next->next->val)
	{
		if (p->next->val > p->next->next->val)
		{
			sa(a);
			rra(a);
		}
		else if (p->next->val < p->next->next->val)
			ra(a);
	}
	else if (p->val > p->next->val && p->val < p->next->next->val)
		sa(a);
	else if (p->val < p->next->val && p->val > p->next->next->val)
		rra(a);
	else if (p->val < p->next->val && p->next->val > p->next->next->val)
	{
		sa(a);
		ra(a);
	}
	else
		return ;
}
