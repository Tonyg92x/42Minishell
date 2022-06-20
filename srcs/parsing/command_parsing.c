/*                                                        :::      ::::::::   */
/*   analyser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/12 06:47:31 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static size_t	how_much_command(char **split_entry, size_t i, size_t length)
{
	size_t	retour;
	size_t	limit;

	if (!split_entry)
		return (0);
	retour = 0;
	limit = i + length;
	while (i <= limit && split_entry[i])
	{
		if (is_white_space(split_entry[i]))
			i++;
		else
		{
			retour++;
			i++;
		}
	}
	return (retour);
}

//	Initialise the exact size for of the command in command.cmd
bool	init_cmd(t_command *command, char **split_entry, size_t *i, size_t *length)
{
	size_t			cmd_entered;
	const size_t	cmd_to_entered = how_much_command(split_entry, (*i), (*length));

	if ((*length) == 0)
		return (false);
	command->cmd = ft_calloc((*length) + 1, sizeof(char *));
	cmd_entered = 0;
	while (cmd_entered < cmd_to_entered)
	{
		command->cmd[cmd_entered++] = ft_strdup(split_entry[(*i)++]);
		while (split_entry[(*i)] && is_white_space(split_entry[(*i)]))
			(*i)++;
	}
	command->cmd[cmd_entered] = NULL;
	return (true);
}

//	Do all the operation to check if the command is
//	valid, the path and his arguments and if there is
//	and output / append mode.
// bool	command_is_valid(t_command *command, char **split_entry, size_t *i)
// {
// 	/*
// 		2)	Look if the command is a command with access
// 			and the path to the command. If it is, add path
// 			of the command and increment iterator. Else free
// 			the command and return an error for that invalid
// 			command but continue execution cause other command
// 			could be valid.
// 		3)	look if there is arguments or ouputs increment
// 			iterator for each ones..
// 	*/
// }
