/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:03:17 by jnho              #+#    #+#             */
/*   Updated: 2022/09/07 16:48:28 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		src_len;
	int		cpy_idx;

	if (!src)
		return (NULL);
	src_len = 0;
	while (src[src_len])
		src_len++;
	dest = (char *)malloc(sizeof(char) * src_len);
	if (!dest)
		return (NULL);
	cpy_idx = 0;
	while (src[cpy_idx])
	{
		dest[cpy_idx] = src[cpy_idx];
		cpy_idx++;
	}
	dest[cpy_idx] = '\0';
	return (dest);
}
