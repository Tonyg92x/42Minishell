/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/08 15:33:42 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef COMMANDS_H
# define COMMANDS_H

typedef struct command
{
	bool				valid;
	struct command		*next;
	struct command		*prev;
	bool				builtins;
	char				**here_doc;
	char				**cmd;
	char				*path;
	char				*input;
	char				*output;
	bool				append_mode;
	char				*link_next;
	char				**envp;
	struct command_q	*queue_link;
}				t_command;

typedef struct command_q
{
	struct command	*start;
	size_t			nb_command;
	bool			valid_entry;
	char			**envp;
}				t_command_q;

#endif