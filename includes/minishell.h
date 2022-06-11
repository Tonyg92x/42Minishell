/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/11 06:58:48 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "commands.h"
# include "parsing.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdbool.h>
# include <dirent.h>

//	Engine
void		routine_prompt(t_command_q *command_q);

//	Parsing functions
void		parsing(t_command_q *command_q, char *entry);
bool		ft_is_metacharacter(char c);
size_t		word_size(char *string);
char		**error_exit(char **s_entry);
char		*get_word(char *string, size_t *i);
char		*get_char(char c);
char		**split_entry(char *entry);
int			how_much_node(char *string);
void		analyse_entry(t_command_q *command_q, char **split_entry);
bool		white_space(char *string, size_t *i);
bool		quotes_incomplete(char *string, size_t *i);

//	Builtins
void		ft_ls(char *path);

//	Commands fucntions
void	initialise_commands(t_command_q *command_q);
void	initialise_command_list(t_command_q *command_q);

#endif