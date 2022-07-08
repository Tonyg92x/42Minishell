/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:16:36 by roxannefour       #+#    #+#             */
/*   Updated: 2022/07/08 15:50:08 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	open_input(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory.\n", 2);
		return (false);
	}
	else
		close(fd);
	return (true);
}

bool	ft_input(t_command *command, size_t *temp, size_t *len,
	char ***split_entry)
{
	(*split_entry) = ft_revRealloc((*split_entry), (*split_entry)[(*temp)]);
	(*len)--;
	while ((*split_entry)[(*temp)] && (*split_entry)[(*temp)][0]
			&& (*split_entry)[(*temp)][0] == ' ')
	{
		(*split_entry) = ft_revRealloc((*split_entry), (*split_entry)[(*temp)]);
		(*len)--;
	}
	if (!open_input((*split_entry)[(*temp)]))
		return (false);
	if (command->input)
		free(command->input);
	command->input = ft_strdup((*split_entry)[(*temp)]);
	(*split_entry) = ft_revRealloc((*split_entry), (*split_entry)[(*temp)]);
	(*len)--;
	return (true);
}

bool	ft_inputHD(t_command *command, size_t *temp, size_t *len,
	char ***split_entry)
{
	(void) command;
	(void) temp;
	(void) len;
	(void) split_entry;
	return (true);
}
