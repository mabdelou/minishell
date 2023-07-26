/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_2_utilis_V.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:01:29 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 21:01:30 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "exe_header.h"

void	ft_execve_cmd_2__(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_no_cmd_no_output(data, node);
	dup2(node->fd[0], 0);
	close_h_fd(node);
	close_fd(node);
	if (execve(data[1].cmd_path, data[1].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_cmd_2_rr__(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_out_files(data, node, 1);
	ft_no_cmd_no_output(data, node);
	dup2(node->fd[0], 0);
	dup2(node->file2, 1);
	close_fd(node);
	close_h_fd(node);
	close(node->file2);
	if (execve(data[1].cmd_path, data[1].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

void	ft_execve_cmd_1_rr__(t_mini *data, t_built *g_built, t_node *node)
{
	(void) g_built;
	ft_open_std_out_files(data, node, 0);
	ft_no_cmd_no_output(data, node);
	dup2(node->file2, 1);
	close(node->file2);
	close_fd(node);
	close_h_fd(node);
	if (execve(data[0].cmd_path, data[0].opt_args, g_built->envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}
