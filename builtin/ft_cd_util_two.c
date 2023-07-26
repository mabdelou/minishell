/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:39:31 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/01 22:16:23 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"

int	ft_file_out(t_mini *line)
{
	int		len;
	int		i;
	int		fd;

	fd = 0;
	len = 0;
	while (line[0].std_out && line[0].std_out[len])
		len++;
	if (len)
	{
		i = -1;
		while (++i < len)
		{
			if (access(line[0].std_out[i], F_OK) != 0)
				fd = open(line[0].std_out[i],
						O_CREAT | O_RDWR | O_APPEND, 0644);
			else if (access(line[0].std_out[i], R_OK) != 0)
				ft_print_error(2, line[0].std_out[i]);
			else if (line[0].trunc[i][0] == 't')
				fd = open(line[0].std_out[i], O_TRUNC, 0644);
			if (fd > 2)
				close(fd);
		}
	}
	return (0);
}

void	ft_heredoc_util(char *g_line, char *lim)
{
	while (g_line != NULL)
	{
		free(g_line);
		g_line = NULL;
		g_line = readline("heredoc> ");
		if (ft_strcmp(g_line, lim) == 0)
		{
			free(g_line);
			g_line = NULL;
		}
	}
}

int	ft_here_doc(t_mini *line)
{
	char	*lim;
	char	*g_line;
	int		len;

	g_line = NULL;
	len = 0;
	while (line[0].limiter && line[0].limiter[len])
		len++;
	if (len != 0)
	{
		lim = line[0].limiter[len - 1];
		g_line = readline("heredoc> ");
		if (ft_strcmp(g_line, lim) == 0)
		{
			free(g_line);
			g_line = NULL;
			return (0);
		}
		ft_heredoc_util(g_line, lim);
	}
	return (0);
}

int	ft_previous_dir(t_built *g_built)
{
	char	*var;
	char	*oldpwd;
	int		stt;

	var = NULL;
	var = (char *) malloc(sizeof(char) * 4096);
	oldpwd = (char *) malloc(sizeof(char) * 4096);
	var = ft_get_env_var(g_built->envp, "OLDPWD", var);
	if (var == NULL)
	{
		free(var);
		return (1);
	}
	if (ft_check_file_access(var, 1) != 0)
		return (1);
	else
	{
		oldpwd = getcwd(oldpwd, 4096);
		stt = chdir(var);
		if (stt == 0)
			printf("%s\n", var);
		ft_update_paths(g_built, oldpwd, stt);
	}
	free(var);
	return (stt);
}

int	ft_user_home(t_mini *line, t_built *g_built)
{
	char	*var;
	char	*oldpwd;
	int		i;
	int		j;

	var = (char *) malloc(sizeof(char) * 4096);
	oldpwd = (char *) malloc(sizeof(char) * 4096);
	var = ft_get_env_var(g_built->envp, "HOME", var);
	i = ft_strlen(var);
	while (var[i - 1] != '/')
		i--;
	j = 1;
	while (line[0].opt_args[0][j])
		var[i++] = line[0].opt_args[0][j++];
	var[i] = 0;
	if (ft_check_user_access(var, line[0].opt_args[0], 1) == 0)
	{
		oldpwd = getcwd(oldpwd, 4096);
		j = chdir(var);
		ft_update_paths(g_built, oldpwd, j);
	}
	free(var);
	return (j);
}
