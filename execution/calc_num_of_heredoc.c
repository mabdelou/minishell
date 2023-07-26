/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_num_of_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:54:06 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 19:54:11 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/minishell.h"
#include "exe_header.h"

int	ft_calc_num_of_heredoc(t_mini *data)
{
	int	a;
	int	num_of_hr;

	a = -1;
	num_of_hr = 0;
	while (data[++a].fcl != NULL)
		if (data[a].limiter != NULL)
			++num_of_hr;
	return (num_of_hr);
}
