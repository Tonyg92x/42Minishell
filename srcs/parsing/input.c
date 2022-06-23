/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:16:36 by roxannefour       #+#    #+#             */
/*   Updated: 2022/06/23 10:58:01 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	advance_input(char **split_entry, size_t *i)
{
	(*i)++;
	while (split_entry[(*i)] && (is_white_space(split_entry[(*i)])
			|| split_entry[(*i)][0] == '<'))
		(*i)++;
}

static bool	input_command(t_command_q *command_q, char **split_entry, size_t *i)
{
	t_command	*command;
	char		*inpu;
	size_t		length;

	inpu = ft_strdup(split_entry[(*i)]);
	if (!inpu)
		return (false);
	advance_input(split_entry, i);
	if (!split_entry[(*i)])
		return (false);
	length = how_much_node_in_command(&split_entry[(*i)]);
	if (builtins_exept(command_q, split_entry, i, &length))
	{
		command = last_command(command_q);
		command->input = inpu;
		return (true);
	}
	else if (command_exept(command_q, split_entry, i, &length))
	{
		command = last_command(command_q);
		command->input = inpu;
		return (true);
	}
	free(inpu);
	return (false);
}

//	look if there is input in the command
//	DONT FORGET THE DOCK CODE HERE
bool	input_fd(t_command_q *command_q, char **split_entry, size_t *i)
{
	char	*delim;

	if (!command_q || !split_entry || !split_entry[(*i)])
		return (false);
	delim = has_heredoc(split_entry, i);
	if (delim)
		return (run_heredoc(command_q, split_entry, i, delim));
	if (has_input(split_entry, i))
		return (input_command(command_q, split_entry, i));
	return (false);
}

static bool	get_command(t_command_q *command_q, char **split_entry,
	size_t *i, char **hd)
{
	t_command	*command;
	size_t		length;

	length = how_much_node_in_command(&split_entry[(*i)]);
	if (length == 0)
	{
		ft_free2d(hd);
		return (false);
	}
	if (builtins_exept(command_q, split_entry, i, &length))
	{
		command = last_command(command_q);
		command->here_doc = hd;
		return (true);
	}
	if (command_exept(command_q, split_entry, i, &length))
	{
		command = last_command(command_q);
		command->here_doc = hd;
		return (true);
	}
	return (false);
}

//	Execute here doc here
bool	run_heredoc(t_command_q *command_q, char **split_entry,
	size_t *i, char *delim)
{
	char		**hd;

	hd = get_hd(split_entry, i, delim);
	free(delim);
	if (!hd)
		return (false);
	return (get_command(command_q, split_entry, i, hd));
}
