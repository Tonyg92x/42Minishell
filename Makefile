# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguay <aguay@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 08:51:26 by aguay             #+#    #+#              #
#    Updated: 2022/06/10 15:38:34 by aguay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## -----  NAME OF THE PROGRAMM ----- ##
NAME 			= minishell

## ----- CHOOSE COMPILER AND FLAGS ----- ##
CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

## ----- PATH TO FOLDERS ----- ##
SRCS_DIR		= srcs/

OBJ_DIR			= obj/

INCLUDE_DIR		= includes/

LIB_DIR			= $(LIBFT_DIR)lib/

PARSING_DIR		= $(SRCS_DIR)parsing

BUILTINS_DIR	= $(SRCS_DIR)builtins

PROMPT_DIR		= $(SRCS_DIR)prompt

MAIN_DIR		= $(SRCS_DIR)main

ENGINE_DIR		= $(SRCS_DIR)engine

## ----- LIBFT PATH ----- ##

LIBFT_DIR		= $(SRCS_DIR)libft/

LIBFT_OBJ		= $(SRCS_DIR)libft/obj/

LIBFT_INC		= $(SRCS_DIR)libft/includes/

## ----- FILES ----- ##
SRCS_FILES		=						\

PARSING_FILES	=						\
			parsing.c					\
			parsing_utils.c				\
			split_entry.c				\
			data_analyser.c				\

BUILTINS_FILES	=						\
			cd.c						\
			echo.c						\
			env.c						\
			exit.c						\
			export.c					\
			ls.c						\
			pwd.c						\
			unset.c						\

PROMPT_FILES	=						\
			prompt.c					\

MAIN_FILES		=						\
			main.c						\
			init.c						\

ENGINE_FILES	=						\
			exec1.c						\

## -----  if to compile differently on other os ----- ##
## ifeq ($(shell uname), Linux)
## endif

## ----- .C TO .O CONVERT ----- ##

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I $(LIB_DIR) -I $(LIBFT_INC) -c $< -o $@

## ----- ADDPREFIX TO FILES ----- ##

BUILTINS_SRCS	=	$(addprefix $(BUILTINS_DIR), $(BUILTINS_FILES))
PROMPT_SRCS		=	$(addprefix $(PROMPT_DIR), $(PROMPT_FILES))
PARSING_SRCS	=	$(addprefix $(PARSING_DIR), $(PARSING_FILES))
MAIN_SRCS		=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))
ENGINE_SRCS		=	$(addprefix $(ENGINE_DIR), $(ENGINE_FILES))

OBJS			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJ_FILES	=		$(SRCS_FILES:.c=.o) $(PARSING_FILES:.c=.o) $(BUILTINS_FILES:.c=.o) $(PROMPT_FILES:.c=.o) $(MAIN_FILES:.c=.o) $(ENGINE_FILES:.c=.o)

VPATH			=	$(SRCS_DIR) $(PARSING_DIR) $(BUILTINS_DIR) $(PROMPT_DIR) $(MAIN_DIR) $(ENGINE_DIR)

#--------------------------------------------------------------#

## ----- TOOLS AND COLORS ----- ##
RM				= rm -rf
NO_PRINT		= --no-print-directory
RED 			= \033[31m
GREEN 			= \033[32m
YELLOW 			= \033[33m
BLUE 			= \033[34m
PINK 			= \033[35m
AQUA 			= \033[36m
GREY 			= \033[37m
UNDERLINE 		= \033[4m
NORMAL 			= \033[0m

LIBFT			= make -C $(LIBFT_DIR)

## ----- ALL ACTION DEPENDENCIES AND RECIPE FOR MAIN PROGRAM ----- ##

all: obj $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(LIBFT)
	$(CC) $(OBJS) $(LIBFT_DIR)libft.a $(LIB_DIR)libreadline.a $(LIB_DIR)libhistory.a -lcurses -lreadline -o $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

## ----- make options ----- #
debug: CFLAGS += -g
debug: obj $(NAME)

opti: CFLAGS += -O3
opti: obj $(NAME)

leak: obj $(NAME)
	@valgrind ./minishell

## ----- CLEAN COMMANDS ----- ##
clean:
	$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf libft/libft.a

re: fclean all

.PHONY: all clean fclean re
