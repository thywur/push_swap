/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:43:54 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 17:48:32 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_command(t_stack *a, t_stack *b)
{
	int	cost;
	int	command;

	cost = ft_max(2, get_r_cost(a), get_r_cost(b));
	command = 1;
	if (ft_max(2, get_rr_cost(a), get_rr_cost(b)) < cost)
	{
		cost = ft_max(2, get_rr_cost(a), get_rr_cost(b));
		command = 3;
	}
	if ((get_r_cost(a) + get_rr_cost(b)) < cost)
	{
		cost = get_r_cost(a) + get_rr_cost(b);
		command = 2;
	}
	if ((get_rr_cost(a) + get_r_cost(b)) < cost)
	{
		cost = get_rr_cost(a) + get_r_cost(b);
		command = 4;
	}
	return (command);
}
