/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/08 13:47:04 by anthony          ###   ########.fr       */
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
void		routine_prompt(t_flags *flags);
void		reset_flags(t_flags *flags);

//	Parsing functions
void		parsing(t_flags *flags, char *entry);
bool		ft_is_metacharacter(char c);
size_t		how_much_until_meta(char *string);
char		**error_exit(char **s_entry);
char		*get_word(char *string, size_t *i);
char		*get_char(char c);
char		**split_entry(char *entry);
int			how_much_node(char *string);


//	Builtins
void		ft_ls(char *path);

#endif