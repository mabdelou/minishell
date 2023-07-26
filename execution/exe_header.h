/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:00:28 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/22 20:00:32 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_HEADER_H
# define EXE_HEADER_H

# include <string.h> 
# include <stdbool.h>
# include <errno.h>
# include "../parssing/minishell.h"

typedef struct s_node
{
	int		file1;
	int		file2;
	int		fd[2];
	int		h_fd[4];
	int		difirent;
	char	*heredoc_limit;
	char	*ptr;
	char	*ptr2;
	int		*fds;
	int		*h_fds;
	int		loop;
	int		pid;
	int		*pids;
	int		num_of_cmd;
	int		num_of_hr;
	int		n_std_in_c;
	int		n_std_out_c;
	int		n_std_in_hr;
	int		n_std_out_hr;
	int		a;
	int		*pids_ads;
	int		n_pipe;
}	t_node;

int		ft_type_of_cmd_1(t_mini *data, t_built *g_built);
int		ft_type_of_cmd_2(t_mini *data, t_built *g_built, int nbr_of_cmd);
int		ft_type_of_cmd_3(t_mini *data, t_built *g_built, int nbr_of_cmd);
int		ft_check_nbr_of_cmd(t_mini *data, t_built *g_built, int nbr_of_cmd);
char	**ft_get_args(t_mini *data, int nbr_of_pipe);
void	ft_open_std_in_files(t_mini *data, t_node *node, int loop);
void	ft_open_std_out_files(t_mini *data, t_node *node, int loop);
void	ft_open_std_out_files_for_built(t_mini *data, t_node *node, int loop);
void	ft_no_cmd_no_output(t_mini *data, t_node *node);
void	close_fd(t_node *node);
void	close_fds(t_node *node);
void	close_h_fd(t_node *node);
void	close_h_fds(t_node *node);
void	wait_pross(t_node *node, t_built *g_built);
int		ft_do_some_malloc(t_node *node, int type);
int		ft_do_some_malloc_v2(t_node *node, int type);
void	ft_free_some_ptrs(t_node *node, int type);
int		make_pipes(t_node *node);
int		make_hr_pipes(t_node *node, int type);
void	ft_putstr_fd(char *s, int fd);
int		ft_heredoc_type_of_cmd_1(t_node *node, t_mini *data, t_built *g_built);
void	ft_heredoc_1(t_node *node, t_mini *data, t_built *g_built);
int		ft_heredoc_type_of_cmd_2(t_node *node, t_mini *data,
			t_built *g_built, int nbr_of_cmd);
void	ft_heredoc_2(t_node *node, t_mini *data, t_built *g_built);
void	ft_drr_2_v2(t_node *node, t_built *g_built, t_mini *data);
void	ft_drr_2_v3(t_node *node, t_built *g_built, t_mini *data);
int		ft_heredoc_type_of_cmd_3(t_node *node, t_mini *data,
			t_built *g_built, int nbr_of_cmd);
void	ft_heredoc_3(t_node *node, t_mini *data, t_built *g_built);
int		ft_strncmp_exe(const char	*s1,	const char	*s2);
int		ft_strncmp_magiscule( const char *s1, const char *s2);
int		ft_calc_num_of_heredoc(t_mini *data);
void	ft_execve_cmd(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_lr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_rr_lr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_hr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_hr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1_lr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1_lr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1_hr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1_hr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2_lr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2_lr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2_hr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2_hr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1_lr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1_lr_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1_hr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_1_hr_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2_lr_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2_lr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2_hr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2_hr_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_2__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3_lr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3_lr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3_hr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3_hr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4_lr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4_lr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4_hr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4_hr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5_lr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5_lr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5_hr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5_hr_rr(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3_lr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3_lr_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3_hr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_3_hr_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4_lr_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4_lr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4_hr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_4_hr_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5_lr_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5_lr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5_hr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_cmd_5_hr_rr__(t_mini *data, t_built *g_built, t_node *node);
void	ft_execve_builtin(t_mini *data, t_built *g_built, t_node *node);

#endif
