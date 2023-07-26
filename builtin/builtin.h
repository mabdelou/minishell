/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:19:30 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/23 14:19:32 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <string.h> 
# include <stdbool.h>
# include <limits.h>
# include "../parssing/minishell.h"

int		ft_export(t_mini *data, t_built *g_built, int loop);
int		ft_unset(t_mini *data, t_built *g_built, int loop);
void	ft_env(t_mini *data, t_built *g_built, int loop);
int		ft_isalpha(int a, int loop);
int		ft_strlen_who_big(char *s1, char *s2, char a);
int		ft_iseagal(char *str);
int		ft_check_var(t_mini *data, int a, int loop);
void	ft_envlen(t_mini *data, t_built *g_built, int loop);
void	ft_exelen(t_mini *data, t_built *g_built, int loop);
void	ft_exportdup(t_mini *data, t_built *g_built, int loop);
char	*ft_strdup_qoute(const char *s1, int num_of_qoute);
void	ft_change_shlvl(t_mini *line, t_built *g_built);
void	ft_print_export(t_mini *data, t_built *g_built, int loop);
void	ft_sort_export(t_mini *data, t_built *g_built);
void	ft_check_export(t_mini *data, t_built *g_built, int b, int loop);
void	ft_check_export_two(t_mini *data, int loop, int a, int b);
void	ft_check_export_v2(t_mini *data,
			t_built *g_built, int a, int b);
void	ft_print_env(t_mini *data, t_built *g_built, int loop);
void	ft_envdup(t_mini *data, t_built *g_built, int loop);
void	ft_free_env(t_mini *data, t_built *g_built);
int		ft_check_expert_before_rm(t_mini *data,
			t_built *g_built, int b, int loop);
int		ft_calc_args(t_mini *data, int loop);
int		ft_strncmp_built(const char	*s1,	const char	*s2,	size_t n);
size_t	ft_strlen_to(const char *str, char a);
char	**ft_bzero(char **st, size_t len);
char	**ft_delvar(t_mini *data, t_built *g_built, int b, int loop);
char	**ft_addvar(t_mini *data, t_built *g_built, int b, int loop);

#endif
