/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:34:33 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:11:13 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	convert_args(argc, argv, &a);
	check_vals(&a);
	if (!is_sorted(a) && ft_lstsize(a) == 2)
		sa(&a, &b);
	else if (!is_sorted(a) && ft_lstsize(a) >= 3)
		turk_sort(&a, &b);
	free_all_noerr(&a, &b);
	return (0);
}
