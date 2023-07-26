/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:44:58 by mabdelou          #+#    #+#             */
/*   Updated: 2021/12/01 15:28:57 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cutstr(char *s)
{
	int		a;
	char	*str;
	int		size;

	size = ft_strlenn(s);
	a = 0;
	while (s[a] != '\0' && s[a] != '\n')
		a++;
	if (!s[a])
	{
		free(s);
		return (NULL);
	}
	size = size - a;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	size = -1;
	while (s[a++])
		str[++size] = s[a];
	str[size] = '\0';
	free(s);
	return (str);
}

char	*ft_cpy(char *src)
{
	char	*dest;
	int		j;

	j = 0;
	if (!src[j])
		return (NULL);
	while (src[j] != '\n' && src[j])
		j++;
	if (src[j] == '\n')
		j++;
	dest = (char *)malloc(sizeof(char) * (j + 1));
	if (dest == NULL)
		return (NULL);
	j = -1;
	while (src[++j] && src[j] != '\n')
		dest[j] = src[j];
	if (src[j] == '\n')
	{
		dest[j] = '\n';
		dest[j + 1] = 0;
	}
	else
		dest[j] = '\0';
	return (dest);
}

char	*getv2(char *newstr, int fd)
{
	char	*buffer;
	int		words;

	words = 1;
	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		return (NULL);
	while (return_trorfo(newstr) && words != 0)
	{
		words = read(fd, buffer, 1);
		if (words == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[words] = '\0';
		newstr = ft_strjoinn(newstr, buffer);
	}
	free(buffer);
	return (newstr);
}

char	*get_next_line(int fd)
{
	char		*strcpy;
	static char	*newstr;

	if (fd < 0)
		return (NULL);
	newstr = getv2(newstr, fd);
	if (!newstr)
		return (NULL);
	strcpy = ft_cpy(newstr);
	newstr = ft_cutstr(newstr);
	return (strcpy);
}
