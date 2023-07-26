/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:53:22 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 01:27:24 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_copy_env(char *env, char *cmd, int j, int len)
{
	int	i;

	if (cmd[j] >= '0' && cmd[j] <= '9')
	{
		env[0] = cmd[j];
		env[1] = 0;
		return (env);
	}
	i = 0;
	while (i < len)
	{
		env[i] = cmd[j];
		i++;
		j++;
	}
	env[i] = 0;
	return (env);
}

char	*ft_get_env(char *cmd, int i)
{
	int		j;
	int		len;
	char	*env;

	len = 0;
	j = i;
	if (cmd[i] == '?')
		len = 1;
	else
	{
		while (cmd[i] && (ft_is_alpha_digit(cmd[i])
				|| cmd[i] == 63 || cmd[i] == 95))
		{
			len++;
			i++;
		}
	}
	env = (char *) malloc(sizeof(char) * len + 1);
	i = 0;
	env = ft_copy_env(env, cmd, j, len);
	return (env);
}

char	*ft_get_env_val(char *env_n, char **env)
{
	int		i;
	int		len;
	char	*env_cp;

	len = ft_strlen(env_n);
	i = -1;
	if (ft_strncmp(env_n, "path", 4) == 0)
	{
		while (++i < 4)
			env_n[i] = env_n[i] - 32;
	}
	i = 0;
	while (env[i])
	{
		env_cp = ft_env_copy(env_cp, env[i]);
		if (ft_strcmp(env_n, env_cp) == 0)
		{
			free(env_cp);
			return (&env[i][len + 1]);
		}
		if (env_cp != NULL)
			free(env_cp);
		i++;
	}
	return (NULL);
}

int	ft_exp_check(char c)
{
	if (c == '+' || c == '=' || c == 0
		|| c == '$')
		return (0);
	return (1);
}
