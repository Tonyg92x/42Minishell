/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:51:01 by roxannefour       #+#    #+#             */
/*   Updated: 2022/06/30 16:10:25 by aguay            ###   ########.fr       */
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
		||!split_entry[temp][0] || !split_entry[temp + 1][0])
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

	if (!split_entry[(*i) + 1] || !split_entry[(*i) + 2])
		return (false);
	if (split_entry[(*i)][0] == '<' && split_entry
		[(*i) + 1][0] == '<' && split_entry[(*i) + 2])
	{
		temp = (*i) + 2;
		while (split_entry[temp] && (split_entry[temp][0]) == ' ')
			temp++;
		if (!split_entry[temp])
			return (false);
		delim = ft_calloc(1, sizeof(char *));
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
