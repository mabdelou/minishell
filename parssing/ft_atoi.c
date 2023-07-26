/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:48:46 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/07 23:35:34 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_getnbr(char *str, int sign)
{
	int	index;
	int	res;

	res = 0;
	index = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10;
		res = res + (str[index] - 48);
		index++;
	}
	if (index > 19 && sign == -1)
		return (0);
	if (index > 19 && sign == 1)
		return (-1);
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	sign;

	index = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	return (ft_getnbr((char *)str + index, sign));
}

static long long	ft_getnbr_l(char *str, int sign)
{
	int			index;
	long long	res;

	res = 0;
	index = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10;
		res = res + (str[index] - 48);
		index++;
	}
	if (index > 19 && sign == -1)
		return (0);
	if (index > 19 && sign == 1)
		return (-1);
	return (res * sign);
}

t_ll	ft_atoi_l(const char *str)
{
	int	index;
	int	sign;

	index = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	return (ft_getnbr_l((char *)str + index, sign));
}
