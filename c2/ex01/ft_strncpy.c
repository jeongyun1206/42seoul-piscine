/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:17:44 by jnho              #+#    #+#             */
/*   Updated: 2022/08/27 13:24:45 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	idx;

	idx = 0;
	while ((src[idx]) && (idx < (int)n))
	{
		dest[idx] = src[idx];
		idx++;
	}
	while (idx < (int)n)
	{
		dest[idx] = '\0';
		idx++;
	}
	return (dest);
}
