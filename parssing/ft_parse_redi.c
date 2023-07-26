/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_redi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:37 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/06 12:07:20 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	*ft_parse_redi_util_two(t_mini *line, char **token, int index)
{
	line[0].std_out = ft_push_std(line[0].std_out, token[index + 1]);
	if (line[0].redi == 1)
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
	return (line);
}

t_mini	*ft_parse_redi_util(t_mini *line, char **token, int index)
{
	if ((line[0].redi == 1 || line[0].redi == 2) && token[index + 1])
		line = ft_parse_redi_util_two(line, token, index);
	else if (line[0].redi == 3 && token[index + 1])
	{
		line[0].std_in = ft_push_std(line[0].std_in, token[index + 1]);
		line[0].orlim = ft_free_tab(line[0].orlim, NULL, NULL);
		line[0].order = ft_free_tab(line[0].order, NULL, NULL);
		line[0].order = ft_push_std(line[0].order, token[index + 1]);
		line[0].orlim = ft_push_std(line[0].orlim, "f");
		line[0].f_ord = ft_push_std(line[0].f_ord, token[index + 1]);
		line[0].f_o_d = ft_push_std(line[0].f_o_d, "i");
	}
	else if (line[0].redi == 4 && token[index + 1])
	{
		line[0].limiter = ft_push_std(line[0].limiter, token[index + 1]);
		line[0].orlim = ft_free_tab(line[0].orlim, NULL, NULL);
		line[0].order = ft_free_tab(line[0].order, NULL, NULL);
		line[0].order = ft_push_std(line[0].order, token[index + 1]);
		line[0].orlim = ft_push_std(line[0].orlim, "t");
	}
	return (line);
}

t_mini	ft_parse_redi(t_mini *line, char **token, int j)
{
	int	index;

	index = 0;
	while (token[index])
	{
		line[0].redi = ft_redirection(token[index]);
		if (line[0].redi != 0)
		{
			line = ft_parse_redi_util(&line[0], token, index);
			index = index + 2;
		}
		else
		{
			if (j >= 3 && index == 2)
			{
				line[0].cmd = ft_strdup(token[index]);
				line[0].opt_args = ft_push_std(line[0].opt_args, token[index]);
			}
			else
				line[0].opt_args = ft_push_std(line[0].opt_args, token[index]);
			index++;
		}
	}
	return (line[0]);
}

int	ft_redirection(char *cmd)
{
	if (ft_strncmp(">>", cmd, 2) == 0)
	{
		return (2);
	}
	else if (ft_strncmp("<<", cmd, 2) == 0)
	{
		return (4);
	}
	else if (ft_strncmp(">", cmd, 1) == 0)
	{
		return (1);
	}
	else if (ft_strncmp("<", cmd, 1) == 0)
	{
		return (3);
	}
	return (0);
}

int	ft_parse(t_mini **line, int i, char *cmd, char **env)
{
	char	**token;
	int		j;
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(cmd);
	tmp = ft_add_space_besides(tmp);
	tmp = ft_remove_whitespace(tmp);
	token = ft_split_str(tmp, " \t");
	free(tmp);
	token = ft_return_whitespace(token);
	token = ft_remove_quotes(token);
	j = 0;
	while (token[j])
		j++;
	if (ft_redirection(token[0]))
		line[0][i] = ft_parse_redi(&line[0][i], token, j);
	else if (j >= 1)
		line[0][i] = ft_parse_cmd(&line[0][i], token);
	if (line[0][i].cmd != NULL)
		line[0][i] = ft_get_cmd_path(&line[0][i], env);
	ft_free_a(token);
	return (0);
}
