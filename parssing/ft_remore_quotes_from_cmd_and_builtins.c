/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remore_quotes_from_cmd_and_builtins.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:56:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/30 22:06:15 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_rm_quotes(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		while ((str[i] == 34 || str[i] == 39) && str[i])
			i++;
		str[j] = str[i];
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}

void	ft_expand_init(char **c, int **flag, char **fcl)
{
	c[0] = (char *) malloc(sizeof(char) * 2);
	flag[0] = (int *) malloc(sizeof(int) * 2);
	c[0][1] = 0;
	flag[0][0] = 0;
	flag[0][1] = 0;
	fcl[0][0] = 0;
}
