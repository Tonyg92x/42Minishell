/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/22 08:18:37 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Fonction for testing
static void	print_comannd_q(t_command_q *command_q)
{
	t_command	*temp;
	int			i;
	int			x;

	i = 0;
	temp = command_q->start;
	printf("\t\033[4mCommand queue\033[0m\n");
	printf("Nb_command : %d\n\n", (int)command_q->nb_command);
	while (temp)
	{
		printf("Valid command : %d\n", temp->valid);
		printf("Command %d\n", i++);
		if (temp->next)
			printf("next = %p\n", temp->next);
		if (temp->prev)
			printf("prev = %p\n", temp->prev);
		if (temp->builtins)
			printf("builtins = %d\n", temp->builtins);
		printf("Command :\n");
		x = 0;
		while (temp->cmd && temp->cmd[x])
			printf("%s\n", temp->cmd[x++]);
		if (temp->path)
			printf("Path = %s\n", temp->path);
		if (temp->input)
			printf("input = %s\n", temp->input);
		x = 0;
		while (temp->here_doc && temp->here_doc[x])
		{
			if (x == 0)
				printf("Here doc :\n");
			printf("%s\n", temp->here_doc[x++]);
		}
		if (temp->output)
			printf("output = %s\n", temp->output);
		if (temp->append_mode)
			printf("append_mod = %d\n", temp->append_mode);
		temp = temp->next;
	}
	printf("\nEnd output info command\n\n\n");
}

bool	parsing(t_command_q *command_q, char *entry)
{
	char	**entry_sp;
	int		nb_node;

	nb_node = how_much_node(entry);
	entry_sp = split_entry(entry, nb_node);
	ft_remove_space(&entry_sp);
	if (!entry_sp)
		return (false);
	if (!analyse_entry(command_q, &entry_sp, nb_node))
	{
		ft_free2d(entry_sp);
		return (false);
	}
	print_comannd_q(command_q);
	ft_free2d(entry_sp);
	return (true);
}
