/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_analyser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/20 13:09:06 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

//	Look if there is a builtins command
static bool	builtins_exept(t_command_q *command_q, char **split_entry, size_t
	*i, size_t *length)
{
	t_command	*command;

	if (!is_builtins(split_entry[(*i)]))
		return (false);
	command = new_command(command_q);
	command->builtins = true;
	if (!init_cmd(command, split_entry, i, length))
	{
		free_command(command);
		return (false);
	}
	return (true);
}

//	Look if there is a command.
// static bool	simple_command(t_command_q *command_q)
// {
	
// }

//	Parse the word to understand the command and his agruments.
static bool	parse_command(t_command_q *command_q, char **split_entry, size_t
	*i, size_t *length)
{
	size_t		i_limit;

	i_limit = (*i) + (*length);
	while (split_entry[(*i)] && (*i) < i_limit)
	{
		if (is_white_space(split_entry[(*i)]))
		{
			while (is_white_space(split_entry[(*i)]))
				(*i)++;
		}
		else if (builtins_exept(command_q, split_entry, i, length))
			return (true);
		else if (command_exept(command_q, split_entry, i, length))
			return (true);
		else
		{
			while (split_entry[(*i)] && (*i) < i_limit)
				(*i)++;
		}
	}
	if (is_white_space(split_entry[(*i)]))
	{
		while (is_white_space(split_entry[(*i)]))
			(*i)++;
	}
	return (false);
}

static size_t	how_much_node_in_command(char **split_entry)
{
	size_t	index;

	index = 0;
	while (split_entry[index] && split_entry[index][0] != 
			'|' && split_entry[index][0] != '&' && split_entry
			[index][0] != ';')
		index++;
	return (index);
}

void	analyse_entry(t_command_q *command_q, char **split_entry, int nb_node)
{
	size_t	i;
	size_t	length;

	i = 0;
	while (split_entry[i] && (int)i < nb_node)
	{
		length = how_much_node_in_command(&split_entry[i]);
		if (quotes_incomplete(split_entry[i], &i))
			i += length;
		if (parse_command(command_q, split_entry, &i, &length) == true)
			command_q->nb_command++;
		if (command_q->valid_entry == false)
			return ;
		while (split_entry[i] && (split_entry[i][0] ==
			'|' || split_entry[i][0] == '&' || split_entry[i][0] == ';'))
			i++;
	}
}
