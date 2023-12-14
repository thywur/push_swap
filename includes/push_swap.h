/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:59:35 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/14 15:46:46 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

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
void	sa(t_stack **a, t_stack **b);
void	sb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
t_stack	*ft_lstnew(int val);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **stack);
long	ft_atoi(const char *nptr);
void	sort_three(t_stack **a, t_stack **b);
int		ft_lstsize(t_stack *lst);
int		ft_max(int n, ...);
int		ft_min(int n, ...);
void	turk_sort(t_stack **a, t_stack **b);
int		ft_isdigit(int c);
int		ft_strisdigit(char *s);
int		ft_digit_and_spc(char *s);
char	**ft_split(char const *s);
void	free_split(char **split);
void	free_and_exit(t_stack **a, t_stack **b);
void	free_all_noerr(t_stack **a, t_stack **b);
void	check_vals(t_stack **a);
void	convert_args(int argc, char **argv, t_stack **a);
size_t	ft_strlen(const char *s);
int		is_sorted(t_stack *stack);
int		get_command(t_stack *a, t_stack *b);
void	push_to_top(t_stack **a, t_stack **b, t_stack *a_pos, t_stack *b_pos);
void	push_a_to_top(t_stack **a, t_stack **b, t_stack *pos);
t_stack	*find_smallest(t_stack **a);
t_stack	*directly_smaller(int to_place, t_stack **stack);
t_stack	*directly_bigger(int to_place, t_stack **stack);
int		get_r_cost(t_stack *pos);
int		get_rr_cost(t_stack *pos);
int		get_cost(t_stack *a, t_stack *b);
t_stack	*find_cheapest(t_stack **a, t_stack **b);
t_stack	*find_cheapest_back(t_stack **a, t_stack **b);
char	*get_next_line(int fd);
char	*get_next_line(int fd);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
void	*free_and_null(char *s);
void	sa_checker(t_stack **a);
void	sb_checker(t_stack **b);
void	ss_checker(t_stack **a, t_stack **b);
void	pa_checker(t_stack **a, t_stack **b);
void	pb_checker(t_stack **a, t_stack **b);
void	ra_checker(t_stack **a);
void	rb_checker(t_stack **b);
void	rr_checker(t_stack **a, t_stack **b);
void	rra_checker(t_stack **a);
void	rrb_checker(t_stack **b);
void	rrr_checker(t_stack **a, t_stack **b);

#endif
