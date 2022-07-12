/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revRealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:04:11 by aguay             #+#    #+#             */
/*   Updated: 2022/07/12 18:39:38 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_size(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
		i++;
	return (i);
}

static bool	exist(char **array, void *ptr)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		if (array[i] == ptr)
			return (true);
		i++;
	}
	return (false);
}

//	Create a new string array without the string entered as ptr
char	**ft_rev_realloc(char **array, void *ptr)
{
	const size_t	new_size = get_size(array);
	char			**retour;
	size_t			i;
	size_t			new_i;

	if (!exist(array, ptr))
		return (array);
	retour = ft_calloc(new_size, sizeof(char *));
	i = 0;
	new_i = 0;
	while (array[i])
	{
		if (array[i] == ptr)
			i++;
		else
			retour[new_i++] = ft_strdup(array[i++]);
	}
	retour[new_i] = NULL;
	ft_free2d(array);
	return (retour);
}
