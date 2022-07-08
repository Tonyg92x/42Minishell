/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:02:21 by aguay             #+#    #+#             */
/*   Updated: 2022/07/08 09:30:06 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parse_cmd_output(t_command *command)
{
	size_t	i;

	i = 0;
	while (command->cmd && command->cmd[i])
	{
		if (command->cmd[i][0] == '>')
		{
			if (command->cmd[i][1] && command->cmd[i][1] == '>')
				command->append_mode = true;
			else
				command->append_mode = false;
			command->cmd = ft_revRealloc(command->cmd, command->cmd[i]);
			if (command->output)
				free(command->output);
			command->output = ft_strdup(command->cmd[i]);
			command->cmd = ft_revRealloc(command->cmd, command->cmd[i]);
		}
		else
			i++;
	}
}

void	parse_output(t_command_q *command_q)
{
	t_command	*command;
	size_t		i;

	i = 0;
	command = command_q->start;
	while (i < command_q->nb_command)
	{
		parse_cmd_output(command);
		command = command->next;
		i++;
	}
}
