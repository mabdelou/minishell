/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:39:52 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/08 20:27:17 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "get_next_line.h"

typedef struct s_mini
{
	char	*fcl;
	char	*f_cmd;
	char	*cmd_path;
	char	**opt_args;
	char	*builtins;
	char	*cmd;
	char	**std_in;
	char	**std_out;
	char	**trunc;
	char	**limiter;
	char	**env;
	char	**order;
	char	**orlim;
	char	**f_ord;
	char	**f_o_d;
	char	*error;
	int		n_of_p;
	int		redi;
}				t_mini;

typedef struct s_built
{	
	char	**export;
	char	**envp;
	char	*swap;
	int		loop;
	int		loop2;
	int		num_of_strings;
	int		num_of_env_strings;
	int		num_of_vars;
	int		end_state;
	int		i;
	int		type;
	int		flag;
}			t_built;

typedef struct s_echo
{
	int	i;
	int	newline;
	int	*fds;
}				t_echo;

t_built				g_built;

typedef long long	t_ll;

# define RE1 ">"
# define RE2 "<"
# define RE3 ">>"
# define RE4 "<<"
# define PIPE "|"

# define ERR1 "<<<<"
# define ERR2 "><<"
# define ERR3 ">><"
# define ERR4 "><"
# define ERR5 ">>>"
# define ERR6 "<<>"
# define ERR7 "<>>"
# define ERR8 ">|"
# define ERR9 "<|"
//# define ERR10 "|"
//# define ERR11 "|"
# define ERR12 "||"
# define ERR13 "<<<"
# define ERR14 "<>"

// minishell.c
void	ft_minishell(t_mini *line, char **env, t_built *g_built);
int		ft_valide(char *cmd);

// minishell_util.c
int		ft_valide(char *cmd);
t_mini	*ft_init_line(t_mini *line, char *cmd, char **env);
void	ft_next_cmd(char **cmd);

// ft_signal.c
void	ft_sigint_handler(int sig);
void	ft_sigquit_handler(int sig);
void	ft_sig_handler(int sig);
void	ft_init_sig(t_built *g_built, int ac, char **av);

// ft_initialize.c
int		ft_initialize_util(t_mini *line, char **cmds, char **env);
int		ft_initialize_two(t_mini *line,
			char *cmd, t_built *g_built, char **cmds);
int		ft_initialize(t_mini *line, char *cmd, t_built *g_built);
void	ft_init(t_mini **line, int nbr, char **env);

//ft_initialize_util.c
t_mini	*ft_prevent_from_sig(t_mini *line, char **cmds);
int		ft_number_of_pipe(char *cmd);

// ft_between_pipes.c
int		ft_index_of_next_pipe(char *fcl, int i);
char	*ft_override_between_pipe(char *fcl, int i, int l);
char	*ft_between_pipes(char *fcl);

// ft_get_env.c
char	*ft_env_copy(char *env_cp, char *env);
char	*ft_get_env_var(char **env, char *env_var, char *home);

// ft_handle.c
int		ft_get_index_close_quote(char *cmd, int index, char c);
int		ft_between(char *cmd, int index);
int		ft_quote_error(char *cmd, int i);
int		ft_handle_quotes(t_mini *line, char *cmd, t_built *g_built);

// ft_check_cmd_err.c
int		ft_case_three(char **tab);
int		ft_case_case_one(t_mini *line);
int		ft_check_cmd_err(t_mini *line, char *cmd);

//ft_check_if_builtin
void	ft_check_if_builtin(t_mini *line, t_built *g_built, int loop);

// ft_check_cmd_err_two.c
int		ft_case_two_util_1(char *c, int i, int len);
int		ft_case_two_util_2(char *c, int i, int len);
int		ft_case_two_util_3(char *c, int i, int len);
int		ft_case_two(char *c, int i);

// ft_expand_util.c
char	*ft_get_env(char *cmd, int i);
char	*ft_get_env_val(char *env_n, char **env);
int		ft_exp_check(char c);

// ft_expand.c
char	*ft_get_expand(char *env_name, char **env);
char	*ft_expand_util_two(t_built *g_built, int *flag, char *exp);
int		ft_expand_util(t_mini *line, char **fcl, char *cmd, t_built *g_built);
char	*ft_expand(t_mini *line, char **fcl, char *cmd, t_built *g_built);

// ft_get_cmd_path.c
char	**ft_get_paths(char **env);
t_mini	ft_get_cmd_path(t_mini *line, char **env);

// ft_parse_redi.c
int		ft_parse(t_mini **line, int i, char *cmd, char **env);
int		ft_redirection(char *cmd);
t_mini	ft_parse_redi(t_mini *line, char **token, int j);
t_mini	*ft_parse_redi_util(t_mini *line, char **token, int index);
t_mini	*ft_parse_redi_util_two(t_mini *line, char **token, int index);

