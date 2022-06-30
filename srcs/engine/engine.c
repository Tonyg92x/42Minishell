/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:59:56 by aguay             #+#    #+#             */
/*   Updated: 2022/06/30 16:10:56 by aguay            ###   ########.fr       */
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
		else
			command_engine(command);
		if (command->next)
			command = command->next;
		else
			break ;
	}
}