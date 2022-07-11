/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/11 13:28:41 by aguay            ###   ########.fr       */
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
void		engine(t_command_q *command_q);
void		builtins_engine(t_command	*command);
void		command_engine(t_command *command);

//	Parsing functions
bool		parsing(t_command_q *command_q, char *entry);
char		**split_entry(char *entry, int nb_node);
char		*get_word(char *string, size_t *i);
char		*get_char(char c, size_t *i);
bool		analyse_entry(t_command_q *command_q, char ***split_entry, int nb_node);
bool		command_exept(t_command_q *command, char **split_entry, size_t *i, size_t *length);
bool		init_cmd(t_command *command, char **split_entry, size_t *i, size_t *length);
bool		builtins_exept(t_command_q *command_q, char **split_entry, size_t *i, size_t *length);
void		parse_builtins(t_command *command, char **split_entry, size_t *i);
void		ft_clear(char ***split_entry, size_t *len, size_t *temp);
void		ft_removeSpace(char ***split_entry, size_t *len);

//	Redirection
bool		ft_redir(t_command *command, char ***split_entry, size_t *length, size_t *i);
bool		ft_input(t_command *command, size_t *temp, size_t *len, char ***split_entry);
bool		ft_inputHD(t_command *command, size_t *temp, size_t *len, char ***split_entry);
bool		parse_output(t_command *command, char ***, size_t *len, size_t *i);
bool		ft_append(t_command *command, size_t *temp, size_t *len, char ***split_entry);
bool		ft_output(t_command *command, size_t *temp, size_t *len, char ***split_entry);

//	Quotes
bool	ft_parseQuotes(t_command *command, char ***split_entry, size_t *len, size_t *i);

//	Utils
bool		ft_is_metacharacter(char c);
size_t		word_size(char *string);
int			how_much_node(char *string);
bool		is_white_space(char *string);
char		**error_exit(char **s_entry);
size_t		how_much_node_in_command(char **split_entry);

//	Builtins
bool		is_builtins(char *string);
void		builtin_cd(t_command *command);
void		builtin_echo(t_command *command);
void		builtin_env(t_command *command);
void		builtin_exit(t_command *command);
void		builtin_export(t_command *command);
void		builtin_pwd(t_command *command);
void		builtin_unset(t_command *command);

//	Commands fucntions
t_command	*last_command(t_command_q *command_q);
void		initialise_commands(t_command_q *command_q);
t_command	*new_command(t_command_q *command_q);
void		free_command(t_command	*command);
size_t		index_to_path(char **envp);
bool		path_is_valid(char *command, char **path, t_command_q *command_q);
void		analyse_link(t_command_q *command_q, char ** split_entry, size_t *i);

//	Environnement fonctions
char		**envp_init(char **envp);
char		*find_variable(char *str, char **envp);
int			find_variable_index(char *str, char **envp);
void		change_pwd(char *pwd, char **envp);

//	Fonction pour libft ?
char		**ft_realloc(char **strings, char *str);
char		**ft_revRealloc(char **array, void *ptr);


#endif