/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:24:44 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/02 15:29:39 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	ft_rotate(a);
}
void	rb(t_stack **b)
{
	ft_rotate(b);
}
void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
