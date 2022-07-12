/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:42:58 by aguay             #+#    #+#             */
/*   Updated: 2022/07/12 10:31:10 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	validInput(char **split_entry, size_t temp)
{
	if (!split_entry[temp] || !split_entry[temp][0])
		return (false);
	temp++;
	while (split_entry[temp] && split_entry[temp][0]
			&& split_entry[temp][0] == ' ')
		temp++;
	if (!split_entry[temp] || !split_entry[temp][0])
		return (false);
	return (true);
}

static bool	parse_input(t_command *command, char ***split_entry)
{
	size_t	temp;

	temp = 0;
	while (validInput((*split_entry), temp))
	{
		if ((*split_entry)[temp][0] == '<')
		{
			if ((*split_entry)[temp][1] && (*split_entry)[temp][1] == '<')
			{
				if (ft_inputHD(command, temp, split_entry) == false)
					return (false);
			}
			else if (ft_input(command, temp, split_entry) == false)
				return (false);
		}
		else
			temp++;
	}
	return (true);
}

bool	parse_output(t_command *command, char ***split_entry)
{
	size_t	temp;

	temp = 0;
	while (validInput((*split_entry), temp))
	{
		if ((*split_entry)[temp][0] == '>')
		{
			if ((*split_entry)[temp][1] && (*split_entry)[temp][1] == '>')
			{
				if (ft_append(command, temp, split_entry) == false)
					return (false);
			}
			else if (ft_output(command, temp, split_entry) == false)
				return (false);
		}
		else
			temp++;
	}
	return (true);
}

bool	ft_redir(t_command *command, char ***split_entry)
{
	if (!parse_input(command, split_entry))
		return (false);
	if (!parse_output(command, split_entry))
		return (false);
	return (true);
}