/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/22 08:55:13 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit(t_command *command)
{
	ft_free2d(command->envp);
	initialise_commands(command->queue_link);
	rl_clear_history();
	exit (0);
}
