/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_type_of_cmd_II_v2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:15:48 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 22:15:50 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_header.h"
#include "../parssing/minishell.h"
#include "./get_next_line/get_next_line.h"

void	ft_drr_2_v2(t_node *node, t_built *g_built, t_mini *data)
{
	(void) g_built;
	node->loop = 0;
	if (node->pids_ads[0] == 0 && data[node->loop].builtins != NULL)
		ft_execve_builtin(data, g_built, node);
	if (data[0].std_in == NULL && data[0].std_out == NULL
		&& data[0].limiter != NULL)
		ft_execve_cmd_1_hr(data, g_built, node);
	else if (data[0].std_in == NULL && data[0].std_out != NULL
		&& data[0].limiter != NULL)
		ft_execve_cmd_1_hr_rr(data, g_built, node);
	else if (data[0].std_in != NULL && data[0].std_out != NULL)
		ft_execve_cmd_1_lr_rr__(data, g_built, node);
	else if (data[0].std_in != NULL && data[0].std_out == NULL)
		ft_execve_cmd_1_lr__(data, g_built, node);
	else if (data[0].std_in == NULL && data[0].std_out == NULL)
		ft_execve_cmd_1__(data, g_built, node);
	else if (data[0].std_in == NULL && data[0].std_out != NULL)
		ft_execve_cmd_1_rr__(data, g_built, node);
	close_h_fd(node);
	exit(0);
}

void	ft_drr_2_v3(t_node *node, t_built *g_built, t_mini *data)
{
	(void) g_built;
	node->loop = 1;
	if (node->pids_ads[1] == 0 && data[node->loop].builtins != NULL)
		ft_execve_builtin(data, g_built, node);
	if (data[1].std_in == NULL && data[1].std_out == NULL
		&& data[1].limiter != NULL)
		ft_execve_cmd_2_hr(data, g_built, node);
	else if (data[1].std_in == NULL && data[1].std_out != NULL
		&& data[1].limiter != NULL)
		ft_execve_cmd_2_hr_rr(data, g_built, node);
	else if (data[1].std_in == NULL && data[1].std_out == NULL)
		ft_execve_cmd_2__(data, g_built, node);
	else if (data[1].std_in == NULL && data[1].std_out != NULL)
		ft_execve_cmd_2_rr__(data, g_built, node);
	else if (data[1].std_in != NULL && data[1].std_out != NULL)
		ft_execve_cmd_2_lr_rr__(data, g_built, node);
	else if (data[1].std_in != NULL && data[1].std_out == NULL)
		ft_execve_cmd_2_lr__(data, g_built, node);
	close_h_fd(node);
	exit(0);
}
