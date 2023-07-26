/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:47:06 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/16 17:13:49 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	index_j;

	if (*needle == '\0')
		return ((char *)haystack);
	index = 0;
	while (haystack[index] && index < len)
	{
		index_j = 0;
		while (haystack[index + index_j] == needle[index_j])
		{
			index_j++;
			if (index + index_j > len)
				return (0);
			if (needle[index_j] == '\0')
				return (((char *)haystack) + index);
		}
		index++;
	}
	return (0);
}
