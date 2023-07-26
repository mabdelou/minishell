/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_3_utilis_I.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:03:27 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 21:03:52 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "exe_header.h"

void	ft_execve_cmd_3_lr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_in_files(data, node, node->loop);
	ft_no_cmd_no_output(data, node);
	dup2(node->file1, 0);
	dup2(node->fds[1], 1);
	close(node->file1);
	close_fds(node);
	if (execve(data[0].cmd_path, data[0].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_cmd_3_lr_rr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_in_files(data, node, node->loop);
	ft_open_std_out_files(data, node, node->loop);
	ft_no_cmd_no_output(data, node);
	dup2(node->file1, 0);
	dup2(node->file2, 1);
	close(node->file1);
	close(node->file2);
	if (execve(data[0].cmd_path, data[0].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_cmd_3_rr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_out_files(data, node, node->loop);
	ft_no_cmd_no_output(data, node);
	dup2(node->file2, 1);
	close(node->file2);
	if (execve(data[0].cmd_path, data[0].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_cmd_3(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_no_cmd_no_output(data, node);
	dup2(node->fds[1], 1);
	close_fds(node);
	if (execve(data[0].cmd_path, data[0].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_cmd_4(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_no_cmd_no_output(data, node);
	dup2(node->fds[node->loop + node->n_std_in_c], 0);
	dup2(node->fds[node->n_std_out_c], 1);
	close_fds(node);
	if (execve(data[node->loop].cmd_path,
			data[node->loop].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}
