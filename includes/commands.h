/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/12 06:14:41 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef COMMANDS_H
# define COMMANDS_H

typedef struct command
{
	struct command		*next;
	struct command		*prev;
	char				**cmd;
	char				*path;
	bool				builtins;
	char				*input;
	char				*output;
	bool				append_mode;
	char				*delimiter;
}				t_command;

typedef struct command_q
{
	struct command	*start;
	int				nb_command;
	bool			valid_entry;
}				t_command_q;

#endif