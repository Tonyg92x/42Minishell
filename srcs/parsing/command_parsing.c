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
		if (is_white_space(split_entry[i]) || split_entry[i][0] == 
			'&' || split_entry[i][0] == '|' || split_entry[i][0] == ';')
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
	command->cmd = ft_calloc(cmd_to_entered + 1, sizeof(char *));
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

static bool	is_command(char *command, t_command_q *command_q)
{
	const size_t	index_p = index_to_path(command_q->envp);

	if (index_p == 999999)
	{
		ft_putstr_fd("Error: there is no path variable.\n", 2);
		return (false);
	}
	if (!path_is_valid(command, ft_split(command_q->envp[
			(int)index_p], ':'), command_q))
		return (false);
	return (true);
}

bool	command_exept(t_command_q *command_q, char **split_entry, size_t *i, size_t *length)
{
	if (!split_entry)
		return (false);
	if (!is_command(split_entry[(*i)], command_q))
		return (false);
	if (!init_cmd(last_command(command_q), split_entry, i, length))
	{
		free_command(last_command(command_q));
		return (false);
	}
	return (true);
}
