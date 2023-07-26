/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:57:09 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 17:41:52 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution/exe_header.h"
#include "../builtin/builtin.h"
#include "minishell.h"

int	ft_valide(char *cmd)
{
	int	i;

	if (cmd == NULL)
		return (-1);
	else if (ft_strlen(cmd) == 0)
		return (0);
	i = 0;
	while ((cmd[i] >= 9 && cmd[i] <= 13) || cmd[i] == 32)
		i++;
	if (cmd[i] == 0)
		return (0);
	if (cmd[i] < 32 && cmd[i] > 126)
		return (0);
	return (1);
}

t_mini	*ft_init_line(t_mini *line, char *cmd, char **env)
{
	int		nbr_of_pipe;

	nbr_of_pipe = ft_number_of_pipe(cmd);
	line = NULL;
	line = (t_mini *) malloc(sizeof(t_mini) * nbr_of_pipe + 1);
	ft_init(&line, nbr_of_pipe, env);
	return (line);
}

void	ft_next_cmd(char **cmd)
{
	free(cmd[0]);
	cmd[0] = NULL;
	g_built.flag = 0;
}
