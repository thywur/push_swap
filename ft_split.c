/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:24:01 by alermolo          #+#    #+#             */
/*   Updated: 2023/12/12 16:08:54 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_get_split_size(char const *s)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]) && (ft_isspace(s[i + 1]) || s[i + 1] == '\0'))
			size++;
		i++;
	}
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned long	i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	else if (start + len > ft_strlen(s) || len > ft_strlen(s))
		len = ft_strlen(s) - start;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void	ft_fill_split(char **split, const char *s, int size)
{
	int	save;
	int	i;
	int	line_no;

	i = 0;
	line_no = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	save = i;
	while (s[i] && line_no < size)
	{
		if (i != 0 && !ft_isspace(s[i - 1]) && ft_isspace(s[i]))
		{
			split[line_no] = ft_substr(s, save, i - save);
			line_no++;
		}
		if (i != 0 && ft_isspace(s[i - 1]) && !ft_isspace(s[i]))
			save = i;
		i++;
	}
	if (i != 0 && s[i] == '\0' && !ft_isspace(s[i - 1]))
		split[line_no] = ft_substr(s, save, i);
}

char	**ft_split(char const *s)
{
	char	**split;
	int		split_size;

	if (!s)
		return (NULL);
	split_size = ft_get_split_size(s);
	split = malloc(sizeof(char *) * (split_size + 1));
	if (!split)
		return (NULL);
	ft_fill_split(split, s, split_size);
	split[split_size] = 0;
	return (split);
}
