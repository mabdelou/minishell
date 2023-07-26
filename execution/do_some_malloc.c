/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_some_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:22:30 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/01 22:41:51 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_header.h"

int	ft_dsm(t_node *node)
{
	node->fds = malloc(sizeof(int) * (node->num_of_cmd - 1) * 2);
	if (!node->fds)
	{
		write(2, "ERROR in allocat node->fds\n", 27);
		return (512);
	}
	if (make_pipes(node))
	{
		write(2, "error cant make pipes\n", 22);
		return (512);
	}
	return (0);
}

int	ft_do_some_malloc(t_node *node, int type)
{
	if (type == 0)
		return (ft_dsm(node));
	else if (type > 0)
	{
		node->h_fds = malloc(sizeof(int) * (type * 2));
		if (!node->h_fds)
		{
			write(2, "ERROR in allocat node->h_fds\n", 29);
			return (512);
		}
		if (make_hr_pipes(node, type))
		{
			write(2, "error cant make hr_pipes\n", 22);
			close_h_fds(node);
			free(node->h_fds);
			return (512);
		}
	}
	return (0);
}

void	ft_free_some_ptrs(t_node *node, int type)
{
	int	a;

	a = -1;
	if (type == 0)
		free(node->fds);
	else if (type > 0)
		free(node->h_fds);
}

int	ft_do_some_malloc_v2(t_node *node, int type)
{
	int	a;

	a = -1;
	if (type == 1)
	{
		node->pids_ads = malloc(sizeof(int) * node->num_of_cmd);
		if (!node->pids_ads)
		{
			write(2, "ERROR in allocat node->pids_ads\n", 32);
			return (512);
		}
	}
	else
	{
		if (node->pids_ads != NULL)
			free(node->pids_ads);
	}
	return (0);
}
