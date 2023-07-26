/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_err_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:43:12 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 14:15:41 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_err_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:37:31 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 13:39:08 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_case_two_util_1(char *c, int i, int len)
{
	if (len >= i + 4 && ft_strncmp(ERR1, c + i, 4) == 0)
		return (write(2, "bash: parse error near `<'\n", 27));
	if (len >= i + 3 && ft_strncmp(ERR2, c + i, 3) == 0)
		return (write(2, "bash: parse error near `<'\n", 27));
	if (len >= i + 3 && ft_strncmp(ERR3, c + i, 3) == 0)
		return (write(2, "bash: parse error near `<'\n", 27));
	if (len >= i + 2 && ft_strncmp(ERR4, c + i, 2) == 0)
		return (write(2, "bash: parse error near `<'\n", 27));
	return (0);
}

int	ft_case_two_util_2(char *c, int i, int len)
{
	if (len >= i + 3 && ft_strncmp(ERR5, c + i, 3) == 0)
		return (write(2, "bash: parse error near `>'\n", 27));
	if (len >= i + 3 && ft_strncmp(ERR6, c + i, 3) == 0)
		return (write(2, "bash: parse error near `>'\n", 27));
	if (len >= i + 3 && ft_strncmp(ERR7, c + i, 3) == 0)
		return (write(2, "bash: parse error near `>'\n", 27));
	if (len >= i + 3 && ft_strncmp(ERR13, c + i, 3) == 0)
		return (write(2, "bash: here string doesnt supported\n", 35));
	if (len >= i + 2 && ft_strncmp(ERR14, c + i, 2) == 0)
		return (write(2, "bash: read-write redic doesnt supported\n", 40));
	return (0);
}

int	ft_case_two_util_3(char *c, int i, int len)
{
	if (len >= i + 2 && ft_strncmp(ERR8, c + i, 2) == 0)
		return (write(2, "bash: parse error near `\\n'\n", 29));
	if (len >= i + 2 && ft_strncmp(ERR9, c + i, 2) == 0)
		return (write(2, "bash: parse error near `|'\n", 27));
	if (len >= i + 2 && ft_strncmp(ERR12, c + i, 2) == 0)
		return (write(2, "bash: found double pipe\n", 24));
	return (0);
}

int	ft_case_two(char *c, int i)
{
	int	len;

	len = ft_strlen(c);
	while (c[i])
	{
		if (c[i] == '|' && c[i + 1] == '|')
			return (write(2, "syntax error near unexpected token `||'\n", 40));
		if (ft_case_two_util_1(c, i, len) != 0)
			return (1);
		if (ft_case_two_util_2(c, i, len) != 0)
			return (1);
		if (ft_case_two_util_3(c, i, len) != 0)
			return (1);
		i++;
	}
	if (i > 0)
		if (c[i - 1] == '>' || c[i - 1] == '<')
			return (write(2, "bash: parse error near `\\n'\n", 28));
	return (0);
}
