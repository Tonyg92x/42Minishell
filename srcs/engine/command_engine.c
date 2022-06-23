/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:08:29 by aguay             #+#    #+#             */
/*   Updated: 2022/06/23 12:52:00 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	command_engine(t_command *command)
{
	pid_t	id;

	id = fork();
	if (id == 0)
	{
		if (execve(command->path, command->cmd, command->envp) == -1)
		{
			ft_putstr_fd("execve : problem on executing the command\n", 2);
			free_command(command);
			exit(0);
		}
	}
	wait(&id);
}