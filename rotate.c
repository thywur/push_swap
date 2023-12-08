/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:24:44 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/08 17:08:32 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}
void	rb(t_stack **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}
void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
