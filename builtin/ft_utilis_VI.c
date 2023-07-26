/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis_VI.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:01:33 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/06 18:01:35 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../execution/exe_header.h"
#include "../parssing/minishell.h"

int	ft_strlen_who_big(char *exp, char *ops, char a)
{
	size_t	i;
	size_t	k;

	if (exp == NULL || ops == NULL)
		return (0);
	i = 0;
	while (exp[i] != a && exp[i] != '\0')
		i++;
	k = 0;
	while (ops[k] != a && ops[k] != '\0')
		k++;
	if (i > k)
		return (i);
	else if (i < k)
		return (k);
	return (i);
}

void	ft_check_export_two(t_mini *data, int loop, int a, int b)
{
	g_built.loop = loop;
	ft_check_export_v2(data, &g_built, a, b);
}
