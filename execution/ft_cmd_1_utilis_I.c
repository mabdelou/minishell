/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_1_utilis_I.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:06:30 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/04 15:45:15 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "exe_header.h"

void	ft_execve_cmd(t_mini *data, t_built *g_built, t_node *node)
{
	(void) node;
	(void) g_built;
	ft_no_cmd_no_output(data, node);
	if (execve(data[0].cmd_path, data[0].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_builtin(t_mini *data, t_built *g_built, t_node *node)
{
	(void) node;
	(void) g_built;
	if (node->num_of_cmd == 2 && node->loop == 0)
		dup2(node->fd[1], 1);
	else if (node->num_of_cmd >= 3 && node->loop < node->num_of_cmd - 1)
		dup2(node->fds[node->n_std_out_c], 1);
	ft_check_if_builtin(data, g_built, node->loop);
	if (node->num_of_cmd == 2 && data[node->loop].limiter == NULL)
		close_fd(node);
	else if (node->num_of_cmd == 2 && data[node->loop].limiter != NULL)
	{
		close_h_fd(node);
		close_fd(node);
	}
	else if (node->num_of_cmd == 3 && data[node->loop].limiter == NULL)
		close_fds(node);
	else if (node->num_of_cmd == 3 && data[node->loop].limiter != NULL)
	{
		close_h_fds(node);
		close_fds(node);
	}
	exit(g_built->end_state / 256);
}

void	ft_execve_cmd_lr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_in_files(data, node, 0);
	ft_no_cmd_no_output(data, node);
	if (data[0].limiter != NULL)
	{
		if (data[0].orlim[0][0] == 't')
			dup2(node->fd[0], 0);
		else
			dup2(node->file1, 0);
		close_fd(node);
	}
	else
		dup2(node->file1, 0);
	close(node->file1);
	if (execve(data[0].cmd_path, data[0].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_cmd_rr_lr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_in_files(data, node, 0);
	ft_open_std_out_files(data, node, 0);
	ft_no_cmd_no_output(data, node);
	if (data[0].limiter != NULL)
	{
		if (data[0].orlim[0][0] == 't')
			dup2(node->fd[0], 0);
		else
			dup2(node->file1, 0);
		close_fd(node);
	}
	else
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

void	ft_execve_cmd_rr(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_out_files(data, node, 0);
	ft_no_cmd_no_output(data, node);
	dup2(node->file2, 1);
	close(node->file2);
	if (execve(data[0].cmd_path, data[0].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}
