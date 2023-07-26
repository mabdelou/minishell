/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:15:24 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/01 22:10:36 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "../builtin/builtin.h"

int	ft_check_path(char *path)
{
	int	stt;

	stt = 0;
	if (ft_check_file_access(path, 1) == 0)
	{
		if (ft_check_file_access(path, 3) == 0)
			return (0);
	}
	return (1);
}

char	**ft_update_envp(char **envp, int i)
{
	char	*oldpwd;
	char	*pwd;

	pwd = NULL;
	oldpwd = NULL;
	pwd = (char *) malloc(sizeof(char) * 4096);
	pwd = getcwd(pwd, 4096);
	oldpwd = (char *) malloc(sizeof(char) * 4096);
	oldpwd = ft_get_env_var(envp, "PWD", oldpwd);
	while (envp && envp[++i])
	{
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
		{
			free(envp[i]);
			envp[i] = ft_strjoin("PWD=", pwd);
			free(pwd);
		}
		if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
		{
			free(envp[i]);
			envp[i] = ft_strjoin("OLDPWD=", oldpwd);
			free(oldpwd);
		}
	}
	return (envp);
}

char	**ft_update_export(char **envp, char **export, char *oldpwd)
{
	int		i;
	char	*pwd;

	pwd = (char *) malloc(sizeof(char) * 4096);
	pwd = getcwd(pwd, 4096);
	i = 0;
	if (envp == NULL || export == NULL)
		return (NULL);
	while (export[i])
	{
		if (!ft_strncmp(export[i], "PWD=", 4))
		{
			free(export[i]);
			export[i] = ft_strjoin("PWD=", pwd);
		}
		if (!ft_strncmp(export[i], "OLDPWD=", 7))
		{
			free(export[i]);
			export[i] = ft_strjoin("OLDPWD=", oldpwd);
		}
		i++;
	}
	free(pwd);
	free(oldpwd);
	return (export);
}

char	*ft_join_home_path(t_mini *line, t_built *g_built)
{
	char	*path;

	path = NULL;
	path = (char *) malloc(sizeof(char) * 4096);
	path = ft_get_env_var(g_built->envp, "HOME", path);
	path = ft_strjoin_free(path, line[0].opt_args[0] + 1);
	return (path);
}

int	ft_go_to_path(t_mini *line, t_built *g_built)
{
	char	*path;
	char	*oldpwd;
	int		stt;

	if (line[0].opt_args[0][0] == '~')
		path = ft_join_home_path(line, g_built);
	else
		path = ft_strdup(line[0].opt_args[0]);
	oldpwd = (char *) malloc(sizeof(char) * 4096);
	if (ft_check_path(path))
	{
		free(path);
		free(oldpwd);
		return (1);
	}
	oldpwd = getcwd(oldpwd, 4096);
	stt = chdir(path);
	free(path);
	ft_update_paths(g_built, oldpwd, stt);
	return (stt);
}
