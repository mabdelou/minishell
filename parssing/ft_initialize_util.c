/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:02:20 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/06 15:03:34 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	*ft_prevent_from_sig(t_mini *line, char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i] != NULL)
		i++;
	if (i == 0)
		i = 1;
	line[i].fcl = NULL;
	return (line);
}

int	ft_number_of_pipe(char *cmd)
{
	char	**str;
	int		i;

	str = NULL;
	i = 0;
	str = ft_split_case(cmd, '|');
	if (str == NULL)
		return (0);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	if (i == 0)
		return (1);
	return (i);
}
