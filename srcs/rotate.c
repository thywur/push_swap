/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:24:44 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:11:34 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	if (write(1, "ra\n", 3) == -1)
		free_and_exit(a, b);
}

void	rb(t_stack **a, t_stack **b)
{
	ft_rotate(b);
	if (write(1, "rb\n", 3) == -1)
		free_and_exit(a, b);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	if (write(1, "rr\n", 3) == -1)
		free_and_exit(a, b);
}
