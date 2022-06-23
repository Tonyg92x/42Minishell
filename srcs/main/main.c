/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/23 16:17:25 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static void	init_command_queue(t_command_q *command_q, char **envp)
{
	command_q->start = NULL;
	command_q->nb_command = 0;
	command_q->valid_entry = true;
	command_q->envp = envp_init(envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_command_q	command_q;

	(void) argc;
	(void) argv;
	init_command_queue(&command_q, envp);
	printf("\033[33mWelcome \033[31m%s\033[0m\n", getenv("USER"));
	chdir(getenv("HOME"));
	change_pwd("PWD=", command_q.envp);
	routine_prompt(&command_q);
}
