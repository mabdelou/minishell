/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis_I.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:47:55 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/23 14:47:57 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../execution/exe_header.h"
#include "../parssing/minishell.h"

void	ft_exelen(t_mini *data, t_built *g_built, int loop)
{
	int	a;

	a = 0;
	if (g_built->export == NULL)
		while (data[loop].env[a])
			++a;
	else
		while (g_built->export[a] && a < g_built->num_of_strings)
			++a;
	g_built->num_of_strings = a;
	return ;
}

void	ft_exportdup(t_mini *data, t_built *g_built, int loop)
{
	int	a;

	ft_exelen(data, g_built, loop);
	g_built->export = malloc(sizeof(char *) * g_built->num_of_strings + 1);
	if (!g_built->export)
		return ;
	a = -1;
	while (data[loop].env[++a] && a < g_built->num_of_strings)
		g_built->export[a] = ft_strdup(data[loop].env[a]);
	g_built->export[a] = NULL;
	return ;
}

int	ft_check_expert_before_rm(t_mini *data, t_built *g_built, int b, int loop)
{
	int	a;

	a = -1;
	while (g_built->export[++a] && a < g_built->num_of_strings)
	{
		if (ft_strncmp_built(g_built->export[a], data[loop].opt_args[b],
				ft_strlen_to(g_built->export[a], '=')) == 0)
		{
			if (ft_strlen_to(g_built->export[a], '=')
				== ft_strlen(data[loop].opt_args[b]))
				return (a);
		}
	}
	return (a);
}

int	ft_calc_args(t_mini *data, int loop)
{
	int	a;

	a = -1;
	while (data[loop].opt_args[++a])
		;
	return (a);
}

void	ft_print_export(t_mini *data, t_built *g_built, int loop)
{
	int	a;

	(void) data;
	a = -1;
	ft_exelen(data, g_built, loop);
	if (g_built->export)
		while (g_built->export[++a] && a < g_built->num_of_strings)
			printf("declare -x %s\n", g_built->export[a]);
	return ;
}
