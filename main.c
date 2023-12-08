/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:34:33 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/06 18:32:17 by alermolo         ###   ########.fr       */
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
		// printf("%d ", ft_atoi(argv[i]));
		i++;
	}

	// pb(&a, &b);
	// pb(&a, &b);
//	sort_three(&a);
	// sa(&a);
	// rra(&a);
	print = a;

	while (print)
	{
		printf("%d ", print->val);
		print = print->next;
	}

	printf("\n-------\n");

	print = b;

	while (print)
	{
		printf("%d ", print->val);
		print = print->next;
	}
	printf("\n");

	sort_turk(&a, &b);

	print = a;

	while (print)
	{
		printf("%d ", print->val);
		print = print->next;
	}

	printf("\n-------\n");

	print = b;

	while (print)
	{
		printf("%d ", print->val);
		print = print->next;
	}
	printf("\n");

	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
