/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:42:58 by aguay             #+#    #+#             */
/*   Updated: 2022/07/12 18:52:58 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	valid_input(char **split_entry, size_t temp, size_t limit)
{
	if (!split_entry[temp] || !split_entry[temp][0] || temp >= limit)
		return (false);
	temp++;
	if (temp >= limit || !split_entry[temp] || !split_entry[temp][0])
		return (false);
	return (true);
}

static bool	parse_input(t_command *command, char ***split_entry, size_t *length,
	size_t *i)
{
	size_t	limit;
	size_t	temp;

	temp = (*i);
	limit = temp + (*length);
	while (valid_input((*split_entry), temp, limit))
	{
		if ((*split_entry)[temp][0] == '<')
		{
			if ((*split_entry)[temp][1] && (*split_entry)[temp][1] == '<')
			{
				if (ft_input_hd(command, &temp, length, split_entry) == false)
					return (false);
			}
			else if (ft_input(command, &temp, length, split_entry) == false)
				return (false);
		}
		else
			temp++;
	}
	return (true);
}

bool	parse_output(t_command *command, char ***split_entry, size_t *len,
	size_t *i)
{
	size_t	limit;
	size_t	temp;

	temp = (*i);
	limit = temp + (*len);
	while (valid_input((*split_entry), temp, limit))
	{
		if ((*split_entry)[temp][0] == '>')
		{
			if ((*split_entry)[temp][1] && (*split_entry)[temp][1] == '>')
			{
				if (ft_append(command, &temp, len, split_entry) == false)
					return (false);
			}
			else if (ft_output(command, &temp, len, split_entry) == false)
				return (false);
		}
		else
			temp++;
	}
	return (true);
}

bool	ft_redir(t_command *command, char ***split_entry, size_t *length,
	size_t *i)
{
	if (!parse_input(command, split_entry, length, i))
		return (false);
	if (!parse_output(command, split_entry, length, i))
		return (false);
	return (true);
}
