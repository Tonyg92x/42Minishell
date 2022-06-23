/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:20:48 by aguay             #+#    #+#             */
/*   Updated: 2022/06/23 10:53:16 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

//	Add a backslath after every string to test
//	test the path/command with acces funciton.
static char	**add_backslash(char **path)
{
	int		i;
	char	*path_command;

	i = 0;
	while (path[i])
	{
		path_command = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i++] = path_command;
	}
	return (path);
}

size_t	index_to_path(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] ==
			'A' && envp[i][2] == 'T' && envp[i][3] ==
			'H' && envp[i][4] == '=')
			return (i);
		i++;
	}
	return (999999);
}

static bool	working_path(char **path, t_command_q *command_q, char *command)
{
	char		*temp;
	t_command	*path_command;
	int			i;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], command);
		if (access(temp, F_OK) == 0)
		{
			free(temp);
			path_command = new_command(command_q);
			path_command->path = ft_strdup(path[i]);
			ft_free2d(path);
			return (true);
		}
		free(temp);
		i++;
	}
	ft_free2d(path);
	return (false);
}

bool	path_is_valid(char *command, char **path, t_command_q *command_q)
{
	char	**parsed_path;

	parsed_path = add_backslash(path);
	if (!working_path(parsed_path, command_q, command))
		return (false);
	return (true);
}
