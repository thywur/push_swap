/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:22:20 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:43:00 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa_checker(t_stack **a, t_stack **b)
{
	ft_push(b, a);

}

void	pb_checker(t_stack **a, t_stack **b)
{
	ft_push(a, b);
}
