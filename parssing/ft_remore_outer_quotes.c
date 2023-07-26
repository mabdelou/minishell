/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remore_outer_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:36:00 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/10 17:44:55 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_q(char **cmd, int *j, int k, char c)
{
	c = 39;
	if (cmd[0][j[0]] == 34)
		c = 34;
	j[0]++;
	while (cmd[0][j[0]] && cmd[0][j[0]] != c)
	{
		cmd[0][k] = cmd[0][j[0]];
		j[0]++;
		k++;
	}
	if (cmd[0][j[0]] == 0)
		cmd[0][k] = 0;
	return (k);
}

char	**ft_remove_quotes(char **cmds)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (cmds[i])
	{
		j = 0;
		k = 0;
		while (cmds[i][j])
		{
			if (cmds[i][j] == 34 || cmds[i][j] == 39)
				k = ft_handle_q(&cmds[i], &j, k, cmds[i][j]);
			else
			{
				cmds[i][k] = cmds[i][j];
				k++;
			}
			j++;
		}
		cmds[i][k] = 0;
		i++;
	}
	return (cmds);
}
