/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:25:26 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/01 21:26:20 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_error(char *file, int flag)
{
	char	*err;
	char	*tmp;

	if (flag == 1)
		tmp = ft_strdup("bash: permission denied: ");
	else
		tmp = ft_strdup("bash: no such file or directory: ");
	err = ft_strjoin(tmp, file);
	free(tmp);
	return (err);
}

int	ft_check_file_in(t_mini *line, char *file)
{
	if (access(file, F_OK) != 0)
	{
		line[0].error = ft_get_error(file, 2);
		return (1);
	}
	if (access(file, R_OK) != 0)
	{
		line[0].error = ft_get_error(file, 1);
		return (1);
	}
	return (0);
}

int	ft_check_file_out(t_mini *line, char *file)
{
	if (access(file, F_OK) == 0)
	{
		if (access(file, R_OK) != 0)
		{
			line[0].error = ft_get_error(file, 1);
			return (1);
		}
	}
	return (0);
}

void	ft_creat_file_inorder(t_mini *line, int i)
{
	int		index;
	int		fd;
	char	**tmp;
	char	**tmp1;

	index = 0;
	tmp = line[0].f_ord;
	tmp1 = line[0].f_o_d;
	while (tmp && tmp[index] && index < i)
	{
		if (tmp1[index][0] == 'o' || tmp1[index][0] == 'a')
		{
			if (access(tmp[index], F_OK) != 0)
				fd = open(tmp[index], O_CREAT, 0644);
			else if (ft_strcmp(tmp1[index], "o") == 0)
			{
				fd = open(tmp[index], O_TRUNC, 0644);
			}
			close(fd);
		}
		index++;
	}
}

void	ft_handle_order(t_mini *line)
{
	char	**order;
	char	**flag;
	int		i;
	int		rtrn;

	order = line[0].f_ord;
	flag = line[0].f_o_d;
	rtrn = 0;
	i = 0;
	while (order && order[i] && rtrn == 0)
	{
		if (flag[i] && flag[i][0] == 'i')
		{
			rtrn = ft_check_file_in(line, order[i]);
			if (rtrn)
				ft_creat_file_inorder(line, i);
		}
		else
		{
			rtrn = ft_check_file_out(line, order[i]);
			if (rtrn)
				ft_creat_file_inorder(line, i);
		}
		i++;
	}
}
