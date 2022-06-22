/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roxannefournier <roxannefournier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:51:01 by roxannefour       #+#    #+#             */
/*   Updated: 2022/06/22 10:39:04 by roxannefour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static bool	here_doc_done(char *delim, char *line)
{
	const size_t	size = ft_strlen(delim);

	if (ft_strnstr(line, delim, size) == NULL)
		return (false);
	return (true);
}

bool	has_input(char **split_entry, size_t *i)
{
	size_t temp;

	temp = (*i) + 1;
	while (split_entry[temp] && split_entry[temp][0] == ' ')
		temp++;
	if (!split_entry[temp] || !split_entry[temp + 1] || !split_entry[temp][0] || !split_entry[temp + 1][0])
		return (false);
	if (split_entry[temp][0] == '<')
		return (true);
	return (false);
}

char	*has_heredoc(char **split_entry, size_t *i)
{
	char	*delim;
	size_t	temp;

	if (!split_entry[(*i) + 1] || !split_entry[(*i) + 2])
		return (false);
	if (split_entry[(*i)][0] == '<' && split_entry
		[(*i) + 1][0] == '<' && split_entry[(*i) + 2])
	{
		temp = (*i) + 2;
		while (split_entry[temp] && (split_entry[temp][0]) == ' ')
			temp++;
		if (!split_entry[temp] || !split_entry[temp + 1])
			return (false);
		delim = ft_calloc(1, sizeof(char *));
		delim = ft_strdup(split_entry[temp]);
		return (delim);
	}
	return (NULL);
}

//	Get the entry routine
char	**getHereDocEntry(char **split_entry, size_t *i, char *delim)
{
	char	**retour;
	char	*line;

	advanceInput(split_entry, i);
	(*i)++;
	advanceInput(split_entry, i);
	if (!split_entry[(*i)])
		return (NULL);
	retour = ft_calloc(1, sizeof(char *));
	retour[0] = NULL;
	line = ft_calloc(1, sizeof(char *));
	line[0] = '\0';
	while (true)
	{
		free(line);
		line = readline("");
		if (here_doc_done(delim, line))
			break;
		retour = ft_realloc(retour, line);
	}
	free(line);
	return (retour);
}
