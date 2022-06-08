/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/06/08 10:38:46 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	main(void)
{
	char	*entry;
	t_flags	flags;

	reset_flags(&flags);
	while (flags.exit == false)
	{
		reset_flags(&flags);
		entry = routine_prompt();
		parsing(&flags, entry);
		free(entry);
	}
	rl_clear_history();
}