/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:30:33 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/02 15:33:20 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	ft_revrotate(a);
}
void	rrb(t_stack **b)
{
	ft_revrotate(b);
}
void	rrr(t_stack **a, t_stack **b)
{
	ft_revrotate(a);
	ft_revrotate(b);
}
