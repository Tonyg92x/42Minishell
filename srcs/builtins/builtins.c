/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:13:32 by aguay             #+#    #+#             */
/*   Updated: 2022/06/19 13:25:27 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

//	Look if the command passed in string is a builtins
bool	is_builtins( char *string)
{
	if (ft_strnstr(string, "cd", 2) != NULL)
		return (true);
	if (ft_strnstr(string, "echo", 4) != NULL)
		return (true);
	if (ft_strnstr(string, "env", 3) != NULL)
		return (true);
	if (ft_strnstr(string, "exit", 5) != NULL)
		return (true);
	if (ft_strnstr(string, "export", 6) != NULL)
		return (true);
	if (ft_strnstr(string, "pwd", 3) != NULL)
		return (true);
	if (ft_strnstr(string, "unset", 5) != NULL)
		return (true);
	return (false);
}
