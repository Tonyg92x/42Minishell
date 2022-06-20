/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:38:32 by aguay             #+#    #+#             */
/*   Updated: 2022/06/20 16:03:18 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Return a new string, that has the content of s string, starting
//	at the start argument as index. The new string is allocated with
//	malloc so don't forget to free it.
char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t			i;
	size_t			slen;
	char			*tmp;

	if (!src)
		return (NULL);
	slen = ft_strlen((char *)src);
	if (start > slen)
		return (ft_strdup(""));
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < len)
		tmp[i] = src[start + i];
	tmp[i] = '\0';
	return (tmp);
}
