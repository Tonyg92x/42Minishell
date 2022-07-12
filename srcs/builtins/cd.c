/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/12 13:29:50 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	go_home(t_command *command)
{
	char	*home;

	home = find_variable("HOME=", command->envp);
	chdir(&home[5]);
	change_pwd("PWD=", command->envp);
	free(home);
}

static bool	change_dir(t_command *command)
{
	if (chdir(command->cmd[1])!= 0)
	{
		ft_putstr_fd("cd : ", 2);
		ft_putstr_fd(command->cmd[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (false);
	}
	change_pwd("PWD=", command->envp);
	return (true);
}

void	builtin_cd(t_command *command)
{
	if (!command || !command->cmd || !command->cmd[0])
	{
		ft_putstr_fd("Invalid command entry\n", 2);
		return ;
	}
	else if (!command->cmd[1])
	{
		go_home(command);
		return ;
	}
	change_dir(command);
}
