/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:13:41 by aguay             #+#    #+#             */
/*   Updated: 2022/07/19 13:17:02 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Expand every environnement variable in HD
void	expand_var_hd(char **string, size_t pos, t_command *command)
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

//	Expand every environnement variable in cmd
bool	expand_var(char **string, int pos, t_command *command)
{
	char	*variable;
	char	*temp;
	char	*expand;
	char	*new_str;
	int		i;
	int		x;
	int		y;

	variable = ft_substr((*string), pos, varlen(&(*string)[pos]));
	expand = find_variable(variable, command->envp);
	temp = (*string);
	if (!expand)
	{
		if (variable)
			free(variable);
		return (false);
	}
	new_str = ft_calloc(ft_strlen((*string)) - varlen(&(*string)[pos])
			+ ft_strlen(expand) + 1, sizeof(char));
	i = 0;
	x = 0;
	while ((*string) && (*string)[i] && (int)i < pos - 2)
	{
		if ((*string)[0] == '"')
			(*string)++;
		new_str[x++] = (*string)[i++];
	}
	y = 0;
	while (expand[y])
		new_str[x++] = expand[y++];
	i = i + 3 + ft_strlen(variable);
	if (!(i > (int)ft_strlen((*string))))
	{
		while ((*string) && (*string)[i])
			new_str[x++] = (*string)[i++];
	}
	new_str[x] = '\0';
	free(temp);
	free(variable);
	free(expand);
	(*string) = new_str;
	return (true);
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
				expand_var_hd(&command->here_doc[i], ++x, command);
			x++;
		}
		i++;
	}
}

static bool	expand_entry(t_command *command)
{
	size_t	index;

	if (!command || !command->cmd || !command->cmd[0])
		return (false);
	index = 0;
	while (command->cmd[index])
	{
		if (!expand_node(&command->cmd[index++], command))
			return (false);
	}
	return (true);
}

bool	expand_envar(t_command *command)
{
	if (!command)
		return (false);
	if (command->here_doc)
		expand_hd(command);
	else if (command->cmd)
		return (expand_entry(command));
	return (true);
}
