/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/18 09:03:56 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static void	init_command_queue(t_command_q *command_q, t_envp *envp)
{
	command_q->start = NULL;
	command_q->nb_command = 0;
	command_q->valid_entry = true;
	command_q->envp = envp;
}

int	main(void)
{
	t_command_q	command_q;
	t_envp		envp;

	if (!envp_init(&envp))
	{
		ft_putstr_fd("There was an error while initialising environnement variable.\n", 2);
		return (1);
	}
	init_command_queue(&command_q, &envp);
	printf("\033[33mWelcome \033[31m%s\033[0m\n", envp.USER);
	routine_prompt(&command_q);
}
