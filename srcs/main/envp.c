/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:04:14 by aguay             #+#    #+#             */
/*   Updated: 2022/06/23 09:16:25 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static size_t	get_envp_size(char **envp)
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
	char	**new_envp;
	size_t	i;

	i = 0;
	new_envp = ft_calloc(get_envp_size(envp), sizeof(char *));
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = NULL;
	return (new_envp);
}
