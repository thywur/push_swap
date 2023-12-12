/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:30:33 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 17:55:53 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, t_stack **b)
{
	ft_revrotate(a);
	if (write(1, "rra\n", 4) == -1)
		free_and_exit(a, b);
}

void	rrb(t_stack **a, t_stack **b)
{
	ft_revrotate(b);
	if (write(1, "rrb\n", 4) == -1)
		free_and_exit(a, b);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_revrotate(a);
	ft_revrotate(b);
	if (write(1, "rrr\n", 4) == -1)
		free_and_exit(a, b);
}
