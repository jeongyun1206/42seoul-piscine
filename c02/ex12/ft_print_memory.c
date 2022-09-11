/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:48:32 by jnho              #+#    #+#             */
/*   Updated: 2022/09/01 12:06:16 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_addr(char *add)
{
	unsigned long long	address;
	char				ptr_num[100];
	int					idx;
	int					prt_zero;

	address = (unsigned long long) add;
	idx = 0;
	while (address)
	{
		if (address % 16 >= 10)
			ptr_num[idx] = address % 16 - 10 + 'a';
		else
			ptr_num[idx] = address % 16 + '0';
		address /= 16;
		idx++;
	}
	prt_zero = 0;
	while (prt_zero++ < 16 - idx)
		write(1, "0", 1);
	while (idx--)
		write(1, &ptr_num[idx], 1);
	write(1, ": ", 2);
}

void	ft_print_zero(int idx)
{
	while (idx < 16)
	{
		write(1, "  ", 2);
		if (idx % 2 == 1)
			write(1, " ", 1);
		idx++;
	}
}

void	ft_print_hexadecimal(char *str, int idx_max)
{
	int	idx;
	int	hex;
	int	digit;

	idx = 0;
	while (idx < idx_max)
	{
		if (str[idx] / 16 < 10)
			hex = str[idx] / 16 + '0';
		else
			hex = str[idx] / 16 - 10 + 'a';
		if (str[idx] % 16 < 10)
			digit = str[idx] % 16 + '0';
		else
			digit = str[idx] % 16 - 10 + 'a';
		write(1, &hex, 1);
		write(1, &digit, 1);
		if (idx % 2 == 1)
			write(1, " ", 1);
		idx++;
	}
	ft_print_zero(idx);
}

void	ft_print_printable(char *str, int idx_max)
{
	int	idx;

	idx = 0;
	while (idx < idx_max)
	{
		if ((32 <= str[idx]) && (str[idx] <= 126))
			write(1, &str[idx], 1);
		else
			write(1, ".", 1);
		idx++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*addr_prt;
	int		idx;

	addr_prt = (char *)addr;
	idx = 0;
	while (idx < (int)size)
	{
		if ((int)size - idx < 16)
		{
			ft_print_addr(&addr_prt[idx]);
			ft_print_hexadecimal(&addr_prt[idx], (int)size - idx);
			ft_print_printable(&addr_prt[idx], (int)size - idx);
		}
		else
		{
			ft_print_addr(&addr_prt[idx]);
			ft_print_hexadecimal(&addr_prt[idx], 16);
			ft_print_printable(&addr_prt[idx], 16);
		}
		idx += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
