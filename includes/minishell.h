/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/19 14:14:57 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "commands.h"
# include "parsing.h"
# include "environnement.h"
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
char		**split_entry(char *entry, int nb_node);
int			how_much_node(char *string);
void		analyse_entry(t_command_q *command_q, char **split_entry, int nb_node);
bool		is_white_space(char *string);
bool		quotes_incomplete(char *string, size_t *i);
bool		input_fd(t_command_q *command_q, char **split_entry, size_t *i);
bool		init_cmd(t_command *command, char **split_entry, size_t *i, size_t *length);
void		parse_builtins(t_command *command, char **split_entry, size_t *i);

//	Builtins
bool		is_builtins(char *string);
void		ft_ls(char *path);

//	Commands fucntions
t_command	*last_command(t_command_q *command_q);
void		initialise_commands(t_command_q *command_q);
t_command	*new_command(t_command_q *command_q);
void		free_command(t_command	*command);
void		get_command(t_command *command, char **split_entry, size_t *i);
bool		command_is_valid(t_command *command, char **split_entry, size_t *i);

//	Environnement fonctions
bool		envp_init(t_envp *envp);

#endif