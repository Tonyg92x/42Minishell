/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/09 09:34:43 by anthony          ###   ########.fr       */
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
	if (c == ' ' || c == '\n' || c == '\t' || c == '|' ||
			c == '&' || c == ';' || c == '(' || c == ')'
			|| c == '<' || c == '>')
		return (true);
	return (false);
}

size_t	word_size(char *string)	// finish here
{
	size_t	i;
	bool	single_quote;
	bool	double_quote;

	single_quote = false;
	double_quote = false;
	if (!string)
		return (0);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\'')
		{
			if (single_quote == true)
				single_quote = false
			else
				single_quote = true;
		}
		if (string[i] == '"')
		{
			if (double_quote == true)
				double_quote = false
			else
				double_quote = true;
		}
		if (single_quote = true)
		{
			
		}
		else if (double_quote = true)
		{
			
		}
		else (ft_is_metacharacter(string[i]))
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
