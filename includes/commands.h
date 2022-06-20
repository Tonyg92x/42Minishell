/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/20 11:37:54 by aguay            ###   ########.fr       */
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
	bool				append_mode;
	char				*delimiter;
	char				**cmd;
	char				*path;
	char				*input;
	char				*output;

}				t_command;

typedef struct command_q
{
	struct command	*start;
	int				nb_command;
	bool			valid_entry;
	char			**envp;
}				t_command_q;

#endif