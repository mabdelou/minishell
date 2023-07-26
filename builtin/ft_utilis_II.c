/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis_II.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:50:42 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/23 14:50:43 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

size_t	ft_strlen_to(const char *str, char a)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != a && str[i] != '\0')
		i++;
	return (i);
}

int	ft_iseagal(char *str)
{
	int	a;

	a = -1;
	if (!str)
		return (0);
	while (str[++a])
		if (str[a] == 61)
			return (a);
	return (0);
}

int	ft_strncmp_built(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' && s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	if (i == n && (unsigned char)s2[i] == '\0')
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isalpha(int a, int loop)
{
	char	c;

	c = (unsigned char )a;
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || a == '_')
	{
		return (1);
	}
	else if (loop != 0 && (a >= 48 && a <= 57))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	**ft_bzero(char **st, size_t len)
{
	size_t	i;
	size_t	a;

	a = 0;
	i = len;
	if (!st)
		return (NULL);
	while (a < i)
	{
		st[a] = NULL;
		a++;
	}
	return (st);
}
