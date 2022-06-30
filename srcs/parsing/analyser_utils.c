/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/30 16:10:34 by aguay            ###   ########.fr       */
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

//	Look if there is an error at entry with unfinished
//	quotes. We don't have to manage it so we don't try
//	to understand it by asking an other input.
bool	quotes_incomplete(char *string, size_t *i)
{
	size_t	x;
	size_t	d_q;
	size_t	s_q;

	x = 0;
	d_q = 0;
	s_q = 0;
	while (string[x])
	{
		if (string[x] == '\'')
			s_q++;
		else if (string[x] == '"')
			d_q++;
		x++;
	}
	if (s_q % 2 != 0 || d_q % 2 != 0)
	{
		(*i)++;
		ft_putstr_fd("Invalid entry: Entry has unclosed quotes.\n", 2);
		return (true);
	}
	return (false);
}
