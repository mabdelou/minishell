/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:20:33 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/04 17:20:36 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_header.h"

void	close_fds(t_node *node)
{
	int	a;

	a = -1;
	while (++a < node->n_pipe)
		close(node->fds[a]);
}

void	close_fd(t_node *node)
{
	int	a;

	a = -1;
	if (node->num_of_cmd == 1)
		node->num_of_cmd += 1;
	while (++a < node->num_of_cmd)
		close(node->fd[a]);
}

void	close_h_fd(t_node *node)
{
	int	a;

	a = -1;
	while (++a < (node->num_of_cmd * 2))
		close(node->h_fd[a]);
}

void	close_h_fds(t_node *node)
{
	int	a;

	a = -1;
	while (++a < node->num_of_hr * 2)
		close(node->h_fds[a]);
}
