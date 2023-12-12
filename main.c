/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:34:33 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 16:43:01 by alermolo         ###   ########.fr       */
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

	if (argc < 2)
		return (0);
	// else if (check_args(argc, argv) == -1)
	// 	free_and_exit(&a, &b);
	convert_args(argc, argv, &a);
	check_vals(&a);
	// while (i < argc)
	// {
	// 	ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
	// 	i++;
	// }

	print = a;

	while (print)
	{
		printf("%d ", print->val);
		print = print->next;
	}

	printf("\n-------\n");

	// print = b;

	// while (print)
	// {
	// 	printf("%d ", print->val);
	// 	print = print->next;
	// }
	// printf("\n");
	if (!is_sorted(a))
		turk_sort(&a, &b);

	print = a;

	while (print)
	{
		printf("%d ", print->val);
		print = print->next;
	}

	// printf("\n-------\n");

	// print = b;

	// while (print)
	// {
	// 	printf("%d ", print->val);
	// 	print = print->next;
	// }
	// printf("\n");

	free_all_noerr(&a, &b);
	return (0);
}
