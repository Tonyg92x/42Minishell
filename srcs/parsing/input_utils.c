/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:51:01 by roxannefour       #+#    #+#             */
/*   Updated: 2022/07/08 08:34:05 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	size_t	temp;

	temp = (*i);
	while (split_entry[temp] && split_entry[temp][0] == ' ')
		temp++;
	if (!split_entry[temp] || !split_entry[temp + 1]
		|| !split_entry[temp][0] || !split_entry[temp + 1][0]
		|| !split_entry[temp + 1])
		return (false);
	if (split_entry[temp][0] == '<')
	{
		(*i)++;
		advance_input(split_entry, i);
		return (true);
	}
	return (false);
}

char	*has_heredoc(char **split_entry, size_t *i)
{
	char	*delim;
	size_t	temp;

	if (!split_entry[(*i) + 1])
		return (false);
	if (split_entry[(*i)][1] && split_entry[(*i)][1] &&
		split_entry[(*i)][0] == '<' && split_entry[(*i)][1] == '<')
	{
		temp = (*i) + 1;
		while (split_entry[temp] && (split_entry[temp][0]) == ' ')
			temp++;
		if (!split_entry[temp])
			return (false);
		delim = ft_strdup(split_entry[temp]);
		return (delim);
	}
	return (NULL);
}

//	Get the entry routine
char	**get_hd(char **split_entry, size_t *i, char *delim)
{
	char	**retour;
	char	*line;

	advance_input(split_entry, i);
	(*i)++;
	advance_input(split_entry, i);
	retour = ft_calloc(1, sizeof(char *));
	retour[0] = NULL;
	line = ft_calloc(1, sizeof(char *));
	line[0] = '\0';
	while (true)
	{
		free(line);
		line = readline("> ");
		if (here_doc_done(delim, line))
			break ;
		retour = ft_realloc(retour, line);
	}
	free(line);
	return (retour);
}
