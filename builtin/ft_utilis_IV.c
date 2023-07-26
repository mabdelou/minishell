/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis_IV.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:33:25 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/01 22:40:23 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../execution/exe_header.h"
#include "../parssing/minishell.h"

void	ft_envlen(t_mini *data, t_built *g_built, int loop)
{
	int	a;
	int	b;

	a = -1;
	b = 0;
	if (g_built->export == NULL)
	{
		while (data[loop].env[++a])
			;
		g_built->num_of_env_strings = a;
		return ;
	}
	else
	{
		while (g_built->export[++a] && a < g_built->num_of_strings)
			if (ft_iseagal(g_built->export[a]))
				++b;
		g_built->num_of_env_strings = b;
		return ;
	}
}

void	ft_free_env(t_mini *data, t_built *g_built)
{
	int		a;

	(void) data;
	a = -1;
	if (g_built->envp != NULL)
		while (g_built->envp[++a] && a < g_built->num_of_env_strings)
			free(g_built->envp[a]);
	free(g_built->envp);
	return ;
}

void	ft_envdup(t_mini *data, t_built *g_built, int loop)
{
	int	a;
	int	b;

	ft_free_env(data, g_built);
	ft_envlen(data, g_built, loop);
	g_built->envp = malloc(sizeof(char *) * g_built->num_of_env_strings + 1);
	if (!g_built->envp)
		return ;
	a = -1;
	b = 0;
	if (g_built->export != NULL)
	{
		while (g_built->export[++a] && b < g_built->num_of_env_strings)
			if (ft_iseagal(g_built->export[a]))
				g_built->envp[b++] = ft_strdup(g_built->export[a]);
			g_built->envp[b++] = NULL;
	}
	else if (g_built->export == NULL)
	{
		ft_exportdup(data, g_built, loop);
		while (g_built->export[++a] && b < g_built->num_of_env_strings)
			g_built->envp[b++] = ft_strdup(g_built->export[a]);
		g_built->envp[a++] = NULL;
	}
	ft_envlen(data, g_built, loop);
}

void	ft_print_env(t_mini *data, t_built *g_built, int loop)
{
	int	a;

	(void) data;
	a = -1;
	ft_envlen(data, g_built, loop);
	if (g_built->envp)
		while (g_built->envp[++a] && a < g_built->num_of_env_strings)
			printf("%s\n", g_built->envp[a]);
	return ;
}

void	ft_check_export_v2(t_mini *data, t_built *g_built, int a, int b)
{
	int	size;
	int	loop;

	loop = g_built->loop;
	size = ft_iseagal(data[loop].opt_args[b]);
	if (a == g_built->num_of_strings && size != 0)
		g_built->export = ft_addvar(data, g_built, b, loop);
	else if (a == g_built->num_of_strings && size == 0)
		g_built->export = ft_addvar(data, g_built, b, loop);
	else if (a != g_built->num_of_strings && size != 0)
	{
		free(g_built->export[a]);
		g_built->export[a] = strdup(data[loop].opt_args[b]);
	}
	else if (a != g_built->num_of_strings && size == 0)
		return ;
}
