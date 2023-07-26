/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:33:29 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/07 23:30:35 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "builtin.h"

char	*ft_replace(t_mini *line, char *path, char *var, char *srch)
{
	int	i;
	int	j;
	int	k;
	int	len;

	len = ft_strlen(srch);
	j = 0;
	i = 0;
	while (path[i])
	{
		if (ft_strncmp(path + i, srch, len) == 0)
		{
			k = 0;
			while (line[0].opt_args[1][k])
			{
				var[j++] = line[0].opt_args[1][k++];
			}
			i = i + len;
		}
		else
			var[j++] = path[i++];
	}
	var[j] = 0;
	return (var);
}

int	ft_search_and_replace(t_mini *line, char *srch, t_built *g_built)
{
	int		i;
	char	*path;
	char	*var;
	char	*oldpwd;

	i = 1;
	path = (char *) malloc(sizeof(char) * 4096);
	oldpwd = (char *) malloc(sizeof(char) * 4096);
	var = (char *) malloc(sizeof(char) * 4096);
	path = ft_get_env_var(g_built->envp, "PWD=", path);
	var = ft_replace(line, path, var, srch);
	if (ft_check_file_access(var, 1) == 0)
	{
		if (ft_check_file_access(var, 3) == 0)
		{
			oldpwd = getcwd(path, 4096);
			i = chdir(var);
		}
	}
	ft_update_paths(g_built, oldpwd, i);
	free(var);
	free(path);
	return (i);
}

int	ft_user_home_case(t_mini *line, t_built *g_built)
{
	char	**tmp;

	tmp = line[0].opt_args;
	if (ft_strcmp(tmp[0], "~-") == 0)
		return (ft_previous_dir(g_built));
	if (ft_strcmp(tmp[0], "-") == 0)
		return (ft_previous_dir(g_built));
	if (ft_strcmp(tmp[0], "--") == 0)
		return (ft_go_home(line, g_built));
	if (ft_strcmp(tmp[0], "~") == 0)
		return (ft_go_home(line, g_built));
	if (ft_strcmp(tmp[0], ".") == 0)
		return (0);
	if (tmp[0][0] == '~' && ft_strlen(tmp[0]) > 1 && tmp[0][1] != '/')
		return (ft_user_home(line, g_built));
	else
		return (ft_go_to_path(line, g_built));
	return (0);
}

int	ft_check_files(t_mini *line)
{
	int	stt;
	int	len;

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
	len = 0;
	while (line[0].opt_args && line[0].opt_args[len])
		len++;
	if (len > 2)
	{
		write(2, "cd: too many arguments\n", 23);
		return (1);
	}
	return (0);
}

int	ft_cd(t_mini *line, t_built *g_built)
{
	int	stt;
	int	len;

	if (ft_strcmp(line[0].builtins, "cd") != 0)
		return (1);
	stt = ft_check_files(line);
	if (stt)
		return (1);
	len = 0;
	while (line[0].opt_args && line[0].opt_args[len])
		len++;
	if (g_built && g_built->envp == NULL)
		ft_envdup(line, g_built, 0);
	if (len == 0)
		return (ft_go_home(line, g_built));
	if (len == 1)
		return (ft_user_home_case(line, g_built));
	else if (len == 2)
		return (ft_search_and_replace(line, line[0].opt_args[0], g_built));
	return (0);
}
