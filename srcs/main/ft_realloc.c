/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:41:53 by roxannefour       #+#    #+#             */
/*   Updated: 2022/06/23 10:50:44 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static size_t	get_size(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
		i++;
	return (i + 2);
}

//	Allocate the string passed to the char **
char	**ft_realloc(char **strings, char *str)
{
	char			**new_str;
	size_t			i;
	const size_t	size = get_size(strings);

	i = 0;
	new_str = ft_calloc(size, sizeof(char *));
	while (strings[i])
	{
		new_str[i] = strings[i];
		i++;
	}
	free(strings);
	new_str[i] = ft_strdup(str);
	new_str[i + 1] = NULL;
	return (new_str);
}
