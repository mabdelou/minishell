/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:38:12 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/30 22:15:12 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count_word(const char *s, char c)
{
	int	words;
	int	i;

	if (s == NULL)
		return (0);
	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] && !ft_odd_quote(s, i))
			i++;
		if ((s[i] != c && s[i]) || (s[i] == c && ft_odd_quote(s, i)))
		{
			while ((s[i] != c && s[i]) || (s[i] == c && ft_odd_quote(s, i)))
				i++;
			words++;
		}
	}
	if (words == 0)
		return (1);
	return (words);
}

static void	ft_free(char **buff, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}

static char	*ft_assign(char **buff, int k, const char *s, int j)
{
	int	i;

	i = 0;
	buff[k] = NULL;
	buff[k] = (char *) malloc(sizeof(char) * (j + 1));
	if (buff[k] == NULL)
	{
		write(2, "Fail to allocate memory\n", 24);
		ft_free(buff, k);
		return (NULL);
	}
	while (i < j)
	{
		buff[k][i] = (char )s[i];
		i++;
	}
	buff[k][j] = '\0';
	return (buff[k]);
}

static char	**ft_allocate(char **buff, const char *s, char c)
{
	int	i;
	int	index_j;
	int	index_k;

	i = 0;
	index_k = 0;
	while (s[i])
	{
		index_j = 0;
		while (s[i] == c && s[i] && !ft_odd_quote(s, i))
			i++;
		while ((s[i + index_j] != c && s[i + index_j])
			|| (s[i + index_j] == c && ft_odd_quote(s, i + index_j)))
			index_j++;
		if (index_j > 0)
		{
			buff[index_k] = ft_assign(buff, index_k, &s[i], index_j);
			index_k++;
		}
		i += index_j;
	}
	buff[index_k] = 0;
	return (buff);
}

char	**ft_split_case(char const *s, char c)
{
	char	**buff;
	int		words;

	buff = (void *) 0;
	words = ft_count_word(s, c);
	if (s == NULL)
		return (NULL);
	else if (words)
	{
		buff = (char **) malloc(sizeof(char *) * (words + 1));
		if (buff == (void *) 0)
		{
			write(2, "Fail to allocate memory\n", 24);
			return ((void *) 0);
		}
		buff = ft_allocate(buff, s, c);
	}
	return (buff);
}
