/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:16:36 by roxannefour       #+#    #+#             */
/*   Updated: 2022/07/11 13:26:09 by aguay            ###   ########.fr       */
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

//	Get the entry routine
static char	**get_hd(char *delim)
{
	char	**retour;
	char	*line;

	retour = ft_calloc(1, sizeof(char *));
	retour[0] = NULL;
	line = ft_calloc(1, sizeof(char *));
	line[0] = '\0';
	while (true)
	{
		free(line);
		line = readline("> ");
		if (ft_strnstr(line, delim, ft_strlen(delim)) != NULL)
			break ;
		retour = ft_realloc(retour, line);
	}
	free(line);
	return (retour);
}

bool	ft_inputHD(t_command *command, size_t *temp, size_t *len,
	char ***split_entry)
{
	ft_clear(split_entry, len, temp);
	while ((*split_entry)[(*temp)] && (*split_entry)[(*temp)][0]
		&& (*split_entry)[(*temp)][0] == ' ')
			ft_clear(split_entry, len, temp);
	if (!(*split_entry)[(*temp)])
	{
		ft_putstr_fd("Sytax error near unexpected token\n", 2);
		return (false);
	}
	if (command->here_doc)
		ft_free2d(command->here_doc);
	command->here_doc = get_hd((*split_entry)[(*temp)]);
	ft_clear(split_entry, len, temp);
	if (!(*split_entry)[(*temp)])
		command->valid = false;
	return (true);
}

bool	ft_input(t_command *command, size_t *temp, size_t *len,
	char ***split_entry)
{
	ft_clear(split_entry, len, temp);
	while ((*split_entry)[(*temp)] && (*split_entry)[(*temp)][0]
			&& (*split_entry)[(*temp)][0] == ' ')
				ft_clear(split_entry, len, temp);
	if (!open_input((*split_entry)[(*temp)]))
		return (false);
	if (command->input)
		free(command->input);
	command->input = ft_strdup((*split_entry)[(*temp)]);
	ft_clear(split_entry, len, temp);
	return (true);
}
