/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:52:38 by jnho              #+#    #+#             */
/*   Updated: 2022/08/31 17:51:56 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx_dest;
	unsigned int	idx_src;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	while (dest[dest_len])
		dest_len++;
	if (size == 0)
		return (src_len);
	idx_src = 0;
	idx_dest = dest_len;
	while ((src[idx_src]) && (idx_dest < size - 1))
	{
		dest[idx_dest] = src[idx_src];
		idx_dest++;
		idx_src++;
	}
	dest[idx_dest] = '\0';
	if (size < dest_len)
		return (src_len + size);
	return (dest_len + src_len);
}
