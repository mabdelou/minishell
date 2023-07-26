/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_cmd_no_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:56:55 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 21:56:56 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "exe_header.h"

void	ft_no_cmd_no_output(t_mini *data, t_node *node)
{
	if (data[node->loop].cmd == NULL && node->num_of_cmd == 1)
	{
		if (data[node->loop].limiter != NULL)
			close_fd(node);
		exit(1);
	}
	else if (data[node->loop].cmd == NULL && node->num_of_cmd == 2)
	{
		close_fd(node);
		if (data[node->loop].limiter != NULL)
			close_h_fd(node);
		exit(1);
	}
	else if (data[node->loop].cmd == NULL && node->num_of_cmd == 3)
	{
		close_fds(node);
		if (data[node->loop].limiter != NULL)
			close_h_fds(node);
		exit(1);
	}
}
