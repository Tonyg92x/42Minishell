/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/08 15:47:11 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Setup all value of struct command to NULL
//	to avoid unwanted behavior
static void	initialise_command(t_command *command,
	t_command_q *command_q)
{
	command->valid = true;
	command->cmd = NULL;
	command->path = NULL;
	command->builtins = false;
	command->input = NULL;
	command->output = NULL;
	command->here_doc = NULL;
	command->link_next = NULL;
	command->append_mode = NULL;
	command->envp = command_q->envp;
	command->queue_link = command_q;
}

//	Return the pointer to the last command in the
//	queue.
t_command	*last_command(t_command_q *command_q)
{
	t_command	*temp;

	if (command_q->start == NULL)
		return (NULL);
	temp = command_q->start;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

//	Allocate a new command at the end of the queue.
t_command	*new_command(t_command_q *command_q)
{
	t_command	*temp;

	temp = last_command(command_q);
	if (temp == NULL)
	{
		command_q->start = ft_calloc(1, sizeof(t_command));
		initialise_command(command_q->start, command_q);
		return (command_q->start);
	}
	else
	{
		temp->next = ft_calloc(1, sizeof(t_command));
		initialise_command(temp->next, command_q);
		temp->next->prev = temp;
	}
	return (temp->next);
}

//	Free the comment and all attributes
void	free_command(t_command	*command)
{
	if (command == NULL)
		return ;
	if (command->here_doc != NULL)
		ft_free2d(command->here_doc);
	if (command->path != NULL)
		free(command->path);
	if (command->cmd != NULL)
		ft_free2d(command->cmd);
	if (command->link_next != NULL)
		free(command->link_next);
	if (command->input != NULL)
		free(command->input);
	if (command->output != NULL)
		free(command->output);
	free (command);
}

//	Initilise the list of command and his flags.
//	Free the last list entered if there is one.
void	initialise_commands(t_command_q *command_q)
{
	t_command	*temp;

	command_q->nb_command = 0;
	if (command_q->start == NULL)
		return ;
	temp = command_q->start;
	while (temp && temp->next != NULL)
	{
		temp = temp->next;
		free_command(temp->prev);
	}
	if (temp)
		free_command(temp);
	command_q->start = NULL;
}
