/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/22 07:45:28 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear(char ***split_entry, size_t *len, size_t *temp)
{
	(*split_entry) = ft_rev_realloc((*split_entry), (*split_entry)[(*temp)]);
	if (len && *len)
		(*len)--;
}

//	Look if the word is simply a whitespace
bool	is_white_space(char *string)
{
	if (!string || !string[0])
		return (false);
	if (string[0] == ' ' || string[0] == '\n' || string[0] == '\t')
		return (true);
	return (false);
}

void	ft_remove_space(char ***split_entry)
{
	size_t	temp;

	temp = 0;
	while ((*split_entry) && (*split_entry)[temp])
	{
		if ((*split_entry) && (*split_entry)[temp]
			&& (*split_entry)[temp][0] && (*split_entry)[temp][0] == ' ')
		{
			(*split_entry) = ft_rev_realloc((*split_entry),
					(*split_entry)[temp]);
		}
		else
			temp++;
	}
}
