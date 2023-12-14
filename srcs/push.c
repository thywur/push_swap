/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:22:20 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:11:29 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	if (write(1, "pa\n", 3) == -1)
		free_and_exit(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	if (write(1, "pb\n", 3) == -1)
		free_and_exit(a, b);
}
