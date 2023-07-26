/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_2_utilis_III.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:31:46 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 20:31:48 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "exe_header.h"

void	ft_execve_cmd_1_hr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_no_cmd_no_output(data, node);
	if (data[1].limiter != NULL)
	{
		close_h_fd(node);
		close_fd(node);
		exit(127);
	}
	dup2(node->h_fd[node->n_std_in_hr], 0);
	dup2(node->fd[1], 1);
	close_h_fd(node);
	close_fd(node);
	if (execve(data[0].cmd_path, data[0].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_cmd_1_hr_rr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_out_files(data, node, 0);
	ft_no_cmd_no_output(data, node);
	dup2(node->h_fd[node->n_std_in_hr], 0);
	dup2(node->file2, 1);
	close(node->file2);
	close_h_fd(node);
	close_fd(node);
	if (execve(data[0].cmd_path, data[0].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}
