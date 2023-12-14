/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:17:08 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:11:40 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **a, t_stack **b)
{
	ft_swap(a);
	if (write(1, "sa\n", 3) == -1)
		free_and_exit(a, b);
}

void	sb(t_stack **a, t_stack **b)
{
	ft_swap(b);
	if (write(1, "sb\n", 3) == -1)
		free_and_exit(a, b);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	if (write(1, "ss\n", 3) == -1)
		free_and_exit(a, b);
}
