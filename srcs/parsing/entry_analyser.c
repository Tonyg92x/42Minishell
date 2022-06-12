/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_analyser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/12 06:51:17 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

//	Parse the word to understand the command and his agruments.
static bool	parse_word(t_command_q *command_q, char **split_entry, size_t *i)
{
	t_command	*command;

	if (white_space(split_entry[(*i)], i))
		return (false);
	else if (quotes_incomplete(split_entry[(*i)], i))
	{
		command_q->valid_entry = true;
		return (false);
	}
	else if (input_fd(command_q, split_entry, i))
	{
		command = last_command(command_q);
		get_command(command, split_entry, i);
		return (true);
	}
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
