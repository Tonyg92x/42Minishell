/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/07 11:45:59 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Analyse the link between 2 command
void	analyse_link(t_command_q *command_q, char **split_entry, size_t *i)
{
	t_command	*command;

	if (!command_q || !split_entry[(*i)])
		return ;
	if (split_entry[(*i)][0] == '|' || split_entry[(*i)][0] ==
		'&' || split_entry[(*i)][0] == ';')
	{
		command = last_command(command_q);
		if (split_entry[(*i) + 1] && (split_entry[(*i) + 1][0] == '|'
			|| split_entry[(*i) + 1][0] == '&' || split_entry[(*i)
				+ 1][0] == ';'))
		{
			command->link_next = ft_calloc(3, sizeof(char));
			command->link_next[0] = split_entry[(*i)++][0];
			command->link_next[1] = split_entry[(*i)++][0];
			command->link_next[3] = '\0';
		}	
		else
		{
			command->link_next = ft_calloc(2, sizeof(char));
			command->link_next[0] = split_entry[(*i)++][0];
			command->link_next[1] = '\0';
		}
	}
}

//	Look if the word is simply a whitespace
bool	is_white_space(char *string)
{
	if (!string)
		return (false);
	if (string[0] == ' ' || string[0] == '\n' || string[0] == '\t')
		return (true);
	return (false);
}

static void	fixItBoy(char *string, size_t start, size_t end)
{
	while (string[start + 1])
	{
		string[start] = string[start + 1];
		start++;
		if (start == end - 1 && !string[start + 1])
		{
			string[start] = '\0';
			return ;
		}
		else if (start == end - 1)
			start++;
	}
	string[start - 1] = '\0';
}

static void	is_closed(char *string, size_t *i)
{
	const char		quotes = string[(*i)];
	const size_t	pos_begin = (*i)++;

	while (string[(*i)])
	{
		if (string[(*i)] == quotes)
		{
			fixItBoy(string, pos_begin, (*i));
			return ;
		}
		(*i)++;
	}
}

//	Trim the quotes if they are closed
void	quotes_manager(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\'' || string[i] == '\"')
			is_closed(string, &i);
		else
			i++;
	}
}
