/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:39:08 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/07 18:46:17 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"

int	ft_exit_util_tree(t_mini *line, int flag)
{
	flag = ft_atoi(line[0].opt_args[0]);
	write(2, "exit\n", 5);
	g_built.end_state = flag;
	exit(flag % 256);
}
