# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 19:39:22 by tel-bouh          #+#    #+#              #
#    Updated: 2022/05/08 20:30:10 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	./parssing/minishell.c	\
		./parssing/minishell_util.c	\
		./parssing/ft_split.c	\
		./parssing/ft_split_case.c	\
		./parssing/ft_split_case_util.c	\
		./parssing/ft_handle_quotes.c	\
		./parssing/ft_split_str.c	\
		./parssing/ft_parse_redi.c \
		./parssing/ft_expand.c	\
		./parssing/ft_expand_util.c	\
		./parssing/ft_between_pipes.c	\
		./parssing/ft_strjoin.c	\
		./parssing/ft_strncmp.c	\
		./parssing/ft_check_cmd_err.c	\
		./parssing/ft_parse_cmd.c	\
		./parssing/ft_strdup.c \
		./parssing/ft_get_cmd_path.c	\
		./parssing/ft_prepare_to_split.c	\
		./parssing/ft_push.c	\
		./parssing/ft_add_space_between_redirection.c \
		./parssing/ft_check_cmd_err_two.c	\
		./parssing/ft_free.c	\
		./parssing/ft_initialize.c	\
		./parssing/ft_initialize_util.c	\
		./parssing/ft_itoa.c \
		./parssing/ft_handle_order.c \
		./parssing/ft_atoi.c	\
		./parssing/ft_get_env_var.c \
		./parssing/ft_strcmp.c \
		./parssing/ft_remore_quotes_from_cmd_and_builtins.c \
		./parssing/ft_remore_outer_quotes.c \
		./parssing/ft_signal.c \
		./parssing/ft_get_builtins.c \
		./parssing/ft_is_alpha_digit.c \
		./execution/ft_utilis.c	\
		./execution/make_pipes.c	\
		./execution/wait_pross.c	\
		./execution/type_of_cmd_I.c	\
		./execution/type_of_cmd_II.c	\
		./execution/type_of_cmd_III.c	\
		./execution/do_some_malloc.c	\
		./execution/close_fds.c	\
		./execution/get_next_line/get_next_line.c \
		./execution/get_next_line/get_next_line_utils.c \
		./execution/ft_strncmp_exe.c	\
		./execution/ft_putstr_fd.c	\
		./execution/heredoc.c	\
		./execution/ft_cmd_1_utilis_I.c	\
		./execution/ft_cmd_1_utilis_II.c	\
		./execution/ft_cmd_2_utilis_I.c	\
		./execution/ft_cmd_2_utilis_II.c	\
		./execution/ft_cmd_2_utilis_III.c	\
		./execution/ft_cmd_2_utilis_IV.c	\
		./execution/ft_cmd_2_utilis_V.c	\
		./execution/ft_cmd_3_utilis_I.c	\
		./execution/ft_cmd_3_utilis_II.c	\
		./execution/ft_cmd_3_utilis_III.c	\
		./execution/ft_cmd_3_utilis_IV.c	\
		./execution/ft_cmd_3_utilis_V.c	\
		./execution/ft_cmd_3_utilis_VI.c	\
		./execution/ft_cmd_3_utilis_VII.c	\
		./execution/heredoc_type_of_cmd_I.c	\
		./execution/heredoc_type_of_cmd_II.c	\
		./execution/heredoc_type_of_cmd_II_v2.c	\
		./execution/heredoc_type_of_cmd_III.c	\
		./execution/calc_num_of_heredoc.c	\
		./execution/open_std_in_files.c	\
		./execution/open_std_out_files.c	\
		./execution/no_cmd_no_output.c	\
		./builtin/ft_builtin.c	\
		./builtin/ft_utilis_I.c	\
		./builtin/ft_utilis_II.c	\
		./builtin/ft_utilis_III.c	\
		./builtin/ft_utilis_IV.c	\
		./builtin/ft_utilis_V.c	\
		./builtin/ft_utilis_VI.c	\
		./builtin/ft_cd_util.c	\
		./builtin/ft_cd.c	\
		./builtin/ft_cd_util_two.c  \
		./builtin/ft_cd_util_three.c  \
		./builtin/ft_cd_util_four.c  \
		./builtin/ft_echo.c	\
		./builtin/ft_echo_util.c \
		./builtin/ft_exit.c \
		./builtin/ft_exit_util.c \
		./builtin/ft_pwd.c \
		./builtin/ft_pwd_util.c 

OBJS = $(SRCS:.c=.o)

CC = cc

INCLUDES = ./

FLAGS = -Wall -Wextra -Werror

BRAW_FLAGS =  -lreadline -L /goinfre/$(USER)/.brew/opt/readline/lib -I/goinfre/$(USER)/.brew/opt/readline/include

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(BRAW_FLAGS) $(OBJS) -o $(NAME)

.c.o :
	$(CC) -c $(FLAGS)  $< -o $@ 

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
