/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:30:34 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:11:19 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_vals(t_stack **a)
{
	t_stack	*i;
	t_stack	*j;

	i = *a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->val == j->val)
				free_and_exit(a, NULL);
			j = j->next;
		}
		i = i->next;
	}
}

void	convert_args(int argc, char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			free_and_exit(a, NULL);
		if (ft_strisdigit(argv[i]))
			ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		else if (ft_digit_and_spc(argv[i]))
		{
			split = ft_split(argv[i]);
			j = 0;
			while (split[j])
				ft_lstadd_back(a, ft_lstnew(ft_atoi(split[j++])));
			free_split(split);
		}
		else
			free_and_exit(a, NULL);
		i++;
	}
}
