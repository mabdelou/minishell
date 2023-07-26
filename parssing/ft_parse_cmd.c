/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:30:38 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/30 22:04:22 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_push_std(char **std, char *token)
{
	int	len;

	len = 0;
	if (std == NULL)
	{
		std = (char **) malloc(sizeof(char *) * 2);
		std[0] = (char *) malloc(sizeof(char) * ft_strlen(token) + 1);
		ft_copy(&std[0], token);
		std[1] = NULL;
	}
	else
		std = ft_realloc(std, token);
	return (std);
}

int	ft_is_redic(char *t)
{
	int	i;

	if (t == NULL)
		return (0);
	i = ft_strlen(t);
	if (i >= 1 && t[0] == '>' && t[1] == 0)
		return (1);
	if (i >= 1 && t[0] == '<' && t[1] == 0)
		return (3);
	if (i >= 2 && t[0] == '>' && t[1] == '>' && t[2] == 0)
		return (2);
	if (i >= 2 && t[0] == '<' && t[1] == '<' && t[2] == 0)
		return (4);
	return (0);
}

t_mini	ft_parse_cmd_utili_two(t_mini *line, char **token, int index, int redi)
{
	line[0].std_out = ft_push_std(line[0].std_out, token[index + 1]);
	if (redi == 1)
	{
		line[0].trunc = ft_push_std(line[0].trunc, "t");
		line[0].f_ord = ft_push_std(line[0].f_ord, token[index + 1]);
		line[0].f_o_d = ft_push_std(line[0].f_o_d, "o");
	}
	else
	{
		line[0].trunc = ft_push_std(line[0].trunc, "f");
		line[0].f_ord = ft_push_std(line[0].f_ord, token[index + 1]);
		line[0].f_o_d = ft_push_std(line[0].f_o_d, "a");
	}
	return (line[0]);
}

t_mini	ft_parse_cmd_util(t_mini *line, char **token, int index, int redi)
{
	if (redi == 1 || redi == 2)
		line[0] = ft_parse_cmd_utili_two(line, token, index, redi);
	else if (redi == 3)
	{
		line[0].std_in = ft_push_std(line[0].std_in, token[index + 1]);
		line[0].orlim = ft_free_tab(line[0].orlim, NULL, NULL);
		line[0].order = ft_free_tab(line[0].order, NULL, NULL);
		line[0].order = ft_push_std(line[0].order, token[index + 1]);
		line[0].orlim = ft_push_std(line[0].orlim, "f");
		line[0].f_ord = ft_push_std(line[0].f_ord, token[index + 1]);
		line[0].f_o_d = ft_push_std(line[0].f_o_d, "i");
	}
	else if (redi == 4)
	{
		line[0].limiter = ft_push_std(line[0].limiter, token[index + 1]);
		line[0].orlim = ft_free_tab(line[0].orlim, NULL, NULL);
		line[0].order = ft_free_tab(line[0].order, NULL, NULL);
		line[0].order = ft_push_std(line[0].order, token[index + 1]);
		line[0].orlim = ft_push_std(line[0].orlim, "t");
	}
	return (line[0]);
}

t_mini	ft_parse_cmd(t_mini *line, char **token)
{
	int	index;
	int	redi;

	line[0].builtins = ft_geg_builtins(ft_rm_quotes(token[0]));
	if (line[0].builtins == NULL)
	{
		line[0].cmd = ft_strdup(token[0]);
		line[0].opt_args = ft_push_std(line[0].opt_args, token[0]);
	}
	index = 1;
	while (token[index])
	{
		redi = ft_is_redic(token[index]);
		if (redi)
		{
			line[0] = ft_parse_cmd_util(&line[0], token, index, redi);
			index = index + 2;
		}
		else
		{
			line[0].opt_args = ft_push_std(line[0].opt_args, token[index]);
			index++;
		}
	}
	return (line[0]);
}
