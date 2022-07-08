/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:16:36 by roxannefour       #+#    #+#             */
/*   Updated: 2022/07/08 13:49:28 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	open(char *file, t_command *command)
{
	
}

bool	ft_input(t_command *command, size_t *temp, size_t *len,
	char ***split_entry)
{
	(*split_entry) = ft_revRealloc(split_entry, split_entry[(*temp)++]);
	(*len)--;
	while ((*split_entry)[(*temp)] && (*split_entry)[(*temp)][0]
			&& (*split_entry)[(*temp)][0] == ' ')
	{
		split_entry = ft_revRealloc((*split_entry), (*split_entry)[(*temp)++]);
		(*len)--;
	}
	if (!open((*split_entry)[(*temp)], command))
		return (false);
}

bool	ft_inputHD(t_command *command, size_t *temp, size_t *len,
	char ***split_entry)
{
	
}
