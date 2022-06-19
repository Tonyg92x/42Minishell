/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:04:14 by aguay             #+#    #+#             */
/*   Updated: 2022/06/19 11:39:00 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

//	Initialise envp struct has boot up.
bool	envp_init(t_envp *envp)
{
	envp->HOME = getenv("HOME"); 
	if (!envp->HOME)
		return (false);
	envp->LOGNAME = getenv("LOGNAME");
	if (!envp->LOGNAME)
		return (false);
	envp->PATH = getenv("PATH");
	if (!envp->PATH)
		return (false);
	envp->PWD = getenv("PWD");
	if (!envp->PWD)
		return (false);
	envp->SHELL = getenv("SHELL");
	if (!envp->SHELL)
		return (false);
	envp->USER = getenv("USER");
	if (!envp->USER)
		return (false);
	return (true);
}