/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:51:44 by jnho              #+#    #+#             */
/*   Updated: 2022/08/30 20:04:34 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hexadecimal(unsigned char non_print)
{
	char	hex;
	char	digit;

	hex = non_print / 16;
	digit = non_print % 16;
	write(1, "\\", 1);
	if (hex < 10)
		hex += '0';
	else
		hex = hex - 10 + 'a';
	if (digit < 10)
		digit += '0';
	else
		digit = digit + 'a' - 10;
	write(1, &hex, 1);
	write(1, &digit, 1);
}

void	ft_putstr_non_printable(char	*str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if ((str[idx] <= 126) && (str[idx] >= 32))
			write(1, &str[idx], 1);
		else
			ft_hexadecimal((unsigned char)str[idx]);
		idx++;
	}
}
