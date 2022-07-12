/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandEnvUtils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:15:27 by aguay             #+#    #+#             */
/*   Updated: 2022/07/12 14:01:14 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_isMetaEnv(char c)
{
	return (c == '|' || c == '&' || c == ' ' || c ==';'
		|| c == '(' || c == ')' || c == '<' || c == '>');
}