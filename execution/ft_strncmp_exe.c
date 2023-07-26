/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_exe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:24:34 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 21:24:36 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_header.h"
#include "../parssing/minishell.h"

int	ft_strncmp_magiscule( const char *s1, const char *s2)
{
	size_t			b;
	unsigned char	*i;
	unsigned char	*k;

	if (!s1 || !s2)
		return (-1);
	i = (unsigned char *)s1;
	k = (unsigned char *)s2;
	b = 0;
	while (((i[b] == k[b]) || (i[b] == k[b] - 32)) && k[b])
		b++;
	if (i[b] == '\n')
		return (i[b + 1] - k[b]);
	return (i[b] - k[b]);
}

int	ft_strncmp_exe(const char	*s1,	const char	*s2)
{
	size_t			b;
	unsigned char	*i;
	unsigned char	*k;

	if (!s1 || !s2)
		return (1337);
	i = (unsigned char *)s1;
	k = (unsigned char *)s2;
	b = 0;
	while ((i[b] == k[b]) && k[b])
		b++;
	if (i[b] == '\n')
		return (i[b + 1] - k[b]);
	return (i[b] - k[b]);
}
