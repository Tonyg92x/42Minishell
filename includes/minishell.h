/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/22 19:08:04 by aguay            ###   ########.fr       */
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
char		**split_entry(char *entry, int nb_node);
int			how_much_node(char *string);
void		analyse_entry(t_command_q *command_q, char **split_entry, int nb_node);
bool		is_white_space(char *string);
bool		quotes_incomplete(char *string, size_t *i);
bool		input_fd(t_command_q *command_q, char **split_entry, size_t *i);
bool		init_cmd(t_command *command, char **split_entry, size_t *i, size_t *length);
void		parse_builtins(t_command *command, char **split_entry, size_t *i);
bool		has_input(char **split_entry, size_t *i);
char		*has_heredoc(char **split_entry, size_t *i);
bool		run_heredoc(t_command_q *command_q, char **split_entry, size_t *i, char *delim);
bool		builtins_exept(t_command_q *command_q, char **split_entry, size_t *i, size_t *length);
size_t		how_much_node_in_command(char **split_entry);
char		**getHereDocEntry(char **split_entry, size_t *i, char *delim);
void		advanceInput(char **split_entry, size_t *i);
void		parse_output(t_command_q *command_q);


//	Builtins
bool		is_builtins(char *string);
void		ft_exit(t_command_q *command_q);

//	Commands fucntions
t_command	*last_command(t_command_q *command_q);
void		initialise_commands(t_command_q *command_q);
t_command	*new_command(t_command_q *command_q);
void		free_command(t_command	*command);
bool		command_exept(t_command_q *command, char **split_entry, size_t *i, size_t *length);
size_t		index_to_path(char **envp);
bool		path_is_valid(char *command, char **path, t_command_q *command_q);
void		analyse_link(t_command_q *command_q, char ** split_entry, size_t *i);

//	Environnement fonctions
char	**envp_init(char **envp);

//	Fonction pour libft ?
char	**ft_realloc(char **strings, char *str);


#endif