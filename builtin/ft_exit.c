/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:50:49 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/07 23:32:00 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"

int	ft_exit_util_two(t_mini *line, int len)
{
	while (line[0].opt_args && line[0].opt_args[len])
		len ++;
	if (len > 1)
	{
		write(2, "exit\nbash: exit: too many arguments\n", 36);
		return (1);
	}
	return (0);
}

int	ft_compare_first_int(char *nbr, int sign)
{
	long long int	lli;

	lli = ft_atoi_l(nbr);
	if (sign == 1 && ft_atoi_l(nbr) > 0)
		return (1);
	if (sign == 0 && ft_atoi_l(nbr) < 0)
		return (1);
	return (0);
}

int	ft_print_num_error(t_mini *line, t_built *g_built)
{
	write(2, "exit\nbash: exit: ", 17);
	write(2, line[0].opt_args[0], ft_strlen(line[0].opt_args[0]));
	write(2, ": numeric argument required\n", 28);
	g_built->end_state = 1;
	exit(255);
}

int	ft_exit_util(t_mini *line, t_built *g_built)
{
	int				i;
	int				sign;
	long long int	flag;

	flag = 0;
	sign = 0;
	i = 0;
	while (line[0].opt_args[0][i])
	{
		if (line[0].opt_args[0][0] == '-')
		{
			sign = 1;
			i++;
		}
		if (line[0].opt_args[0][i] < 48 || line[0].opt_args[0][i] > 57)
			flag = 1;
		i++;
	}
	if (flag == 0)
		flag = ft_compare_first_int(line[0].opt_args[0], sign);
	if (flag)
		ft_print_num_error(line, g_built);
	if (ft_exit_util_two(line, 0))
		return (1);
	return (ft_exit_util_tree(line, flag));
}

int	ft_exit(t_mini *line, t_built *g_built)
{
	int	len;
	int	stt;

	len = 0;
	stt = ft_here_doc(line);
	if (line[0].error != NULL)
	{
		write(2, line[0].error, ft_strlen(line[0].error));
		return (write(2, "\n", 1));
	}
	if (ft_file_in(line) || ft_file_out(line))
		return (1);
	while (line[0].opt_args && line[0].opt_args[len])
		len++;
	if (len == 0)
	{
		write(2, "exit\n", 5);
		g_built->end_state = 0;
		exit(0);
	}
	if (ft_exit_util(line, g_built))
		return (1);
	return (0);
}
