/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/11 05:39:02 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	parsing(t_command_q *command_q, char *entry)
{
	char	**entry_sp;
	int		temp;

	temp = 0;
	entry_sp = split_entry(entry);
	if (!entry_sp)
		return ;
	while (entry_sp[temp])
		printf("%s\n", entry_sp[temp++]);
	ft_free2d(entry_sp);
	(void)command_q;
}
