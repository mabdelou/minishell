/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:08:20 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 22:08:21 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_header.h"

void	wait_pross(t_node *node, t_built *g_built)
{
	int	a;

	a = -1;
	while (++a < node->num_of_cmd)
		waitpid(node->pids_ads[a], &g_built->end_state, 0);
}
