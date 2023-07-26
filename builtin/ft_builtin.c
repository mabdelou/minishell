/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:21:40 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/23 14:21:45 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../execution/exe_header.h"
#include "../parssing/minishell.h"

int	ft_unset_v1(t_mini *data, t_built *g_built, int loop)
{
	int	a;

	a = -1;
	if (g_built->export == NULL)
		ft_exportdup(data, g_built, loop);
	ft_sort_export(data, g_built);
	while (++a < ft_calc_args(data, loop))
	{
		if (ft_check_var(data, a, loop)
			&& !ft_iseagal(data[loop].opt_args[a]))
		{
			if (ft_check_expert_before_rm(data, g_built, a, loop)
				!= g_built->num_of_strings)
				g_built->export = ft_delvar(data, g_built, a, loop);
		}
		else
		{
			write(2, "bash: unset : not a valid identifier\n", 37);
			return (1);
		}
	}
	ft_envdup(data, g_built, loop);
	return (0);
}

int	ft_unset(t_mini *data, t_built *g_built, int loop)
{
	t_node	node;
	int		rl_std_out;

	g_built->end_state = 0;
	(void) g_built;
	if (data[0].n_of_p < 3)
		ft_here_doc(data);
	if (data[loop].std_out != NULL)
		ft_open_std_out_files_for_built(data, &node, loop);
	rl_std_out = dup(1);
	if (data[loop].std_out != NULL)
		dup2(node.file2, 1);
	if (data[loop].builtins != NULL && data[loop].opt_args != NULL)
		g_built->end_state = ft_unset_v1(data, g_built, loop);
	dup2(rl_std_out, 1);
	return (g_built->end_state);
}

void	ft_env(t_mini *data, t_built *g_built, int loop)
{
	t_node	node;
	int		rl_std_out;

	if (data[0].n_of_p < 3)
		ft_here_doc(data);
	if (data[loop].std_out != NULL)
		ft_open_std_out_files_for_built(data, &node, loop);
	rl_std_out = dup(1);
	if (data[loop].std_out != NULL)
		dup2(node.file2, 1);
	if (data[loop].builtins != NULL && data[loop].opt_args == NULL)
	{
		ft_envdup(data, g_built, loop);
		ft_change_shlvl(data, g_built);
		ft_print_env(data, g_built, loop);
	}
	dup2(rl_std_out, 1);
}

int	ft_export_v1(t_mini *data, t_built *g_built, int loop)
{
	int	a;

	a = -1;
	if (g_built->export == NULL)
		ft_exportdup(data, g_built, loop);
	ft_sort_export(data, g_built);
	while (++a < ft_calc_args(data, loop))
	{
		if (ft_check_var(data, a, loop))
			ft_check_export(data, g_built, a, loop);
		else
		{
			write(2, "bash: export : not a valid identifier\n", 38);
			g_built->end_state = 1;
		}
	}
	ft_envdup(data, g_built, loop);
	return (0);
}

int	ft_export(t_mini *data, t_built *g_built, int loop)
{
	int		rl_std_out;
	t_node	node;

	g_built->end_state = 0;
	if (data[0].n_of_p < 3)
		ft_here_doc(data);
	if (data[loop].std_out != NULL)
		ft_open_std_out_files_for_built(data, &node, loop);
	rl_std_out = dup(1);
	if (data[loop].std_out != NULL)
		dup2(node.file2, 1);
	if (data[loop].builtins != NULL && data[loop].opt_args == NULL)
	{
		if (g_built->export == NULL)
			ft_exportdup(data, g_built, loop);
		ft_change_shlvl(data, g_built);
		ft_sort_export(data, g_built);
		ft_print_export(data, g_built, loop);
	}
	else if (data[loop].builtins != NULL && data[loop].opt_args != NULL)
		ft_export_v1(data, g_built, loop);
	dup2(rl_std_out, 1);
	ft_change_shlvl(data, g_built);
	return (g_built->end_state);
}
