/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/11 07:19:29 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

//	Look if the word is simply a whitespace
bool	white_space(char *string, size_t *i)
{
	if (string[0] == ' ' || string[0] == '\n' || string[0] == '\t')
	{
		(*i)++;
		return (true);
	}
	return (false);
}

//	Look if there is an error at entry with unfinished
//	quotes. We don't have to manage it so we don't try
//	to understand it by asking an other input.
bool	quotes_incomplete(char *string, size_t *i)
{
	size_t	x;
	size_t	d_q;
	size_t	s_q;

	x = 0;
	d_q = 0;
	s_q = 0;
	while(string[x])
	{
		if (string[x] == '\'')
			s_q++;
		else if (string[x] == '"')
			d_q++;
		x++;
	}
	if (s_q % 2 != 0 || d_q % 2 != 0)
	{
		(*i)++;
		ft_putstr_fd("Invalid entry: Entry has unclosed quotes.\n", 2);
		return (true);
	}
	return (false);
}
