/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:54:42 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/01 22:03:20 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"

int	ft_go_home(t_mini *line, t_built *g_built)
{
	char	*home;
	char	*oldpwd;
	int		stt;

	(void) line;
	stt = 0;
	home = NULL;
	home = (char *) malloc(sizeof(char) * 4096);
	oldpwd = (char *) malloc(sizeof(char) * 4096);
	home = ft_get_env_var(g_built->envp, "HOME", home);
	if (home == NULL)
	{
		free(home);
		return (1);
	}
	if (access(home, R_OK) == 0)
	{
		oldpwd = getcwd(oldpwd, 4096);
		stt = chdir(home);
	}
	ft_update_paths(g_built, oldpwd, stt);
	free(home);
	return (stt);
}

int	ft_print_error(int number, char *name)
{
	if (number == 1)
	{
		write(2, "cd: No such file or directory: ", 31);
		write(2, name, ft_strlen(name));
	}
	if (number == 2)
	{
		write(2, "cd: permission denied: ", 23);
		write(2, name, ft_strlen(name));
	}
	if (number == 3)
	{
		write(2, "cd: not a directory: ", 21);
		write(2, name, ft_strlen(name));
	}
	if (number == 4)
	{
		write(2, "cd: no such user or named directory: ", 37);
		write(2, name, ft_strlen(name));
	}
	write(1, "\n", 1);
	return (1);
}

int	ft_check_user_access(char *file, char *name, int flag)
{
	DIR		*fd;

	fd = NULL;
	if (flag == 1)
	{
		if (access(file, F_OK) != 0)
			return (ft_print_error(4, name));
		if (access(file, R_OK) != 0)
			return (ft_print_error(2, name));
	}
	return (0);
}

int	ft_check_file_access(char *file, int flag)
{
	DIR		*fd;

	fd = NULL;
	if (flag == 1)
	{
		if (access(file, F_OK) != 0)
			return (ft_print_error(1, file));
		if (access(file, R_OK) != 0)
			return (ft_print_error(2, file));
	}
	if (flag == 3)
	{
		fd = opendir(file);
		if (fd == NULL)
			return (ft_print_error(3, file));
		if (fd != NULL)
			closedir(fd);
	}
	return (0);
}

int	ft_file_in(t_mini *line)
{
	int		len;
	int		i;
	char	**tmp;

	len = 0;
	tmp = line[0].std_in;
	while (tmp && tmp[len])
		len++;
	if (len)
	{
		i = 0;
		while (i < len)
		{
			if (ft_check_file_access(tmp[i], 1) != 0)
				return (1);
			i++;
		}
		return (0);
	}
	else
		return (0);
}
