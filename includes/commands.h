/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roxannefournier <roxannefournier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/22 10:30:47 by roxannefour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef COMMANDS_H
# define COMMANDS_H

typedef struct command
{
	struct command		*next;
	struct command		*prev;
	bool				builtins;
	char				**here_doc;
	char				**cmd;
	char				*path;
	char				*input;
	char				*output;
	char				*link_next;

}				t_command;

typedef struct command_q
{
	struct command	*start;
	int				nb_command;
	bool			valid_entry;
	char			**envp;
}				t_command_q;

#endif