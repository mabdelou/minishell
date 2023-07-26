/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:45:57 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/17 00:25:24 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(char *s1)
{
	char	*dest;
	int		len;

	dest = NULL;
	len = ft_strlen_g(s1);
	dest = (char *) malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		dest[len] = s1[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*sub;

	if (s == NULL)
		return (NULL);
	sub = (void *) 0;
	length = ft_strlen_g(s);
	if (start >= length)
		sub = (char *) malloc(sizeof(char) * (1));
	else if ((length - start) >= len)
		sub = (char *) malloc(sizeof(char) * (len + 1));
	else if ((length - start) < len && (length > start))
		sub = (char *) malloc(sizeof(char) * ((length - start) + 1));
	if (sub == (void *) 0)
		return ((void *) 0);
	i = 0;
	while (i < len && s[i] != '\0' && start < length)
	{
		sub[i++] = s[start];
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

static char	*ft_realloc(char *s, char *buff)
{
	int		len;
	char	*temp;

	temp = NULL;
	len = ft_strlen_g(s);
	temp = (char *) malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
	{
		free(buff);
		return (NULL);
	}
	ft_copy_str(&temp, &s, len + 1);
	free(s);
	s = (char *) malloc(sizeof(char *) * (len + BUFFER_SIZE + 1));
	if (buff == NULL)
	{
		free(temp);
		return (NULL);
	}
	ft_copy_str(&s, &temp, len + 1);
	free(temp);
	ft_concat(&s, &buff, len + BUFFER_SIZE + 1);
	return (s);
}

static char	*ft_get_line(char **s, int rd, char *buff)
{
	char	*temp;	
	char	*line;
	int		index;

	free(buff);
	temp = NULL;
	if (rd == -1 || *s == NULL)
		return (NULL);
	index = ft_index_of(*s, '\n');
	if (index == -1)
		index = ft_strlen_g(*s);
	line = ft_substr(*s, 0, index + 1);
	temp = ft_substr(*s, ft_index_of(*s, '\n') + 1, ft_strlen_g(*s) - index);
	free(*s);
	if (*temp == '\0')
	{
		free(temp);
		*s = NULL;
	}
	else
		*s = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buff;
	int			rd;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		buff[rd] = 0;
		if (!s)
			s = ft_strdup(buff);
		else if (buff)
			s = ft_realloc(s, buff);
		if (ft_strchar(s, '\n') >= 0)
			return (ft_get_line(&s, rd, buff));
		rd = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_get_line(&s, rd, buff));
}
