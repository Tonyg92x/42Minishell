/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/10 15:13:08 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	routine_prompt(t_flags *flags)
{
	char	*entry;

	reset_flags(flags);
	while (flags->exit == false)
	{
		reset_flags(flags);
		entry = readline("\033[4m\033[36mMinishell\033[0m \033[32m->\033[0m  ");
		add_history(entry);
		parsing(flags, entry);
		free(entry);
	}
	rl_clear_history();
	return ;
}
