/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:53:03 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/01 22:11:17 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "../builtin/builtin.h"

t_built	*ft_initialize_env(t_mini *line, t_built *g_built)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	while (line[0].env[i])
	{
		if (i == 0)
			str = ft_strjoin("", line[0].env[i]);
		else
			str = ft_strjoin_free(str, line[0].env[i]);
		str = ft_strjoin_free(str, "\n");
		i++;
	}
	g_built->envp = ft_split(str, '\n');
	free(str);
	i = 0;
	while (g_built->envp && g_built->envp[i])
		i++;
	g_built->num_of_env_strings = i;
	return (g_built);
}

void	ft_update_paths(t_built *g_built, char *oldpwd, int i)
{
	if (i == 0)
	{
		g_built->envp = ft_update_envp(g_built->envp, -1);
		g_built->export = ft_update_export(g_built->envp,
				g_built->export, oldpwd);
	}
	else
		free(oldpwd);
}
