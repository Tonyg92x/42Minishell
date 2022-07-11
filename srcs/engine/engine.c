/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:59:56 by aguay             #+#    #+#             */
/*   Updated: 2022/07/11 12:08:42 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	engine(t_command_q *command_q)
{
	size_t		i;
	t_command	*command;

	i = 0;
	command = command_q->start;
	while (i < command_q->nb_command)
	{
		if (command->builtins == true)
			builtins_engine(command);
		else if (command->valid == true)
			command_engine(command);
		else if (command->valid == false && command->cmd)
		{
			ft_putstr_fd("Command \"", 2);
			ft_putstr_fd(command->cmd[0], 2);
			ft_putstr_fd("\" is invalid.\n", 2);
		}
		if (command->next)
			command = command->next;
		else
			break ;
	}
}