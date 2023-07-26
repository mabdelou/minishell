/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_between_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:29:41 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 17:12:37 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_index_of_next_pipe(char *fcl, int i)
{
	int	len;

	len = 0;
	if (fcl[i] == '|')
		return (1);
	while (fcl[i] && (fcl[i] == '\t' || fcl[i] == ' '))
	{
		i++;
		len++;
	}
	if (fcl[i] == 0 || fcl[i] == '|')
	{
		if (fcl[i] == 0)
			return (-len);
		return (len);
	}
	return (0);
}

char	*ft_override_between_pipe(char *fcl, int i, int l)
{
	while (fcl[l])
	{
		fcl[i] = fcl[l];
		l++;
		i++;
	}
	fcl[i] = 0;
	return (fcl);
}

char	*ft_between_pipes(char *fcl)
{
	int	i;
	int	l;

	i = 0;
	while (fcl[i])
	{
		if (fcl[i] == '|')
		{
			l = ft_index_of_next_pipe(fcl, i + 1);
			if (l != 0)
			{
				if (l < 0)
					fcl[i] = 0;
				else
					fcl = ft_override_between_pipe(fcl, i, i + l);
				i = 0;
			}
			else
				i++;
		}
		else
			i++;
	}
	return (fcl);
}
