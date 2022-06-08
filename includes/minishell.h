/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/08 10:32:14 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "commands.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdbool.h>
# include <dirent.h>

typedef struct s_flags
{
	bool	builtins;
	bool	command;
	bool	input;
	bool	output;
	bool	exit;
	size_t	nb_command;
}			t_flags;


//	Engine
char		*routine_prompt(void);
void		reset_flags(t_flags *flags);

//	Parsing functions
bool		ft_is_metacharacter(char c);
void		parsing(t_flags *flags, char *entry);

//	Builtins
void		ft_ls(char *path);

#endif