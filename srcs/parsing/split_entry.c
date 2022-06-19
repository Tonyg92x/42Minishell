/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/19 14:14:07 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*get_word(char *string, size_t *i)
{
	size_t			temp;
	size_t			index;
	char			*retour;
	const size_t	size = word_size(string);

	if (size == 0)
		return (NULL);
	temp = 0;
	(*i) += size;
	index = 0;
	retour = ft_calloc(size + 1, sizeof(char));
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

static void	parse_char(char **split_entry, char *entry, size_t *i, size_t *i_r)
{
	if (ft_is_metacharacter(entry[(*i)]))
	{
		split_entry[(*i_r)] = get_char(entry[(*i)]);
		if (!split_entry[(*i_r)])
			error_exit(split_entry);
		(*i)++;
	}
	else
	{
		split_entry[(*i_r)] = get_word(&entry[(*i)], i);
		if (!split_entry[(*i_r)])
			error_exit(split_entry);
	}
	(*i_r)++;
}

char	**split_entry(char *entry, int nb_node)
{
	char			**split_entry;
	size_t			i;
	size_t			i_r;

	split_entry = ft_calloc(nb_node, sizeof(char *));
	if (!split_entry)
		error_exit(split_entry);
	i = 0;
	i_r = 0;
	while (entry[i])
		parse_char(split_entry, entry, &i, &i_r);
	split_entry[i_r] = NULL;
	return (split_entry);
}
