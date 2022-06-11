/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/11 05:54:30 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	routine_prompt(t_command_q *command_q)
{
	char	*entry;

	initialise_commands(command_q);
	while (true)
	{
		entry = readline("\033[4m\033[36mMinishell\033[0m \033[32m->\033[0m  ");
		add_history(entry);
		parsing(command_q, entry);
		free(entry);
		initialise_commands(command_q);
	}
	rl_clear_history();
	return ;
}
