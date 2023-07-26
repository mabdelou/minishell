/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:57:29 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 17:40:59 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_free_tab(char **str, char *arg1, char *arg2)
{
	int	i;

	if (str == NULL)
		return (str);
	if (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		free(str);
	}
	if (arg1 != NULL)
		free(arg1);
	if (arg2 != NULL)
		free(arg2);
	str = NULL;
	return (str);
}

void	ft_free_util(t_mini *line, int i)
{
	if (line[i].f_cmd != NULL)
		free(line[i].f_cmd);
	line[i].f_cmd = NULL;
	if (line[i].cmd_path != NULL)
		free(line[i].cmd_path);
	line[i].cmd_path = NULL;
	if (line[i].cmd != NULL)
		free(line[i].cmd);
	line[i].cmd = NULL;
	line[i].opt_args = ft_free_tab(line[i].opt_args, NULL, NULL);
	line[i].std_in = ft_free_tab(line[i].std_in, NULL, NULL);
	line[i].std_out = ft_free_tab(line[i].std_out, NULL, NULL);
	line[i].trunc = ft_free_tab(line[i].trunc, NULL, NULL);
	line[i].limiter = ft_free_tab(line[i].limiter, NULL, NULL);
	line[i].order = ft_free_tab(line[i].order, NULL, NULL);
	line[i].orlim = ft_free_tab(line[i].orlim, NULL, NULL);
	line[i].f_ord = ft_free_tab(line[i].f_ord, NULL, NULL);
	line[i].f_o_d = ft_free_tab(line[i].f_o_d, NULL, NULL);
}

void	ft_free_cmd(t_mini *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return ;
	while (line[i].fcl != NULL)
	{
		ft_free_util(line, i);
		i++;
	}
	if (line[0].error != NULL)
		free(line[0].error);
	line[0].error = NULL;
	if (line[0].fcl != NULL)
		free(line[0].fcl);
	line[0].fcl = NULL;
}
