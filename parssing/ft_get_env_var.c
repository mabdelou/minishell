/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:16:07 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/30 21:31:24 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_env_copy(char *env_cp, char *env)
{
	int	i;

	if (env == NULL)
		return (NULL);
	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	env_cp = (char *) malloc(sizeof(char) * i + 1);
	i = 0;
	while (env[i] && env[i] != '=')
	{
		env_cp[i] = env[i];
		i++;
	}
	env_cp[i] = 0;
	return (env_cp);
}

char	*ft_get_env_var(char **env, char *env_var, char *home)
{
	char	**temp;
	char	*env_cp;
	int		i;

	i = 0;
	if (env == NULL || env_var == NULL)
		return (NULL);
	while (env[i])
	{
		env_cp = ft_env_copy(env_cp, env[i]);
		if (ft_strcmp(env_cp, env_var) == 0)
		{
			temp = ft_split(env[i], '=');
			ft_copy(&home, temp[1]);
			free(env_cp);
			ft_free_a(temp);
			return (home);
		}
		if (env_cp != NULL)
			free(env_cp);
		i++;
	}
	return (NULL);
}
