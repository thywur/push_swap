/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:24:44 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:46:10 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_checker(t_stack **a)
{
	ft_rotate(a);
}

void	rb_checker(t_stack **b)
{
	ft_rotate(b);
}

void	rr_checker(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);

}
