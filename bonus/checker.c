/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:03:26 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:47:10 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned long	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	check_command(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa_checker(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb_checker(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_checker(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa_checker(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb_checker(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra_checker(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb_checker(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_checker(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra_checker(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb_checker(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_checker(a, b);
	else
		free_and_exit(a, b);
}

void	parse_commands(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line && line[0] != '\n')
	{
		check_command(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

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
	parse_commands(&a, &b);
	if (b)
		write(1, "KO\n", 3);
	else if (!is_sorted(a))
		write(1, "KO\n", 3);
	else if (is_sorted(a))
		write(1, "OK\n", 3);
	free_all_noerr(&a, &b);
	return (0);
}
