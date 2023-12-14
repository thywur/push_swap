/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:17:08 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:46:35 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa_checker(t_stack **a)
{
	ft_swap(a);
}

void	sb_checker(t_stack **b)
{
	ft_swap(b);
}

void	ss_checker(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
}
