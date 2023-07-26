/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:28:19 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 20:21:57 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_index_close_quote(char *cmd, int index, char c)
{
	int	i;

	i = 1;
	if (cmd[index] == c)
		return (1);
	while (cmd[index])
	{
		if (cmd[index] == c)
			return (i);
		i++;
		index++;
	}
	return (-1);
}

int	ft_quote_error(char *cmd, int i)
{
	int	c_q;

	i = 0;
	c_q = -1;
	while (cmd[i])
	{
		if (cmd[i] == '\"')
		{
			c_q = ft_get_index_close_quote(cmd, i + 1, 34);
			if (c_q == -1)
				return (1);
			i = i + c_q;
		}
		else if (cmd[i] == '\'')
		{
			c_q = ft_get_index_close_quote(cmd, i + 1, 39);
			if (c_q == -1)
				return (1);
			i = i + c_q;
		}
		i++;
	}
	return (0);
}

t_mini	*ft_update_num_of_pipe(t_mini *line)
{
	int	n;
	int	i;

	n = ft_number_of_pipe(line[0].fcl);
	i = 0;
	while (i < line[0].n_of_p)
	{
		line[i].n_of_p = n;
		i++;
	}
	return (line);
}

int	ft_handle_quotes(t_mini *line, char *cmd, t_built *g_built)
{
	int	i;
	int	op;

	(void) g_built;
	op = 0;
	i = 0;
	if (ft_quote_error(cmd, i) == 1)
	{
		write(2, "Error : found unclosed quote\n", 29);
		return (1);
	}
	line[0].fcl = ft_expand(line, &line[0].fcl, cmd, g_built);
	line[0].fcl = ft_between_pipes(line[0].fcl);
	line = ft_update_num_of_pipe(line);
	i = ft_strlen(line[0].fcl);
	if (i == 0)
		return (1);
	return (0);
}
