/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:30:33 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:45:36 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_checker(t_stack **a)
{
	ft_revrotate(a);
}

void	rrb_checker(t_stack **b)
{
	ft_revrotate(b);

}

void	rrr_checker(t_stack **a, t_stack **b)
{
	ft_revrotate(a);
	ft_revrotate(b);
}
