/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:59:35 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/06 18:31:42 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

#include <stdio.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	ft_swap(t_stack **stack);
void	ft_push(t_stack **src, t_stack **dest);
void	ft_rotate(t_stack **stack);
void	ft_revrotate(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
t_stack	*ft_lstnew(int val);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **stack);
int		ft_atoi(const char *nptr);
void	sort_three(t_stack **a);
int		ft_lstsize(t_stack *lst);
int		ft_max(int n, ...);
int		ft_min(int n, ...);
void 	sort_turk(t_stack **a, t_stack **b);

t_stack *find_cheapest(t_stack **a, t_stack **b);

#endif
