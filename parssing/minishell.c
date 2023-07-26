/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:39:01 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 20:23:45 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../execution/exe_header.h"
#include "../builtin/builtin.h"
#include "minishell.h"

void	ft_check_if_builtin(t_mini *line, t_built *g_built, int loop)
{
	(void) line;
	(void) g_built;
	(void) loop;
	if (!ft_strncmp_magiscule(line[loop].builtins, "cd"))
		g_built->end_state = ft_cd(&line[loop], g_built);
	else if (!ft_strncmp_magiscule(line[loop].builtins, "echo"))
		g_built->end_state = ft_echo(&line[loop], g_built);
	else if (!ft_strncmp_exe(line[loop].builtins, "exit"))
		g_built->end_state = ft_exit(&line[loop], g_built);
	else if (!ft_strncmp_magiscule(line[loop].builtins, "pwd"))
		g_built->end_state = ft_pwd(&line[loop], g_built);
	else if (!ft_strncmp_exe(line[loop].builtins, "export"))
		g_built->end_state = ft_export(line, g_built, loop);
	else if (!ft_strncmp_exe(line[loop].builtins, "unset"))
		g_built->end_state = ft_unset(line, g_built, loop);
	else if (!ft_strncmp_magiscule(line[loop].builtins, "env"))
		ft_env(line, g_built, loop);
	g_built->end_state = g_built->end_state * 256;
	if (line[0].n_of_p == 1)
		return ;
}

void	ft_minishell(t_mini *line, char **env, t_built *g_built)
{
	int	i;

	i = 0;
	(void) env;
	(void) g_built;
	(void) line;
	if (line[0].n_of_p == 1 && line[0].builtins != NULL)
		ft_check_if_builtin(line, g_built, 0);
	else if (ft_check_nbr_of_cmd(line, g_built, line->n_of_p))
		g_built->end_state = 1;
}

void	ft_addition(t_mini *line)
{
	ft_free_cmd(line);
	g_built.end_state = 1;
}

int	main(int ac, char **av, char **env)
{
	t_mini	*line;
	char	*cmd;

	ft_init_sig(&g_built, ac, av);
	while (1)
	{
		cmd = readline("Prompt $ ");
		g_built.flag = 1;
		if (ft_valide(cmd) == 1)
		{
			line = ft_init_line(line, cmd, env);
			if (ft_initialize(line, cmd, &g_built) == 0)
			{
				ft_minishell(line, env, &g_built);
				ft_free_cmd(line);
			}
			else
				ft_addition(line);
			free(line);
		}
		else if (ft_valide(cmd) == -1)
			ft_sigquit_handler(1);
		ft_next_cmd(&cmd);
	}
	return (0);
}
