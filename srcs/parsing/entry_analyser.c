/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_analyser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/18 09:47:09 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

//	Look if there is a builtins command
static bool	simple_builtins(t_command_q *command_q, char **split_entry, size_t *i)
{
	t_command	*command;

	if (!is_builtins(split_entry[(*i)]))
		return (false);
	command = new_command(command_q);
	command->builtins = true;
	if (!init_cmd(command, split_entry, i))
	{
		free_command(command);
		return (false);
	}
	return (true);
	// Look if there is an output
}

//	Look if there is a command.
// static bool	simple_command(t_command_q *command_q)
// {
	
// }

//	Parse the word to understand the command and his agruments.
static bool	parse_word(t_command_q *command_q, char **split_entry, size_t *i)
{
	t_command	*command;

	if (white_space(split_entry[(*i)], i))
		return (false);
	else if (quotes_incomplete(split_entry[(*i)], i))
	{
		command_q->valid_entry = false;
		return (false);
	}
	else if (input_fd(command_q, split_entry, i))	// Here, i dont look for space between metacharacter and command gotta fix that
	{
		command = last_command(command_q);
		get_command(command, split_entry, i);
		return (true);
	}
	else if (simple_builtins(command_q, split_entry, i))
		return (true);
	else
		(*i)++;
	return (false);
}

void	analyse_entry(t_command_q *command_q, char **split_entry)
{
	size_t	i;

	i = 0;
	while (split_entry[i])
	{
		if (parse_word(command_q, split_entry, &i) == true)
			command_q->nb_command++;
		if (command_q->valid_entry == false)
			return ;
	}
}
