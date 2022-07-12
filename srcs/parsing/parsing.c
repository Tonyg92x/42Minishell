/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/07/12 18:51:25 by aguay            ###   ########.fr       */
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
		printf("next = %p\n", temp->next);
		printf("prev = %p\n", temp->prev);
		printf("builtins = %d\n", temp->builtins);
		x = 0;
		printf("Here doc :\n");
		while (temp->here_doc && temp->here_doc[x])
			printf("%s\n", temp->here_doc[x++]);
		x = 0;
		printf("Command :\n");
		while (temp->cmd && temp->cmd[x])
			printf("%s\n", temp->cmd[x++]);
		printf("Path = %s\n", temp->path);
		printf("input = %s\n", temp->input);
		printf("output = %s\n", temp->output);
		printf("append_mod = %d\n", temp->append_mode);
		printf("Link with next = %s\n\n", temp->link_next);
		temp = temp->next;
	}
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
