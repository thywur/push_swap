/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:30:33 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/08 15:59:19 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	ft_revrotate(a);
	write(1, "rra\n", 4);
}
void	rrb(t_stack **b)
{
	ft_revrotate(b);
	write(1, "rrb\n", 4);
}
void	rrr(t_stack **a, t_stack **b)
{
	ft_revrotate(a);
	ft_revrotate(b);
	write(1, "rrr\n", 4);
}
