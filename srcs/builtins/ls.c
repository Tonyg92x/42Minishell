/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/08 10:33:01 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

//	Print in alphabetic number ?

void	ft_ls(char *path)
{
	DIR* dir;
	struct dirent* entity;

	dir = opendir(path);
	if (dir == NULL)
		return;
	entity = readdir(dir);
	while (entity != NULL)
	{
		printf("%s ", entity->d_name);
		entity = readdir(dir);
	}
	printf("\n");
	closedir(dir);
}