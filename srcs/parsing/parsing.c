/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/11 06:40:24 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	parsing(t_command_q *command_q, char *entry)
{
	char	**entry_sp;
	int		i = 0;

	entry_sp = split_entry(entry);
	if (!entry_sp)
		return ;
	while(entry_sp[i])
		printf("%s\n", entry_sp[i++]);
	analyse_entry(command_q, entry_sp);
	ft_free2d(entry_sp);
	(void)command_q;
}
