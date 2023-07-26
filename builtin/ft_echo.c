/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:21:10 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/10 22:08:59 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"

int	ft_skip_n(t_mini *line, int j, int newline)
{
	char	**opt;
	int		i;

	i = 0;
	opt = line[0].opt_args;
	if (newline == 1)
	{
		while (opt && opt[j])
		{
			if (ft_strcmp("-n", opt[j]) == 0)
				j++;
			else
				return (j);
		}
	}
	return (j);
}

void	ft_echo_util_two(t_mini *line, t_echo ech)
{
	char	**opt;
	int		k;
	int		j;

	opt = line[0].opt_args;
	j = ech.newline;
	if (line[0].opt_args && ft_strcmp(line[0].opt_args[0], "-") == 0)
		j = 1;
	j = ft_skip_n(line, j, ech.newline);
	while (opt && opt[j])
	{
		k = 0;
		while (k < ech.i)
		{
			if (k == ech.i - 1)
			{
				write(ech.fds[k], opt[j], ft_strlen(opt[j]));
				if (opt[j + 1])
					write(ech.fds[k], " ", 1);
			}
			k++;
		}
		j++;
	}
	ft_newline(ech.i, ech.newline, ech.fds);
}

int	ft_check_echo_files(t_mini *line)
{
	int		stt;

	stt = ft_here_doc(line);
	if (line[0].error != NULL)
	{
		write(2, line[0].error, ft_strlen(line[0].error));
		return (write(2, "\n", 1));
	}
	stt = ft_file_in(line);
	if (stt)
		return (1);
	stt = ft_file_out(line);
	if (stt)
		return (1);
	return (0);
}

int	ft_echo(t_mini *line, t_built *g_built)
{
	t_echo	ech;

	ech.i = 0;
	if (ft_check_echo_files(line))
		return (1);
	while (line[0].std_out && line[0].std_out[ech.i] != NULL)
		ech.i++;
	ech.newline = ft_valide_opt(line[0]);
	if (ech.i != 0)
	{
		ech.fds = (int *) malloc(sizeof(int) * ech.i);
		ech.fds = ft_open_files(line, ech.fds, ech.i);
	}
	else
	{
		ech.fds = (int *) malloc(sizeof(int) * 1);
		ech.fds[0] = 1;
		ech.i = 1;
	}
	ft_echo_util(line, ech, g_built);
	free(ech.fds);
	return (0);
}
