/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:16:49 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 20:21:09 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_pipe(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '|')
		return (1);
	return (0);
}

int	ft_strlen_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_case_three(char **tab)
{
	int	i;
	int	j;

	if (ft_is_pipe(tab[0]))
		return (write(2, "bash: a pipe starts the line\n", 29));
	j = ft_strlen_tab(tab);
	i = 0;
	while (tab[i])
	{
		if (ft_is_redic(tab[i]) && tab[i + 1] == NULL)
			return (write(2, "bash: parse error near `\\n'\n", 28));
		if (ft_is_redic(tab[i]) && ft_is_pipe(tab[i + 1]))
			return (write(2, "bash: parse error near `|'\n", 27));
		if (ft_is_pipe(tab[i]) && ft_is_pipe(tab[i + 1]))
			return (write(2, "bash: found double pipe\n", 24));
		if (ft_is_pipe(tab[i]) && tab[i][1] == 0 && tab[i + 1] == NULL)
			return (write(2, "bash: sigle pipe at the end of line\n", 36));
		if (i < j - 1 && ft_is_redic(tab[i]) && ft_is_redic(tab[i + 1]))
			return (write(2, "bash: parse error near `>'\n", 27));
		if (i < j - 2 && ft_is_redic(tab[i])
			&& ft_is_redic(tab[i + 1]) && ft_is_redic(tab[i + 2]))
			return (write(2, "bash: parse error near `>'\n", 27));
		i++;
	}
	return (0);
}

int	ft_case_one(t_mini *line)
{
	char	*c;
	int		i;
	int		len;
	char	*err1;

	err1 = "bash: syntax error near unexpected token `newline'\n";
	c = line->fcl;
	i = 0;
	if (c == NULL)
		return (0);
	len = ft_strlen(c);
	while (c[i] && c[i] == ' ')
		i++;
	if (i < len && (c[i] == '>' || c[i] == '<') && c[i + 1] == 0)
		return (write(2, err1, 51));
	else if (i <= len - 2 && c[i] == '>' && c[i + 1] == '>' && c[i + 2] == 0)
		return (write(2, err1, 51));
	else if (i <= len -2 && c[i] == '<' && c[i + 1] == '<' && c[i + 2] == 0)
		return (write(2, err1, 51));
	else if (i <= len -2 && c[i] == '<' && c[i + 1] == '>' && c[i + 2] == 0)
		return (write(2, err1, 51));
	else if (i <= len - 1 && c[i] == '|' && c[i + 1] == 0)
		return (write(2, "bash: syntax error near unexpected token `|'\n", 45));
	return (0);
}

int	ft_check_cmd_err(t_mini *line, char *cmd)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split_str(cmd, " \t");
	if (tab && ft_case_three(tab))
	{
		ft_free_tab(tab, NULL, NULL);
		return (1);
	}
	ft_free_tab(tab, NULL, NULL);
	if (ft_case_one(line) || ft_case_two(cmd, i))
		return (1);
	return (0);
}
