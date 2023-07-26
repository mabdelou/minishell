/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:02:16 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/20 22:05:04 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);
void			ft_concat(char **dest, char **src, int len);
void			ft_copy_str(char **dest, char **src, size_t len);
size_t			ft_strlen_g(const char *s);
int				ft_index_of(char *s, char c);
int				ft_strchar(char *s, int c);

#endif
