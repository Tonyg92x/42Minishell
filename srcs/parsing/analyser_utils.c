/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/12 10:38:35 by aguay            ###   ########.fr       */
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
	if (!string || !string[0])
		return (false);
	if (string[0] == ' ' || string[0] == '\n' || string[0] == '\t')
		return (true);
	return (false);
}

void	ft_removeSpace(char ***split_entry)
{
	size_t	temp;

	temp = 0;
	while ((*split_entry) && (*split_entry)[temp])
	{
		if ((*split_entry) && (*split_entry)[temp] && (*split_entry)[temp][0] && (*split_entry)[temp][0] == ' ')
				(*split_entry) = ft_revRealloc((*split_entry), (*split_entry)[temp]);
		else
			temp++;
	}
}
