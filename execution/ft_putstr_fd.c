/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:23:28 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 21:23:31 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_header.h"
#include "../parssing/minishell.h"

static	void	print_str(char a, int fd)
{
	write(fd, &a, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	b;

	if (s != NULL)
	{
		b = 0;
		while (s[b])
		{
			print_str(s[b], fd);
			b++;
		}
	}
	write(fd, "\n", 1);
}
