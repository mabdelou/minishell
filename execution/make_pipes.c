/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:55:58 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 21:56:00 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_header.h"

int	make_pipes(t_node *node)
{
	int	a;

	a = -1;
	while (++a < (node->num_of_cmd - 1) * 2)
	{
		if (a % 2 == 0)
			if (pipe(&node->fds[a]) == -1)
				return (1);
		node->n_pipe++;
	}
	return (0);
}

int	make_hr_pipes(t_node *node, int type)
{
	int	a;

	a = -1;
	while (++a < (type * 2))
		if (a % 2 == 0)
			if (pipe(&node->h_fds[a]) == -1)
				return (1);
	return (0);
}
