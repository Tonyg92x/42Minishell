/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandEnv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:13:41 by aguay             #+#    #+#             */
/*   Updated: 2022/07/12 18:51:11 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	varlen(char *string)
{
	size_t	retour;

	retour = 0;
	while (string[retour] && !ft_ismetaenv(string[retour]))
		retour++;
	return (retour);
}

static void	expand_var(char **string, size_t pos, t_command *command)
{
	char	*variable;
	char	*expand;
	char	*new_str;
	size_t	i;
	size_t	x;

	variable = ft_substr((*string), pos, varlen(&(*string)[pos]));
	expand = find_variable(variable, command->envp);
	if (!expand)
	{
		if (variable)
			free(variable);
		return ;
	}
	new_str = ft_calloc(ft_strlen((*string)) - varlen(&(*string)[pos])
			+ ft_strlen(expand) + 1, sizeof(char));
	i = 0;
	x = 0;
	while ((*string)[i] && i < pos - 1)
	{
		new_str[i] = (*string)[i];
		i++;
	}
	while (expand[x])
		new_str[i++] = expand[x++];
	x = i - (x - ft_strlen(variable) - 1);
	while ((*string)[i])
		new_str[i++] = (*string)[x++];
	new_str[i] = '\0';
	free((*string));
	free(variable);
	free(expand);
	(*string) = new_str;
}

static void	expand_hd(t_command *command)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (command->here_doc[i])
	{
		x = 0;
		while (command->here_doc[i][x])
		{
			if (command->here_doc[i][x] == '$')
				expand_var(&command->here_doc[i], ++x, command);
			x++;
		}
		i++;
	}
}

void	ft_expand_env(char ***split_entry, t_command *command)
{
	if (command->here_doc)
		expand_hd(command);
	(void)split_entry;
}
