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

//	Return the number of arguments to allocate
static size_t	how_much_arg(char **split_entry, size_t *i)
{
	size_t	retour;
	size_t	temp;

	if (!split_entry || !split_entry[(*i)])
		return (0);
	temp = (*i);
	retour = 0;
	while (split_entry[temp] && (!ft_is_metacharacter(split_entry[temp][0])))
	{
		if (temp > (*i) && split_entry[temp][0] == '-')
			retour++;
		else if (temp > (*i))
			return (retour);
		else
			retour++;
		temp++;
		while (split_entry[temp] && split_entry[temp][0] == ' ')
			temp++;
	}
	return (++retour);
}

//	Initialise the exact size for of the command in command.cmd
bool	init_cmd(t_command *command, char **split_entry, size_t *i)
{
	const size_t	cmd_size = how_much_arg(split_entry, i);
	size_t			cmd_entered;

	if (cmd_size == 0)
		return (false);
	command->cmd = ft_calloc(cmd_size, sizeof(char *));
	cmd_entered = 0;
	while (cmd_entered < cmd_size - 1)
	{
		command->cmd[cmd_entered++] = ft_strdup(split_entry[(*i)++]);
		while (split_entry[(*i)] && split_entry[(*i)][0] == ' ')
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
