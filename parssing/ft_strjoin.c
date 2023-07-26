/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:32:52 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/11 16:28:05 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	index_i;
	size_t	index_j;
	char	*joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined = NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *) malloc(sizeof(char) * (len + 1));
	if (joined == NULL)
		return (NULL);
	index_i = 0;
	index_j = 0;
	while (s1[index_j])
		joined[index_i++] = s1[index_j++];
	index_j = 0;
	while (s2[index_j])
		joined[index_i++] = s2[index_j++];
	joined[index_i] = 0;
	return (joined);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t	len;
	size_t	index_i;
	size_t	index_j;
	char	*joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined = NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *) malloc(sizeof(char) * (len + 1));
	if (joined == NULL)
		return (NULL);
	index_i = 0;
	index_j = 0;
	while (s1[index_j])
		joined[index_i++] = s1[index_j++];
	index_j = 0;
	while (s2[index_j])
		joined[index_i++] = s2[index_j++];
	joined[index_i] = 0;
	free((void *) s1);
	return (joined);
}
