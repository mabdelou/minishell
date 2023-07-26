/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:50:25 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/24 16:15:32 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] == s2[index])
			index++;
		else
			return (s1[index] - s2[index]);
	}
	return (s1[index] - s2[index]);
}

int	ft_strcmp_case(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i] || s1[i] == (s2[i] + 32))
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}
