/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:15:12 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/03 13:20:00 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_copy(char **line, char *token)
{
	int	i;

	i = 0;
	if (token == NULL)
		return ;
	while (token[i])
	{
		line[0][i] = token[i];
		i++;
	}
	line[0][i] = 0;
}

char	**ft_copy_table(char **line, char **temp, int i)
{
	int	j;
	int	len;

	j = 0;
	while (j < i)
	{
		len = ft_strlen(line[j]);
		temp[j] = (char *) malloc(sizeof(char) * len + 1);
		ft_copy(&temp[j], line[j]);
		j++;
	}
	return (temp);
}

int	ft_free_a(char	**line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
	return (1);
}

char	**ft_concat_str(char **temp, char **line, char *token)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		line[i] = (char *) malloc(sizeof(char) * ft_strlen(temp[i]) + 1);
		while (temp[i][j])
		{
			line[i][j] = temp[i][j];
			j++;
		}
		line[i][j] = 0;
		i++;
	}
	j = -1;
	line[i] = (char *) malloc(sizeof(char) * ft_strlen(token) + 1);
	while (token[++j])
		line[i][j] = token[j];
	line[i][j] = 0;
	line[i + 1] = NULL;
	return (line);
}

char	**ft_realloc(char **line, char *token)
{
	int		i;
	char	**tmp;

	i = 0;
	while (line[i])
		i++;
	tmp = (char **) malloc(sizeof(char *) * (i + 1));
	tmp[i] = NULL;
	tmp = ft_copy_table(line, tmp, i);
	ft_free_a(line);
	line = NULL;
	line = (char **) malloc(sizeof(char *) * (i + 2));
	line = ft_concat_str(tmp, line, token);
	ft_free_a(tmp);
	return (line);
}