//ft_get_builtins.c
char	*ft_geg_builtins(char *cmd);

// ft_parse_cmd.c
char	**ft_push_std(char **std, char *token);
int		ft_is_redic(char *t);
t_mini	ft_parse_cmd(t_mini *line, char **token);
t_mini	ft_parse_cmd_util(t_mini *line, char **token, int index, int redi);
t_mini	ft_parse_cmd_util_two(t_mini *line, char **token, int index, int redi);

// ft_remove_quotes_from_cmd_and_builtins.c
char	*ft_rm_quotes(char *str);
void	ft_expand_init(char **c, int **flag, char **fcl);

// ft_handle_order
void	ft_handle_order(t_mini *line);

// libft utils
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t size);
char	**ft_split(char const *s, char c);
int		ft_odd_quote(char const *s, int index);
char	**ft_split_case(char const *s, char c);
char	**ft_split_str(char *str, char *charset);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcmp_case(char *s1, char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
t_ll	ft_atoi_l(const char *str);
char	*ft_itoa(int n);
int		ft_is_alpha_digit(char c);

// ft_prepare_to_split.c
char	*ft_remove_whitespace_util(char *cmd, int start, int end);
char	*ft_remove_whitespace(char *cmd);
char	**ft_return_whitespace(char **token);

// ft_push.c
void	ft_copy(char **line, char *token);
char	**ft_copy_table(char **line, char **temp, int i);
int		ft_free_a(char **line);
char	**ft_concat_str(char **temp, char **line, char *token);
char	**ft_realloc(char **line, char *token);

// ft_remove_outer_quotes.c
int		ft_handle_two_diff_quote(char *cmds, char *c, int j, int k);
char	*ft_handle_quotes_util(char *cmds, int k, char c);
char	**ft_remove_quotes(char **cmds);

// ft_add_space_between_redirections
char	*ft_adjust(char *token, int add);
int		ft_count_space(char *token);
char	*ft_add_space_besides(char *token);

// ft_free.c
char	**ft_free_tab(char **str, char *arg1, char *arg2);
void	ft_free_cmd(t_mini *line);

// builtins
// ft_get_env_var.c
char	*ft_get_env_var(char **env, char *env_var, char *home);

// ft_cd_util_four.c
t_built	*ft_initialize_env(t_mini *line, t_built *g_built);
void	ft_update_paths(t_built *g_built, char *oldpwd, int i);

// ft_cd_util_three.c
int		ft_check_path(char *path);
char	**ft_update_envp(char **envp, int i);
char	**ft_update_export(char **envp, char **export, char *oldpwd);
char	*ft_join_home_path(t_mini *line, t_built *g_built);
int		ft_go_to_path(t_mini *line, t_built *g_built);

// ft_cd_util_two.c
int		ft_file_out(t_mini *line);
void	ft_heredoc_util(char *g_line, char *lim);
int		ft_here_doc(t_mini *line);
int		ft_previous_dir(t_built *g_built);
int		ft_user_home(t_mini *line, t_built *g_built);

// ft_cd_util.c
int		ft_go_home(t_mini *line, t_built *g_built);
int		ft_print_error(int number, char *name);
int		ft_check_user_access(char *file, char *name, int flag);
int		ft_check_file_access(char *file, int flag);
int		ft_file_in(t_mini *line);

// ft_cd.c
char	*ft_replace(t_mini *line, char *path, char *var, char *srch);
int		ft_search_and_replace(t_mini *line, char *srch, t_built *g_built);
int		ft_user_home_case(t_mini *line, t_built *g_built);
int		ft_check_files(t_mini *line);
int		ft_cd(t_mini *line, t_built *g_built);

//ft_pwd_util.c
int		ft_print_pwd(int *fds, char *pwd, int i);

//ft_pwd.c
int		ft_pwd_util_two(char **tmp);
int		ft_pwd_util(t_mini *line);
int		ft_check_pwd_error(t_mini *line);
int		ft_pwd_util_three(t_mini *line, char *pwd, int i);
int		ft_pwd(t_mini *line, t_built *g_built);

//ft_echo_util.c
int		ft_valide_opt(t_mini line);
int		*ft_open_files(t_mini *line, int *fds, int index);
void	ft_newline(int i, int newline, int *fds);
int		ft_echo_util(t_mini *line, t_echo ech, t_built *g_built);

// ft_echo.c
char	*ft_echo_q(char *exp);
void	ft_echo_util_two(t_mini *line, t_echo echo);
int		ft_check_echo_files(t_mini *line);
int		ft_echo(t_mini *line, t_built *g_built);

//	ft_exit_util.c
int		ft_exit_util_tree(t_mini *line, int flag);

//	ft_exit.c
int		ft_exit_util(t_mini *line, t_built *g_built);
int		ft_exit(t_mini *line, t_built *g_built);

// readline
void	rl_replace_line(const char *test, int flag);

#endif