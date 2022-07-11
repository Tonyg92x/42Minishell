/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:19:03 by aguay             #+#    #+#             */
/*   Updated: 2022/07/11 13:31:40 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	fixItBoy(char *string, size_t start, size_t end)
// {
// 	while (string[start + 1])
// 	{
// 		string[start] = string[start + 1];
// 		start++;
// 		if (start == end - 1 && !string[start + 1])
// 		{
// 			string[start] = '\0';
// 			return ;
// 		}
// 		else if (start == end - 1)
// 			start++;
// 	}
// 	string[start - 1] = '\0';
// }

// static void	is_closed(char *string, size_t *i)
// {
// 	const char		quotes = string[(*i)];
// 	const size_t	pos_begin = (*i)++;

// 	while (string[(*i)])
// 	{
// 		if (string[(*i)] == quotes)
// 		{
// 			fixItBoy(string, pos_begin, (*i));
// 			return ;
// 		}
// 		(*i)++;
// 	}
// }

//	Trim the quotes if they are closed
bool	ft_parseQuotes(t_command *command, char ***split_entry, size_t *len, size_t *i)
{
	(void)command;
	(void)split_entry;
	(void)len;
	(void)i;
	return (true);
}
