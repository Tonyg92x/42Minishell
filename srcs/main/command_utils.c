/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/11 07:06:37 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

//	Initialise command list
void	initialise_command_list(t_command_q *command_q)
{
	command_q->start = NULL;
	command_q->nb_command = 0;
	command_q->valid_entry = true;
}

//	Initilise back the command list and his flags.
void	initialise_commands(t_command_q *command_q)
{
	t_command	*temp;

	command_q->nb_command = 0;
	if (command_q->start == NULL)
		return ;
	temp = command_q->start;
	while (temp->next != NULL)
	{
		temp = temp->next;
		free(temp->prev);
	}
	if (temp)
		free(temp);
}
