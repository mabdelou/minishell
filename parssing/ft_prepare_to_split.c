/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_to_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:08:31 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/10 22:50:08 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_whitespace_util(char *cmd, int start, int end)
{
	while (start < end)
	{
		if (cmd[start] == ' ')
		{
			cmd[start] = (char ) 128;
		}
		else if (cmd[start] == 11)
		{
			cmd[start] = (char ) 129;
		}
		start++;
	}
	return (cmd);
}

char	*ft_remove_whitespace(char *cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == 34)
		{
			j = ft_get_index_close_quote(cmd, i + 1, 34);
			cmd = ft_remove_whitespace_util(cmd, i, i + j);
			i = i + j;
		}
		else if (cmd[i] == 39)
		{
			j = ft_get_index_close_quote(cmd, i + 1, 39);
			cmd = ft_remove_whitespace_util(cmd, i, i + j);
			i = i + j;
		}
		i++;
	}
	return (cmd);
}

char	**ft_return_whitespace(char **token)
{
	int	i;
	int	j;

	i = 0;
	while (token[i])
	{
		j = 0;
		while (token[i][j])
		{
			if (token[i][j] == (char ) 128)
				token[i][j] = 32;
			else if (token[i][j] == (char ) 129)
				token[i][j] = '\t';
			j++;
		}
		i++;
	}
	return (token);
}
