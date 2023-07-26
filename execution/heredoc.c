/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:52:14 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 21:52:15 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_header.h"
#include "../parssing/minishell.h"
#include "./get_next_line/get_next_line.h"

void	ft_sigint_handler_hr(int sig)
{
	(void) sig;
	printf("\n");
	exit(1);
}

int	ft_heredoc_v2(t_node *node, t_mini *data,
		int n_std_out_hr, t_built *g_built)
{
	node->ptr = readline("heredoc> ");
	node->difirent = ft_strncmp_exe(node->ptr, node->heredoc_limit);
	if (node->ptr != NULL)
	{
		ft_expand(data, &node->ptr2, node->ptr, g_built);
		free(node->ptr);
	}
	if (!node->difirent)
		return (1);
	else if (node->difirent == 1337)
		return (1);
	else
	{
		if (data[node->loop].limiter[node->a + 1] == NULL)
		{
			if (g_built->type == 1)
				ft_putstr_fd(node->ptr2, node->fd[n_std_out_hr]);
			else if (g_built->type == 2)
				ft_putstr_fd(node->ptr2, node->h_fd[n_std_out_hr]);
			if (g_built->type == 3)
				ft_putstr_fd(node->ptr2, node->h_fds[n_std_out_hr]);
		}
	}
	return (0);
}

void	ft_heredoc_3(t_node *node, t_mini *data, t_built *g_built)
{
	node->a = -1;
	g_built->type = 3;
	signal(SIGINT, ft_sigint_handler_hr);
	while (data[node->loop].limiter[++node->a] != NULL)
	{
		if (data[node->loop].limiter[node->a + 1] == NULL)
			node->n_std_out_hr += 2;
		node->heredoc_limit = data[node->loop].limiter[node->a];
		while (true)
			if (ft_heredoc_v2(node, data, node->n_std_out_hr, g_built))
				break ;
	}
}

void	ft_heredoc_2(t_node *node, t_mini *data, t_built *g_built)
{
	node->a = -1;
	g_built->type = 2;
	signal(SIGINT, ft_sigint_handler_hr);
	while (data[node->loop].limiter[++node->a] != NULL)
	{
		if (data[node->loop].limiter[node->a + 1] == NULL)
			node->n_std_out_hr += 2;
		node->heredoc_limit = data[node->loop].limiter[node->a];
		while (true)
			if (ft_heredoc_v2(node, data, node->n_std_out_hr, g_built))
				break ;
	}
}

void	ft_heredoc_1(t_node *node, t_mini *data, t_built *g_built)
{
	node->a = -1;
	g_built->type = 1;
	signal(SIGINT, ft_sigint_handler_hr);
	while (data[node->loop].limiter[++node->a] != NULL)
	{
		node->heredoc_limit = data[node->loop].limiter[node->a];
		while (true)
			if (ft_heredoc_v2(node, data, 1, g_built))
				break ;
	}
}
