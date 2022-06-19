/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/19 14:14:46 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static void	print_comannd_q(t_command_q *command_q)
{
	t_command	*temp;
	int			i;
	int			x;

	i = 0;
	temp = command_q->start;
	printf("\t\033[4mCommand queue\033[0m\n");
	printf("Nb_command : %d\n\n", command_q->nb_command);
	while (temp)
	{
		printf("Command %d\n", i++);
		printf("next = %p\n", temp->next);
		printf("prev = %p\n", temp->prev);
		printf("builtins = %d\n", temp->builtins);
		printf("append_mod = %d\n", temp->append_mode);
		printf("Delimiter = %s\n", temp->delimiter);
		x = 0;
		printf("Command :\n");
		while (temp->cmd[x])
			printf("%s\n", temp->cmd[x++]);
		printf("Path = %s\n", temp->path);
		printf("input = %s\n", temp->input);
		printf("output = %s\n\n", temp->output);
		temp = temp->next;
	}
}

void	parsing(t_command_q *command_q, char *entry)
{
	char	**entry_sp;
	int		nb_node;

	nb_node = how_much_node(entry);
	entry_sp = split_entry(entry, nb_node);
	if (!entry_sp)
		return ;
	analyse_entry(command_q, entry_sp, nb_node);
	print_comannd_q(command_q);
	ft_free2d(entry_sp);
	(void)command_q;
}
