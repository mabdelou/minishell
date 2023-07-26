/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_std_out_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:58:07 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 21:58:08 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "exe_header.h"

void	ft_open_std_out_files(t_mini *data, t_node *node, int loop)
{
	int	a;

	a = -1;
	while (data[loop].std_out[++a] != NULL)
	{
		if (data[loop].trunc[a][0] == 't')
			node->file2 = open(data[loop].std_out[a],
					O_CREAT | O_RDWR | O_TRUNC, 0644);
		else if (data[loop].trunc[a][0] == 'f')
			node->file2 = open(data[loop].std_out[a],
					O_CREAT | O_RDWR | O_APPEND, 0644);
		if (node->file2 == -1)
		{
			perror(NULL);
			exit(1);
		}
		if (data[loop].std_out[a + 1] != NULL)
			close(node->file2);
	}
}

void	ft_open_std_out_files_for_built(t_mini *data, t_node *node, int loop)
{
	int	a;

	a = -1;
	while (data[loop].std_out[++a] != NULL)
	{
		if (data[loop].trunc[a][0] == 't')
			node->file2 = open(data[loop].std_out[a],
					O_CREAT | O_RDWR | O_TRUNC, 0644);
		else if (data[loop].trunc[a][0] == 'f')
			node->file2 = open(data[loop].std_out[a],
					O_CREAT | O_RDWR | O_APPEND, 0644);
		if (node->file2 == -1)
		{
			perror(NULL);
			return ;
		}
		if (data[loop].std_out[a + 1] != NULL)
			close(node->file2);
	}
}
