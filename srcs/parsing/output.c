/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:11:58 by aguay             #+#    #+#             */
/*   Updated: 2022/07/12 15:15:51 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static bool	open_output(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_putstr_fd("Opening ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (false);
	}
	else
		close(fd);
	return (true);
}

static bool	open_append(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		ft_putstr_fd("Opening ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (false);
	}
	else
		close(fd);
	return (true);
}

bool	ft_output(t_command *command, size_t *temp, size_t *len, char ***split_entry)
{
	ft_clear(split_entry, len, temp);
	while ((*split_entry)[(*temp)] && (*split_entry)[(*temp)][0]
			&& (*split_entry)[(*temp)][0] == ' ')
				ft_clear(split_entry, len, temp);
	if (!open_output((*split_entry)[(*temp)]))
		return (false);
	if (command->output)
		free(command->output);
	command->output = ft_strdup((*split_entry)[(*temp)]);
	if (command->append_mode == true)
		command->append_mode = false;
	ft_clear(split_entry, len, temp);
	if (!(*split_entry)[(*temp)])
		command->valid = false;
	return (true);
}

bool	ft_append(t_command *command, size_t *temp, size_t *len, char ***split_entry)
{
	ft_clear(split_entry, len, temp);
	while ((*split_entry)[(*temp)] && (*split_entry)[(*temp)][0]
			&& (*split_entry)[(*temp)][0] == ' ')
				ft_clear(split_entry, len, temp);
	if (!open_append((*split_entry)[(*temp)]))
		return (false);
	if (command->output)
		free(command->output);
	command->output = ft_strdup((*split_entry)[(*temp)]);
	if (command->append_mode == false)
		command->append_mode = true;
	ft_clear(split_entry, len, temp);
	return (true);
}
