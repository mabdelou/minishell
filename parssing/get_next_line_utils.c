/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:12:12 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/17 00:24:43 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_index_of(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strchar(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (i);
		i++;
	}
	return (-1);
}

void	ft_copy_str(char **dest, char **src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[0][i] != '\0' && i + 1 < len)
	{
		dest[0][i] = src[0][i];
		i++;
	}
	dest[0][i] = '\0';
}

void	ft_concat(char **dest, char **src, int len)
{
	int	i;
	int	j;

	i = 0;
	while (dest[0][i] != '\0')
		i++;
	j = 0;
	while (src[0][j] != '\0' && i + 1 < len)
	{
		dest[0][i] = src[0][j];
		i++;
		j++;
	}
	dest[0][i] = 0;
}
