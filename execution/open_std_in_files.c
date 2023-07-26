/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_std_in_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:57:24 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/07 23:38:51 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "exe_header.h"

void	ft_open_std_in_files(t_mini *data, t_node *node, int loop)
{
	int	a;

	a = -1;
	while (data[loop].std_in[++a] != NULL && data[0].error == NULL)
	{		
		node->file1 = open(data[loop].std_in[a], O_RDONLY);
		if (node->file1 == -1)
		{
			perror(NULL);
			exit(1);
		}
		if (data[loop].std_in[a + 1] != NULL)
			close(node->file1);
	}
	if (data[0].error != NULL)
	{
		write(2, data[0].error, ft_strlen(data[0].error));
		write(2, "\n", 1);
		exit(1);
	}
}
