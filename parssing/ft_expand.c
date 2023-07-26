/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:00:38 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 01:00:59 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_expand(char *env_name, char **env)
{
	char	*env_val;

	env_val = NULL;
	env_val = ft_get_env_val(env_name, env);
	if (env_val == NULL)
		return (NULL);
	return (env_val);
}

char	*ft_expand_util_two(t_built *g_built, int *flag, char *exp)
{
	flag[0] = 1;
	if (WIFSIGNALED(g_built->end_state))
		exp = ft_itoa(WTERMSIG(g_built->end_state) + 128);
	else
		exp = ft_itoa(WEXITSTATUS(g_built->end_state));
	return (exp);
}

int	ft_expand_util(t_mini *line, char **fcl, char *cmd, t_built *g_built)
{
	char	*exp;
	char	*v_exp;
	int		flag;

	exp = NULL;
	(void) line;
	flag = 0;
	if (g_built->envp == NULL)
		g_built = ft_initialize_env(line, g_built);
	v_exp = ft_get_env(cmd, g_built->i + 1);
	if (ft_strncmp(v_exp, "?", 1) == 0)
		exp = ft_expand_util_two(g_built, &flag, exp);
	else
		exp = ft_get_expand(v_exp, g_built->envp);
	if (exp != NULL)
	{
		fcl[0] = ft_strjoin_free(fcl[0], exp);
		if (flag)
			free(exp);
	}
	g_built->i = g_built->i + ft_strlen(v_exp);
	free(v_exp);
	return (g_built->i);
}

void	ft_free_b(char *c, int *flag)
{
	free(c);
	free(flag);
}

char	*ft_expand(t_mini *line, char **fcl, char *cmd, t_built *g_built)
{
	char	*c;
	int		*flag;

	g_built->i = -1;
	fcl[0] = (char *) malloc(1);
	ft_expand_init(&c, &flag, fcl);
	while (cmd[++g_built->i])
	{
		c[0] = cmd[g_built->i];
		if (cmd[g_built->i] == 34 && flag[1] == 0)
			flag[0]++;
		if (cmd[g_built->i] == 39 && flag[0] == 0)
			flag[1]++;
		if (flag[0] == 2)
			flag[0] = 0;
		if (flag[1] == 2)
			flag[1] = 0;
		if (cmd[g_built->i] == '$' && ft_exp_check(cmd[g_built->i + 1])
			&& (flag[0] || (flag[0] == 0 && flag[1] == 0)))
			g_built->i = ft_expand_util(line, &fcl[0], cmd, g_built);
		else
			fcl[0] = ft_strjoin_free(fcl[0], c);
	}
	ft_free_b(c, flag);
	return (fcl[0]);
}
