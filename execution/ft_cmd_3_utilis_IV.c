/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_3_utilis_IV.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:15:16 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 21:15:20 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "exe_header.h"

void	ft_execve_cmd_4_hr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_no_cmd_no_output(data, node);
	dup2(node->h_fds[node->n_std_in_hr], 0);
	dup2(node->fds[node->n_std_out_c], 1);
	close_fds(node);
	close_h_fds(node);
	if (execve(data[node->loop].cmd_path,
			data[node->loop].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_cmd_4_hr_rr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_out_files(data, node, node->loop);
	ft_no_cmd_no_output(data, node);
	dup2(node->h_fds[node->n_std_in_hr], 0);
	dup2(node->file2, 1);
	close_fds(node);
	close(node->file2);
	close_h_fds(node);
	if (execve(data[node->loop].cmd_path,
			data[node->loop].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_cmd_5_hr_rr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_out_files(data, node, node->loop);
	ft_no_cmd_no_output(data, node);
	dup2(node->h_fds[node->n_std_in_hr], 0);
	dup2(node->file2, 1);
	close(node->file2);
	close_fds(node);
	close_h_fds(node);
	if (execve(data[node->loop].cmd_path,
			data[node->loop].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}
