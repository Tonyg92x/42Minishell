/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/08 13:47:00 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*get_word(char *string, size_t *i)
{
	size_t			temp;
	size_t			index;
	char			*retour;
	const size_t	size = how_much_until_meta(string);

	if (size == 0)
		return (NULL);
	temp = 0;
	(*i) += size;
	index = 0;
	retour = ft_calloc(size + 1,sizeof(char));
	if (!retour)
		return (NULL);
	while (temp < size)
		retour[index++] = string[temp++];
	retour[index] = '\0';
	return (retour);
}

char	*get_char(char c)
{
	char	*retour;

	retour = ft_calloc(2, sizeof(char));
	if (!retour)
		return (NULL);
	retour[0] = c;
	retour[1] = '\0';
	return (retour);
}

char	**split_entry(char *entry)
{
	char			**temp;
	size_t			i;
	size_t			i_r;

	temp = ft_calloc(how_much_node(entry), sizeof(char *));
	if (!temp)
		error_exit(temp);
	i = 0;
	i_r = 0;
	while (entry[i])
	{
		if (ft_is_metacharacter(entry[i]))
		{
			temp[i_r] = get_char(entry[i]);
			if (!temp[i_r])
				error_exit(temp);
			i++;
		}
		else
		{
			temp[i_r] = get_word(&entry[i], &i);
			if (!temp[i_r])
				error_exit(temp);
		}
		i_r++;
	}
	temp[i_r] = NULL;
	return (temp);
}
