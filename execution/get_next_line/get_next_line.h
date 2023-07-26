/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:47:26 by mabdelou          #+#    #+#             */
/*   Updated: 2021/12/01 15:29:17 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlenn(char *s);
int		return_trorfo(char *str);
char	*ft_strjoinn(char *s1, char*s2);
#endif
