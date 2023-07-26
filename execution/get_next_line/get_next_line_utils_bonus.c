/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:37:32 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/27 18:32:03 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	a;

	a = 0;
	if (s == NULL)
		return (0);
	while (s[a])
		a++;
	return (a);
}

int	return_trorfo(char *str)
{
	int	a;

	a = -1;
	if (str == NULL)
		return (1);
	while (str[++a] != '\0')
		if (str[a] == '\n')
			return (0);
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	int		b;
	int		c;
	char	*arr;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s2 == NULL)
		return (NULL);
	c = ft_strlen(s1) + ft_strlen(s2);
	a = -1;
	arr = (char *)malloc((c + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	while (s1[++a] != '\0' && a < c)
		arr[a] = s1[a];
	b = -1;
	while (s2[++b] != '\0' && (a + b) < c)
		arr[a + b] = s2[b];
	arr[a + b] = '\0';
	free(s1);
	return (arr);
}
