/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/10 15:30:48 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	**error_exit(char **s_entry)
{
	if (s_entry)
		ft_free2d(s_entry);
	printf("\033[31mThere was an error while parsing :(.\033[0m\n");
	return (NULL);
}

bool	ft_is_metacharacter(char c)
{
	if (!c)
		return (false);
	if (c == ' ' || c == '\n' || c == '\t' || c
		== '|' || c == '&' || c == '(' || c == ')' || c == '<' || c == '>')
		return (true);
	return (false);
}

static void	quotes_tool(char *string, size_t *single, size_t *doub)
{
	if (string[0] == '\'')
	{
		if ((*single) == 1)
			(*single) = 0;
		else
			(*single) = 1;
	}
	else if (string[0] == '"')
	{
		if ((*doub) == 1)
			(*doub) = 0;
		else
			(*doub) = 1;
	}
}

size_t	word_size(char *string)
{
	size_t	i;
	size_t	single;
	size_t	doub;

	if (!string)
		return (0);
	single = 0;
	doub = 0;
	i = 0;
	while (string[i])
	{
		quotes_tool(&string[i], &single, &doub);
		if (ft_is_metacharacter(string[i]) && single
			== 0 && doub == 0)
			return (i);
		i++;
	}
	return (i);
}

int	how_much_node(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (ft_is_metacharacter(string[i++]))
			count++;
		else
		{
			count++;
			while (string[i] && !ft_is_metacharacter(string[i]))
				i++;
		}
	}
	return (count + 1);
}
