/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:15:27 by aguay             #+#    #+#             */
/*   Updated: 2022/07/22 08:45:19 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_var(char *str, size_t limit)
{
	size_t	i;
	size_t	count;

	if (!str)
		return ;
	i = 0;
	count = 0;
	while (str[i] && count < limit)
	{
		ft_strdecale(&str[i]);
		count++;
	}
}

bool	is_closed(char *string, char c)
{
	size_t	i;

	i = 1;
	while (string[i])
	{
		if (string[i] == c)
			return (true);
		i++;
	}
	return (false);
}

int	pos_quotes_end(char *string)
{
	int i;
	int	y;

	if (!string)
		return (0);
	i = 0;
	y = 0;
	while (string[i])
	{
		if (string[i] == '"')
			y++;
		if (y == 2)
			return (i + 1);
		i++;
	}
	return (i);
}

bool	error_quotes(void)
{
	ft_putstr_fd("Parsing error: Quotes unclosed.\n", 2);
	return (false);
}

bool	expand_node(char **string, t_command *command)
{
	size_t	index;

	if (!string || !(*string))
		return (false);
	index = 0;
	while ((*string)[index])
	{
		if ((*string)[index] == '\'')
		{
			if (!is_closed(&((*string)[index]), '\''))
				return (error_quotes());
			ft_strdecale(&(*string)[index]);
			while ((*string)[index] && (*string)[index] != '\'')
				index++;
			ft_strdecale(&(*string)[index]);
		}
		else if ((*string)[index] == '"')
		{
			if (!is_closed(&((*string)[index]), '"'))
				return (error_quotes());
			ft_strdecale(&(*string)[index]);
			while ((*string)[index] != '"')
			{
				if ((*string)[index] == '$')
				{
					if (!expand_var(&(*string), ++index, command))
						ft_clear_var(&(*string)[index - 1], ft_strlen(&(*string)[index - 1]));
					break ;
				}
				index++;
			}
			ft_strdecale(&(*string)[index]);
		}
		else if ((*string)[index] == '$')
			expand_var(string, (int)++index, command);
		else
			index++;
	}
	return (true);
}

size_t	varlen(char *string)
{
	size_t	retour;

	retour = 0;
	while (string[retour] && !ft_ismetaenv(string[retour]))
		retour++;
	return (retour);
}

bool	ft_ismetaenv(char c)
{
	return (c == '|' || c == '&' || c == ' ' || c == ';'
		|| c == '(' || c == ')' || c == '<' || c == '>'
		|| c == '\'' || c == '"');
}
