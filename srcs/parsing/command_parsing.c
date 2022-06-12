/*                                                        :::      ::::::::   */
/*   analyser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/12 06:47:31 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

//	Do all the operation to check if the command is
//	valid, the path and his arguments and if there is
//	and output / append mode.
bool	command_is_valid(t_command *command, char **split_entry, size_t *i)
{
	/*
		2)	Look if the command is a command with access
			and the path to the command. If it is, add path
			of the command and increment iterator. Else free
			the command and return an error for that invalid
			command but continue execution cause other command
			could be valid.
		3)	look if there is arguments or ouputs increment
			iterator for each ones..
	*/
}

void	parse_builtins(t_command *command, char **split_entry, size_t *i)
{
	
}

//	Look if the command passed in string is a builtins
bool	is_builtins(t_command *command, char *string)
{
	if (ft_strnstr(string, "cd", 2) != NULL)
		command->builtins = true;
	if (ft_strnstr(string, "echo", 4) != NULL)
		command->builtins = true;
	if (ft_strnstr(string, "env", 3) != NULL)
		command->builtins = true;
	if (ft_strnstr(string, "exit", 5) != NULL)
		command->builtins = true;
	if (ft_strnstr(string, "export", 6) != NULL)
		command->builtins = true;
	if (ft_strnstr(string, "ls", 2) != NULL)
		command->builtins = true;
	if (ft_strnstr(string, "pwd", 3) != NULL)
		command->builtins = true;
	if (ft_strnstr(string, "unset", 5) != NULL)
		command->builtins = true;
	if (command->builtins == true)
		return (true);
	return (false);
}
