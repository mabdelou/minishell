/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:38:08 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/27 17:42:34 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		return_trorfo(char *str);
char	*ft_strjoin(char *s1, char*s2);
#endif
