/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:02:21 by aguay             #+#    #+#             */
/*   Updated: 2022/06/23 10:57:13 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static void	parse_cmd_output(t_command *command)
{
	size_t	i;

	i = 0;
	while (command->cmd && command->cmd[i])
	{
		if (command->cmd[i][0] == '>')
		{
			command->cmd[i++][0] = '\0';
			if (command->cmd[i] && command->cmd[i][0] == '>')
			{
				command->append_mode = true;
				command->cmd[i++][0] = '\0';
			}
			if (!command->cmd || !command->cmd[i])
			{
				command->append_mode = false;
				return ;
			}
			command->output = ft_strdup(command->cmd[i]);
			command->cmd[i][0] = '\0';
		}
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
