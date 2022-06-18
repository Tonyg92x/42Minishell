/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:50:17 by aguay             #+#    #+#             */
/*   Updated: 2022/06/18 08:03:44 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef ENVIRONNEMENT_H
# define ENVIRONNEMENT_H

typedef struct EnvpGlobal
{
	char	*SHELL;
	char	*PWD;
	char	*LOGNAME;
	char	*USER;
	char	*HOME;
	char	*PATH;
}	t_envp;

#endif