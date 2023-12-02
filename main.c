/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:34:33 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/02 17:29:06 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	t_stack	*a;
	t_stack	*b;
	t_stack *print;

	i = 1;
	a = NULL;
	b = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		printf("%d ", ft_atoi(argv[i]));
		i++;
	}
	rra(&a);
	printf("\n-------\n");

	print = a;
	while (print)
	{
		printf("%d ", print->val);
		print = print->next;
	}


	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
