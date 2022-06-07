/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/07 15:18:37 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

// Temporaire
static bool	exit_command(char *entry)
{
	if (ft_strnstr(entry, "exit", 10) != NULL)
		return (true);
	return (false);
}

// static void	split_it(char *entry, char **entry_split)
// {
// 	size_t	x

// 	x = 0;
// 	while (entry[x])
// 	{
// 		if ()
// 	}
// }

void	parsing(t_flags *flags, char *entry)
{
	char	**entry_split;
	
	entry_split = malloc(strlen(entry));
	// split_it(entry, entry_split);
	if (exit_command(entry))
		flags->exit = true;
	ft_free2d(entry_split);
}