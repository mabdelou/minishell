/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geg_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:02:34 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/04/30 22:03:00 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_geg_builtins(char *cmd)
{
	int	i;

	i = 0;
	if (ft_strcmp_case("echo", cmd) == 0)
		return ("echo");
	if (ft_strcmp_case("cd", cmd) == 0)
	{
		if (ft_strcmp("cd", cmd) == 0)
			return ("cd");
		return ("Cd");
	}
	if (ft_strcmp_case("pwd", cmd) == 0)
		return ("pwd");
	if (ft_strcmp("export", cmd) == 0)
		return ("export");
	if (ft_strcmp("unset", cmd) == 0)
		return ("unset");
	if (ft_strcmp_case("env", cmd) == 0)
		return ("env");
	if (ft_strcmp("exit", cmd) == 0)
		return ("exit");
	return (NULL);
}
