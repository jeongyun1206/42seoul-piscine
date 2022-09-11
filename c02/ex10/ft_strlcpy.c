/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:49 by jnho              #+#    #+#             */
/*   Updated: 2022/09/01 11:53:32 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size )
{
	unsigned int	src_size;
	unsigned int	idx;

	idx = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	if (size == 0)
		return (src_size);
	while ((src[idx]) && (idx + 1 < size))
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (src_size);
}
