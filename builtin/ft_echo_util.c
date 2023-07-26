/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:59:58 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/06 22:31:01 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"

void	ft_newline(int i, int newline, int *fds)
{
	int	k;

	if (newline == 0)
	{
		k = 0;
		while (k < i)
		{
			if (k == i - 1)
				write(fds[k], "\n", 1);
			if (fds[k] > 3)
				close(fds[k]);
			k++;
		}
	}
}

int	ft_valide_opt(t_mini line)
{
	int		i;
	char	*opt;

	if (line.opt_args == NULL)
		return (0);
	opt = line.opt_args[0];
	i = 0;
	if (opt == NULL)
		return (0);
	if (opt[i] == '-' && opt[i + 1] == 0)
		return (0);
	if (opt[i] == '-')
	{
		i++;
		while (opt[i] == 'n')
			i++;
		if (opt[i] == '\0')
			return (1);
	}
	return (0);
}

int	*ft_open_files(t_mini *line, int *fds, int index)
{
	int		i;
	char	**tmp;
	char	**tmp1;

	i = 0;
	tmp = line[0].std_out;
	tmp1 = line[0].trunc;
	while (i < index)
	{
		if (access(tmp[i], F_OK) != 0)
		{
			if (tmp1[i][0] == 't')
				fds[i]
					= open(tmp[i], O_CREAT | O_TRUNC | O_RDWR | O_APPEND, 0644);
			else
				fds[i] = open(tmp[i], O_CREAT | O_RDWR | O_APPEND, 0644);
		}
		else
			fds[i] = open(tmp[i], O_CREAT | O_RDWR | O_APPEND, 0644);
		i++;
	}
	return (fds);
}

int	ft_echo_util(t_mini *line, t_echo ech, t_built *g_built)
{
	int		j;

	(void) g_built;
	j = 0;
	while (line[0].opt_args && line[0].opt_args[j])
		j++;
	if (j == 0)
		return (write(1, "\n", 1));
	else if (j == 1 && ech.newline == 1)
		return (0);
	ft_echo_util_two(line, ech);
	return (0);
}
