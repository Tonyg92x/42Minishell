/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/07 15:24:04 by aguay            ###   ########.fr       */
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

void	parsing(t_flags *flags, char *entry)
{
	if (exit_command(entry))
		flags->exit = true;
}