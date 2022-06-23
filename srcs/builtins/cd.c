/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/23 12:47:24 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	builtin_cd(t_command *command)
{
	if (!command || !command->cmd || !command->cmd[0])
	{
		ft_putstr_fd("Invalid command entry\n", 2);
		return ;
	}
	if (!command->cmd[1])
	{
		chdir(getenv("HOME"));
		return ;
	}
	if (chdir(command->cmd[1]) != 0)
	{
		ft_putstr_fd(command->cmd[1], 2);
		ft_putstr_fd(" is invaid\n", 2);
	}
	(void) command;
}
