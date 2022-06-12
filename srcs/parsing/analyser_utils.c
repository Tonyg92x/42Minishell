/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/12 07:12:29 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	get_command(t_command *command, char **split_entry, size_t *i)
{
	if (is_builtins(command, split_entry[(*i)]))
		parse_builtins(command, split_entry[(*i)]), i);
	if (!command_is_valid(command, split_entry, i))
		ft_putstr_fd("Invalid command.\n", 2);
}

//	look if there is input in the command
//	DONT FORGET THE DOCK CODE HERE
bool	input_fd(t_command_q *command_q, char **split_entry, size_t *i)
{
	t_command	*temp;

	if (split_entry[(*i)][0] == '<')
	{
		temp = new_command(command_q);
		if (split_entry[(*i)][1] == '<')
		{
			temp->delimiter = true;
			//	start here dock here ??
			temp->input = ft_strdup(split_entry[(*i)][2]);
			(*i) += 3;
			return (true);
		}
		temp->input = ft_strdup(split_entry[(*i)][1]);
		(*i) += 2;
		return (true);
	}
	return (false);
}

//	Look if the word is simply a whitespace
bool	white_space(char *string, size_t *i)
{
	if (string[0] == ' ' || string[0] == '\n' || string[0] == '\t')
	{
		(*i)++;
		return (true);
	}
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
	while(string[x])
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
