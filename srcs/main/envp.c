/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:04:14 by aguay             #+#    #+#             */
/*   Updated: 2022/06/20 11:58:49 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static size_t	getEnvpSize(char **envp)
{
	size_t	i;

	if (!envp)
		return (0);
	i = 0;
	while (envp[i])
		i++;
	return (i + 1);
}

char	**envp_init(char **envp)
{
	char	**newEnvp;
	size_t	i;

	i = 0;
	newEnvp = ft_calloc(getEnvpSize(envp), sizeof(char *));
	while (envp[i])
	{
		newEnvp[i] = ft_strdup(envp[i]);
		i++;
	}
	newEnvp[i] = NULL;
	return (newEnvp);
}
