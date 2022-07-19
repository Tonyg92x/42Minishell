/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_analyser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/19 15:45:00 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	parsing_error(char **split_entry, size_t *i, size_t *length,
	t_command_q *command_q)
{
	t_command	*command;
	int			x;

	x = 0;
	command = last_command(command_q);
	init_cmd(command, split_entry, i, length);
	command->valid = false;
	return (false);
}

//	Look if there is a builtins command
bool	builtins_exept(t_command_q *command_q, char **split_entry,
	size_t *i, size_t *length)
{
	t_command	*command;

	if (!is_builtins(split_entry[(*i)]))
		return (false);
	command = last_command(command_q);
	command->builtins = true;
	if (!init_cmd(command, split_entry, i, length))
		command->valid = false;
	return (true);
}

//	Parse the word to understand the command and his agruments.
static bool	parse_command(t_command_q *command_q, char **split_entry,
	size_t *i, size_t *length)
{
	size_t		i_limit;

	i_limit = (*i) + (*length);
	while (split_entry[(*i)] && (*i) < i_limit)
	{
		if (builtins_exept(command_q, split_entry, i, length))
			return (true);
		else if (command_exept(command_q, split_entry, i, length))
			return (true);
		else
			return (parsing_error(split_entry, i, length, command_q));
	}
	return (false);
}

size_t	how_much_node_in_command(char **split_entry)
{
	size_t	index;

	index = 0;
	while (split_entry[index] && split_entry[index][0] != '|' )
		index++;
	return (index);
}

bool	analyse_entry(t_command_q *command_q, char ***split_entry, int nb_node)
{
	size_t		i;
	size_t		length;
	t_command	*command;

	i = 0;
	while ((*split_entry)[i] && (int)i < nb_node)
	{
		command = new_command(command_q);
		command_q->nb_command++;
		length = how_much_node_in_command(&(*split_entry)[i]);
		if (!ft_redir(command, split_entry, &length, &i))
			return (false);
		parse_command(command_q, (*split_entry), &i, &length);
		if (!expand_envar(command))
			return (false);
		if (!ft_parse_quotes(command, split_entry))
			return (false);
		if (command_q->nb_command > 0 && (*split_entry)[i])
			analyse_link(command_q, (*split_entry), &i);
	}
	return (true);
}
