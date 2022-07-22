/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/22 07:17:30 by aguay            ###   ########.fr       */
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
	char				**cmd;
	char				*path;
	char				*input;
	char				**here_doc;
	char				*output;
	bool				append_mode;
	char				**envp;
	struct command_q	*queue_link;
}				t_command;

typedef struct command_q
{
	struct command	*start;
	size_t			nb_command;
	char			**envp;
}				t_command_q;

#endif