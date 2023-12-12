/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:56:10 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 16:16:37 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	write(1, "Error\n", 6);
	exit(-1);
}

void	free_all_noerr(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
