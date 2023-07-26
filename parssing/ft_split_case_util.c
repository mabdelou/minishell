/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_case_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:11:44 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/30 22:14:57 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_odd_quote(const char *s, int index)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (s[i] && i < index)
	{
		if (s[i] == 34 || s[i] == 39)
			flag++;
		i++;
	}
	return (flag % 2);
}
