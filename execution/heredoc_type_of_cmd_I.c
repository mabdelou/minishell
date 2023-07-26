/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_type_of_cmd_I.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:27:24 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 21:27:26 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_header.h"
#include "../parssing/minishell.h"
#include "./get_next_line/get_next_line.h"

void	ft_drr_1_v2(t_node *node, t_built *g_built, t_mini *data)
{
	if (data[node->loop].std_in == NULL && data[node->loop].std_out == NULL
		&& data[node->loop].limiter != NULL)
		ft_execve_cmd_hr(data, g_built, node);
	else if (data[node->loop].std_in == NULL
		&& data[node->loop].std_out != NULL
		&& data[node->loop].limiter != NULL)
		ft_execve_cmd_hr_rr(data, g_built, node);
	else if (data[node->loop].std_in != NULL
		&& data[node->loop].std_out != NULL
		&& data[node->loop].limiter != NULL)
		ft_execve_cmd_rr_lr(data, g_built, node);
	else if (data[node->loop].std_in != NULL
		&& data[node->loop].std_out == NULL
		&& data[node->loop].limiter != NULL)
		ft_execve_cmd_lr(data, g_built, node);
}

void	ft_drr_1(t_node *node, t_built *g_built, t_mini *data)
{
	(void) g_built;
	node->pids_ads[0] = fork();
	if (node->pids_ads[0] == -1)
		return ;
	else if (node->pids_ads[0] == 0)
		ft_drr_1_v2(node, g_built, data);
	close(node->fd[0]);
	close(node->fd[1]);
	wait(NULL);
	return ;
}

int	ft_make_some_pipe_1(t_node *node)
{
	if (pipe(node->fd) == -1)
		return (1);
	return (0);
}

int	ft_heredoc_type_of_cmd_1(t_node *node, t_mini *data, t_built *g_built)
{
	int	pid;

	(void) g_built;
	pid = fork();
	if (pid == 0)
	{
		if (ft_make_some_pipe_1(node))
			exit(1);
		node->heredoc_limit = data[0].limiter[0];
		ft_heredoc_1(node, data, g_built);
		ft_drr_1(node, g_built, data);
		exit(0);
	}
	else
		waitpid(pid, &g_built->end_state, 0);
	return (0);
}
